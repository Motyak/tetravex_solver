#include "Board.h"
#include "Solver.h"

#include <iostream>

// g++ -o bin/main src/Board.cpp src/Solver.cpp src/main.cpp
int main()
{
    Solver solver("examples/2x2.txt");

    // if(solver.solve())
    if(solver.solveV2(solver.getCurrentBoard()))
    {
        std::cout<<"Solution found :"<<std::endl;
        solver.printBoard();
    }
    else
        std::cout<<"No solution found"<<std::endl;

    return 0;
}
