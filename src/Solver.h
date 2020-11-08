#ifndef SOLVER_H
#define SOLVER_H

#include "Board.h"

#include <stack>

extern unsigned nbOfInstances;

class Solver
{
	/*constants, et communs à tous les boards générés*/
    unsigned width, height;
	std::vector<std::shared_ptr<Tile>> tiles;
	/*-----------------------------------------------*/

    std::shared_ptr<Board> currentBoard;
    std::stack<std::shared_ptr<Board>> stack;

  public:
  	Solver(const std::string& instanceFileName);
    // bool solve();
    bool solveV2(std::shared_ptr<Board> cur);
  	void printBoard(Board* board = nullptr);
    std::shared_ptr<Board> getCurrentBoard();
};
#endif