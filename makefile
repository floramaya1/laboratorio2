CC = gcc
CFLAGS = -I inc -Wall

SRC_DIR = src
OBJ_DIR = build/obj
BIN_DIR = build/bin
DOC_DIR = build/doc

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

all: $(BIN_DIR)/programa

$(BIN_DIR)/programa: $(OBJ_FILES)
	mkdir -p $(BIN_DIR)
	$(CC) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

doc:
	mkdir -p $(DOC_DIR)
	doxygen Doxyfile

clean:
	rm -rf build