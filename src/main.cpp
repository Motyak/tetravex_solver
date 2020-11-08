#include "Board.h"
#include "Solver.h"

#include <vector>
#include <iostream>

// g++ -o bin/main src/Board.cpp src/Solver.cpp src/main.cpp
int main()
{
    Solver solver("examples/2x2.txt");


    if(solver.solve())
    {
        std::cout<<"Solution found :"<<std::endl;
        solver.printBoard();
        std::cout<<""<<std::endl;//gdb debug
    }
        
    else
        std::cout<<"Aucune solution trouvée"<<std::endl;

    return 0;
}