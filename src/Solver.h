#ifndef SOLVER_H
#define SOLVER_H

#include "Board.h"

#include <stack>
#include <iostream>

extern unsigned nbOfInstances;

class Solver
{
    unsigned width, height;
    Board* currentBoard;
    std::stack<Board*> stack;

  public:
  	Solver(const std::string& instanceFileName);
    ~Solver();
    bool solve();
	void printBoard(Board* board = nullptr);

  private:
	bool boardIsSolved();
	bool tileCanBePlaced(const unsigned& tileIndex, const unsigned& gridIndex);
};
#endif