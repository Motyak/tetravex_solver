#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include "Solver.h"

#include <memory>
#include <vector>
#include <stack>
#include <thread>
#include <mutex>
#include <future>



class ThreadPool
{
    unsigned nbOfThreads;

    std::vector<Solver> solvers;
    std::vector<std::thread> threads;
    std::stack<std::shared_ptr<Board>> stack;

    std::vector<std::mutex> mut_solvers;
    std::mutex mut_stack;

    std::promise<void> exitSignal;
    std::future<void> fo;

  public:
    ThreadPool(unsigned nbOfThreads, Solver& solver);
    void execute();
};
#endif