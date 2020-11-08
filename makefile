CC=g++
# CFLAGS=--std=c++11
SRC=src/Board.cpp src/Solver.cpp src/main.cpp
OBJ=obj/Board.o obj/Solver.o obj/main.o
EXEC=bin/tetravex-solver
DIRS=bin obj

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $^ -o $@

obj/Board.o: src/Board.cpp src/Board.h
	$(CC) -c src/Board.cpp -o obj/Board.o

obj/Solver.o: src/Solver.cpp src/Solver.h
	$(CC) -c src/Solver.cpp -o obj/Solver.o

obj/main.o: src/main.cpp
	$(CC) -c src/main.cpp -o obj/main.o

clean:
	rm -rf $(OBJ)

mrproper:
	rm -rf $(DIRS)

# will create all necessary directories after the Makefile is parsed
$(shell mkdir -p $(DIRS))