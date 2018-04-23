SRC = ./src
BIN = ./bin
OBJ = ./obj
INC = ./include

CC = g++
CFLAGS = -g -std=c++14

MKDIR_IF_NEEDED = mkdir -p $(@D)

all:	$(BIN)/main.out

test:	$(BIN)/main.out
	@echo "\033[1;33mCreating tests directory...\033[0m"
	@echo "\n\033[1;33mHelp:\033[0m"
	@mkdir -p ./tests/
	@mkdir -p ./tests/maps/
	@echo "\033[1;36m$$ $(BIN)/main.out\033[0m"
	@$(BIN)/main.out
	@echo "\n\033[1;33mGenerate Streak Files:\033[0m"
	@echo "\033[1;36m$$ $(BIN)/main.out --enumerate ./test_dir/ ./tests/files.data\033[0m"
	@$(BIN)/main.out --enumerate ./test_dir/ ./tests/files.data
	@echo "\n\033[1;36m$$ $(BIN)/main.out --make_maps ./tests/files.data ./tests/maps/\033[0m"
	@$(BIN)/main.out --make_maps ./tests/files.data ./tests/maps/
	@echo "\n\033[1;33mExample Query:\033[0m"
	@echo "\033[1;36m$$ $(BIN)/main.out --query ./test_dir/f1 ./tests/maps/\033[0m"
	@$(BIN)/main.out --query ./test_dir/f1 ./tests/maps/
	@echo "\n\033[1;33mRemoving tests directory...\033[0m"
	@rm -rf ./tests/

$(BIN)/main.out:	$(SRC)/main.cc $(OBJ)/enumerator.o $(OBJ)/streak.o
	$(MKDIR_IF_NEEDED)
	$(CC) $(CFLAGS) -o $@ $^ -lstdc++fs
	@echo ""

$(OBJ)/enumerator.o:	$(SRC)/enumerator.cc $(INC)/enumerator.hh
	@echo "\033[1;33mCompiling...\033[0m"
	$(MKDIR_IF_NEEDED)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ)/streak.o:	$(SRC)/streak.cc $(INC)/streak.hh
	$(MKDIR_IF_NEEDED)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)/
	rm -rf $(BIN)/
