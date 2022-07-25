#include <iostream>
#include <unordered_set>
#include <string>
#include <chrono>
#include "ConveyGoF.hpp"
#include "LifUtil.hpp"

int main(int argc, char** argv) 
{
    if (argc < 2)
    {
        std::cout << "Input format:\n Convey `Life 1.06 Format file` [`iterate count`]" << std::endl;
        return -1;
    }

    string filename = string(argv[1]);
    int iterateCount = 10;
    if (argc >= 3)
    {
        try
        {
            iterateCount = stoi(string(argv[2]));
        }
        catch(...)
        {
            iterateCount = 10;
        }
    }

    CellSet board;
    if (!LifUtil::LoadFile(filename, board))
    {
        return -1;
    }

    ConveyGoF gof;
    gof.initCells(board);

    auto start = chrono::system_clock::now();
    for (int i = 0; i < iterateCount; ++i) {
        gof.proceed(5);
    }
    chrono::duration<double> elapsed = chrono::system_clock::now() - start;
    std::cout << elapsed.count() << std::endl;

    gof.printCells(std::cout);
    
    return 0;
}
