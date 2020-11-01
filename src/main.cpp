#include "Board.h"
// #include "Solver.h"

#include <vector>
#include <iostream>

// g++ -o bin/main src/Board.cpp src/main.cpp
int main()
{
    // Création des données
    std::vector<Board::Tile> tiles = { 
        { { 2, 3, 7, 7 } },
        { { 7, 4, 9, 7 } },
        { { 8, 9, 9, 4 } },
        { { 9, 8, 8, 3 } }
    };

    // Création d'un Board à partir des données
    try {
        Board board(tiles);
        board.print();
        board.addTileToGrid(3, 3);
        board.print();

        // // Déplacement de tiles dans la grid
        // board.addTileToGrid(0, 0);
        // board.addTileToGrid(1, 3);
        // board.print();
    } 
    catch(std::string msg) {
        std::cout<<"Erreur : "<<msg<<std::endl;
    }
    

    // Solver solver("filename");
    
    // std::cout<<solver.solve()<<std::endl;

    return 0;
}