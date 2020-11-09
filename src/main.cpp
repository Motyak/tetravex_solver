#include "Board.h"
#include "Solver.h"

#include <iostream>

// g++ -o bin/main src/Board.cpp src/Solver.cpp src/main.cpp
int main(int argc, char* argv[])
{
    std::string filename = "examples/4x4.txt";
    if(argc > 1)
        filename = std::string(argv[1]);

    Solver solver(filename);

    if(solver.solve())
    {
        std::cout<<"Solution found :"<<std::endl;
        solver.printBoard();
    }
    else
        std::cout<<"No solution found"<<std::endl;

    return 0;
}
