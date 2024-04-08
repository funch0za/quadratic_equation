CC=gcc
LIB_FLAGS= -lm
CHECK_FLAGS = -lcheck

SOURCE=src/quadratic_equation.c
TESTS=tests/test_quadratic_equation.c
BUILD_DIR=build
OUT=test_quadratic_equation

check:
	$(CC) $(LIB_FLAGS) $(CHECK_FLAGS) $(SOURCE) $(TESTS) -o $(BUILD_DIR)/$(OUT)

run:
	gcc -lm $(SOURCE) scripts/run.c -o $(BUILD_DIR)/$(OUT)

clean:
	rm $(BUILD_DIR)/*