CC := gcc

NAME := quadratic_equation

SRCDIR := ./src
SRC := $(SRCDIR)/*.c
TSTDIR := ./test
TST := $(TSTDIR)/*.c
BUILDDIR := ./build
OBJECT := $(BUILDDIR)/$(NAME).o
BINDIR := ./bin

TARGET := $(BUILDDIR)/$(NAME).a
TESTER := $(BINDIR)/test_$(NAME)

LOGDIR := $(TSTDIR)/logs

CFLAGS := -std=c11
LFLAGS := -lm
LFLAGS_TST := -lcheck

RM := rm
AR := ar
AR_FLAGS := rcs

all: clean $(TARGET)

$(TARGET): $(OBJECT)
	@echo "Linking..."
	$(AR) $(AR_FLAGS) $(TARGET) $(OBJECT)

$(OBJECT): $(SRC)
	@echo "Compiling..."
	$(CC) -c $(LFLAGS) $(CFLAGS) $(SRC) -o $(OBJECT)

check: $(TARGET)
	@echo "Check..."
	$(CC) $(LFLAGS_TST) $(LFLAGS) -o $(TESTER) $(TST) -L. $(TARGET)
	$(TESTER)

clean:
	@echo "Cleaning..."
	$(RM) -f $(BINDIR)/* $(BUILDDIR)/* $(LOGDIR)/*