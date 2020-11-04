#ifndef SOLVER_H
#define SOLVER_H

#include "Board.h"

#include <stack>

class Solver
{
    Board* currentBoard;
    std::stack<Board*> stack;

  public:
  	Solver(const std::string& instanceFileName);
    ~Solver();
    Board* solve();
	void printBoard();

  private:
	bool boardIsSolved();
	bool tileCanBePlaced(const Tile& t, unsigned i);
};
#endif