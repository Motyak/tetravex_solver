#include "Board.h"
#include "Solver.h"

#include <vector>
#include <iostream>

// g++ -o bin/main src/Board.cpp src/Solver.cpp src/main.cpp
int main()
{
    Solver solver("examples/2x2.txt");


    // std::vector<Tile*> grid = {new Tile({3, 7, 9, 7}), nullptr, nullptr, nullptr};
    // Solver solver("examples/2x2.txt");
    // solver.currentBoard->grid = grid;
    // solver.printBoard();
    // if(solver.tileCanBePlaced(3, 1))
    //     std::cout<<"tile can be placed in 1"<<std::endl;
    // if(solver.tileCanBePlaced(3, 2))
    //     std::cout<<"tile can be placed in 2"<<std::endl;
    // if(solver.tileCanBePlaced(3, 3))
    //     std::cout<<"tile can be placed in 3"<<std::endl;



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