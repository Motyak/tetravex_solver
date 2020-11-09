#include "Board.h"
#include "Solver.h"
#include "ThreadPool.h"

#include <iostream>

// g++ -o bin/main src/Board.cpp src/Solver.cpp src/ThreadPool.cpp src/main.cpp --std=c++11 -pthread
int main()
{
    Solver solver("examples/2x2.txt");
    ThreadPool tp(2, solver);

    return 0;
}
