#include "ThreadPool.h"

#include <iostream>

ThreadPool::ThreadPool(unsigned nbOfThreads, Solver& solver)
{
    this->fo = this->exitSignal.get_future();

    this->nbOfThreads = nbOfThreads;

    for(int i = 0 ; i < nbOfThreads ; ++i)
        this->solvers.push_back(solver);

    auto cur = solver.getCurrentBoard();

    // je remplis la stack de candidats où la première pièce est placée
    for(int i = 0 ; i < cur->tiles->size() ; ++i)
    {
        std::shared_ptr<Board> child = std::make_shared<Board>(*cur);
        child->grid[i] = (*child->tiles)[child->tileToPlace];
        child->tileToPlace++;
        this->stack.push(child);
    }

    // on créé un thread pool avec n threads
    for(int i = 1 ; i <= nbOfThreads ; ++i)
    {
        this->threads.push_back(std::thread(
            &ThreadPool::execute,
            this
            // std::ref(this->fo)
        ));
    }

    for(auto& t : this->threads)
        t.join();
}

// void ThreadPool::execute(std::future<void>& fo)
void ThreadPool::execute()
{
    // je récupère le prochain job à executer de la pile
    this->mut_stack.lock();
    auto board = this->stack.top();
    this->stack.pop();
    this->mut_stack.unlock();

    // on reserve un solver
    int i = -1;
    bool locked = false;
    do
    {
        ++i;
        locked = this->mut_solvers[i % this->nbOfThreads].try_lock();   
    } while(!locked);
    auto& solver = this->solvers[i % this->nbOfThreads];

    // on nettoie la stack du solveur avant de lancer le solve
    solver.cleanStack();

    // on lance la résolution, si résultat trouvé..
    // if(solver.solve(board, fo))
    if(solver.solve(board, this->fo))
    {
        // on affiche la solution
        std::cout<<"Solution found :"<<std::endl;
        solver.printBoard();

        // on libère le solver
        this->mut_solvers[i % this->nbOfThreads].unlock();

        // on stop tous les threads
        this->exitSignal.set_value();
    }

}