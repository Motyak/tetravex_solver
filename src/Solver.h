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

    // based on currentBoard, which will be pushed on stack afterwards
    Board* generateChild();
    //just do this->stack.top();
    Board* getParent();

  public:
    //solve the problem and return the first solution found
    Board* solve();
};
#endif