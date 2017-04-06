CC = gcc
CFLAGS = -Wall -Werror
TEST_FLAGS = -I src -I thirdparty -Wall -Werror

EXECUTABLE = bin/prog
TEST_EXEC = bin/test

TEST_OBJ_DIR = build/test
SRC_BUILD_DIR = build/src

.PHONY: all clean test

all: $(SRC_BUILD_DIR)/main.o $(SRC_BUILD_DIR)/deposit.o
	$(CC) $(SRC_BUILD_DIR)/main.o $(SRC_BUILD_DIR)/deposit.o -o $(EXECUTABLE)

$(SRC_BUILD_DIR)/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o $(SRC_BUILD_DIR)/main.o

$(SRC_BUILD_DIR)/deposit.o: src/deposit.c
	$(CC) $(CFLAGS) -c src/deposit.c -o $(SRC_BUILD_DIR)/deposit.o

all: deposit-calc-test

deposit-calc-test: $(TEST_OBJ_DIR)/main.o $(TEST_OBJ_DIR)/deposit_test.o $(TEST_OBJ_DIR)/validation_test.o $(SRC_BUILD_DIR)/deposit.o
	$(CC) $(TEST_OBJ_DIR)/main.o $(TEST_OBJ_DIR)/deposit_test.o $(TEST_OBJ_DIR)/validation_test.o $(SRC_BUILD_DIR)/deposit.o -o $(TEST_EXEC)

$(TEST_OBJ_DIR)/main.o: test/main.c
	$(CC) $(TEST_FLAGS) -c test/main.c -o $(TEST_OBJ_DIR)/main.o

$(TEST_OBJ_DIR)/deposit_test.o: test/deposit_test.c
	$(CC) $(TEST_FLAGS) -c test/deposit_test.c -o $(TEST_OBJ_DIR)/deposit_test.o

$(TEST_OBJ_DIR)/validation_test.o: test/validation_test.c
	$(CC) $(TEST_FLAGS) -c test/validation_test.c -o $(TEST_OBJ_DIR)/validation_test.o


.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o *.exe

