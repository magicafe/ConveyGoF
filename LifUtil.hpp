#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include "Cell.hpp"

using namespace std;

class LifUtil
{
public:
    static bool LoadFile(string &filename, CellSet &board)
    {
        ifstream lif(filename);
        if (!lif.is_open())
        {
            cerr << "Open life 1.06 file " << filename << " failed." << std::endl;
            return false;
        } 
        // read header
        string header;
        getline(lif, header);
        if (!header.starts_with("#Life 1.06"))
        {
            cerr << "Invalid Life 1.06 file." << std::endl;
            return false;
        }
        // read in cells
        coord_type x, y;
        while (lif >> x >> y)
        {
            board.insert(Cell{x, y});
        }
        return true;
    }
};

