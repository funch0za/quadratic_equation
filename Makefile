CC := gcc

NAME := quadratic_equation

SRCDIR := ./src
BUILDDIR := ./build
BINDIR := ./bin
LIBDIR := ./lib
TSTDIR := ./test
LOGDIR := $(TSTDIR)/logs

SRC := $(SRCDIR)/$(NAME).c
TST := $(TSTDIR)/test_$(NAME).c

OBJECT := $(BUILDDIR)/$(NAME).o
OBJECT_TST := $(BUILDDIR)/test_$(NAME).o

TARGET := $(LIBDIR)/lib$(NAME).so

TESTER := $(BINDIR)/test_$(NAME)

CFLAGS := -std=c11 -Wall -Werror -Wextra
LFLAGS := -lm
LFLAGS_TST := -lcheck

RM := rm

all: clean $(TARGET)

$(TARGET): $(OBJECT)
	@echo "Linking library..."
	$(CC) -shared $(OBJECT) $(CFLAGS) $(LFLAGS) -o $(TARGET)

$(OBJECT): $(SRC)
	@echo "Building library..."
	$(CC) -c -fPIC $(SRC) -o $(OBJECT)

$(OBJECT_TST): $(TST) $(TARGET)
	@echo "Building test..."
	$(CC) -c $(TST) -o $(OBJECT_TST)

check: $(TARGET) $(OBJECT_TST)
	@echo "Check..."
	$(CC) $(LFLAGS_TST) $(CFLAGS) $(OBJECT_TST) -L. $(TARGET) -Wl,-rpath,. -o $(TESTER)
	$(TESTER)

clean:
	@echo "Cleaning..."
	$(RM) -f $(BINDIR)/* $(BUILDDIR)/* $(LOGDIR)/* $(TARGET)