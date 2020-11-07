#ifndef SOLVER_H
#define SOLVER_H

#include "Board.h"

#include <stack>

extern unsigned nbOfInstances;

class Solver
{
    unsigned width, height;
    std::shared_ptr<Board> currentBoard;
    std::stack<std::shared_ptr<Board>> stack;

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