#ifndef SOLVER_H
#define SOLVER_H

#include "Board.h"

#include <stack>
#include <future>

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
	bool solve(std::future<void>& fo);
    bool solve(std::shared_ptr<Board>& board, std::future<void>& fo);
	void printBoard();
  	void printBoard(Board* board);
	void cleanStack();

	std::shared_ptr<Board> getCurrentBoard();
};
#endif