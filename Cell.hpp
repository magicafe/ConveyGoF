#pragma once

#include <algorithm>
#include <string>
#include "CoordType.hpp"

using namespace std;

struct Cell
{
    coord_type x;
    coord_type y;
    string id;

    Cell(coord_type ix, coord_type iy) : x(ix), y(iy)
    {
#ifdef BIG_INT
        id = x.to_string() + y.to_string();
#else
        id = to_string(x) + to_string(y);
#endif
    }

    bool operator<(const Cell &other) const
    {
        return x < other.x || (x == other.x && y < other.y);
    }
};

class CellHasher
{
public:
    size_t operator()(const Cell &cell) const
    {
        return hasher(cell.id);
    }

private:
    hash<string> hasher;
};

class CellEqual
{
public:
    bool operator()(const Cell &lhs, const Cell &rhs) const
    {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
};

typedef unordered_set<Cell, CellHasher, CellEqual> CellSet;