#ifndef SOLVER_H
#define SOLVER_H

#include "Board.h"

#include <stack>

class Solver
{
    unsigned width, height;
    Board* currentBoard;
    std::stack<Board*> stack;

  public:
  	Solver(const std::string& instanceFileName);
    ~Solver();
    bool solve();
	void printBoard();
	bool boardIsSolved();

  private:
	// bool boardIsSolved();
	bool tileCanBePlaced(const unsigned& tileIndex, const unsigned& gridIndex);
};
#endif