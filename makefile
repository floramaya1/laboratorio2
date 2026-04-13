SRC_DIR = ./src
OBJ_DIR = ./build
INC_DIR = ./inc
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

all: $(OBJ_FILES)
	gcc -o $(OBJ_DIR)/programa $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -c $< -o $@ -I $(INC_DIR)

doc:
	mkdir -p $(OBJ_DIR)/doc
	doxygen Doxyfile

clean:
	rm -rf build