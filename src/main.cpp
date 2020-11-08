#include "Board.h"
#include "Solver.h"

#include <iostream>

// g++ -o bin/main src/Board.cpp src/Solver.cpp src/main.cpp
int main()
{
    Solver solver("examples/4x4.txt");

    if(solver.solve())
    {
        std::cout<<"Solution found :"<<std::endl;
        solver.printBoard();
    }
    else
        std::cout<<"No solution found"<<std::endl;

    return 0;
}