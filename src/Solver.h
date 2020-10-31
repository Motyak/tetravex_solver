#ifndef SOLVER_H
#define SOLVER_H

#include "Board.h"

#include <stack>

class Solver
{
    Board* currentBoard;
    std::stack<Board*> stack;

    Solver(std::string instanceFileName);
    ~Solver();

    Board* generateChild();
    Board* getParent();

  public:
    Board* solve();
};
#endif