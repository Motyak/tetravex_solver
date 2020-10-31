#include "Board.h"
// #include "Solver.h"

#include <vector>

// g++ -o bin/main src/Board.cpp src/main.cpp
int main()
{
    // Création des données
    std::vector<Board::Tile> tiles;
    for(unsigned i = 1 ; i <= 4 ; ++i)
        tiles.push_back({ { i, i+1, i+3, i+5 } });

    // Création d'un Board à partir des données
    Board board(tiles);
    board.print();

    // // Déplacement de tiles dans la grid
    // board.addTileToGrid(0, 0);
    // board.addTileToGrid(1, 3);
    // board.print();




    // Solver solver("filename");
    
    // std::cout<<solver.solve()<<std::endl;

    return 0;
}