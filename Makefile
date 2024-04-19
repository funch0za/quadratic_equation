CC := gcc

NAME := quadratic_equation

SRCDIR := ./src
SRC := $(SRCDIR)/$(NAME).c
TSTDIR := ./test
TST := $(TSTDIR)/test_$(NAME).c
BUILDDIR := ./build
OBJECT := $(BUILDDIR)/$(NAME).o
OBJECT_TST := $(BUILDDIR)/test_$(NAME).o
BINDIR := ./bin

LIBDIR := ./lib
TARGET := $(LIBDIR)/lib$(NAME).so

TESTER := $(BINDIR)/test_$(NAME)

LOGDIR := $(TSTDIR)/logs

CFLAGS := -std=c11
LFLAGS := -lm
LFLAGS_TST := -lcheck

RM := rm

all: clean $(TARGET)

$(TARGET): $(OBJECT)
	@echo "Linking library..."
	$(CC) -shared $(OBJECT) $(CFLAGS) $(LFLAGS) -o $(TARGET)

$(OBJECT): $(SRC)
	@echo "Compiling library..."
	$(CC) -c -fPIC $(SRC) -o $(OBJECT)

$(OBJECT_TST): $(TST) $(TARGET)
	@echo "Compiling test..."
	$(CC) -c $(TST) -o $(OBJECT_TST)

check: $(TARGET) $(OBJECT_TST)
	@echo "Check..."
	$(CC) $(LFLAGS_TST) $(CFLAGS) $(OBJECT_TST) -L. $(TARGET) -Wl,-rpath,. -o $(TESTER)
	$(TESTER)

clean:
	@echo "Cleaning..."
	$(RM) -f $(BINDIR)/* $(BUILDDIR)/* $(LOGDIR)/*