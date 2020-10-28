#include "Solver.h"

int main()
{
    Solver solver("filename");
    
    std::cout<<solver.solve()<<std::endl;

    return 0;
}