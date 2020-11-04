#include "Board.h"
#include "Solver.h"

#include <vector>
#include <iostream>

// g++ -o bin/main src/Board.cpp src/Solver.cpp src/main.cpp
int main()
{
    Solver solver("examples/5x5.txt");
    solver.printBoard();
    
    // std::cout<<solver.solve()<<std::endl;

    return 0;
}