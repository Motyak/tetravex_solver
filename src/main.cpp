#include "Board.h"
#include "Solver.h"

#include <vector>
#include <iostream>

// g++ -o bin/main src/Board.cpp src/Solver.cpp src/main.cpp
int main()
{
    Solver solver("examples/2x2.txt");
    solver.solve();
    solver.printBoard();

    return 0;
}