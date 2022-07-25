#pragma once

#include "CoordType.hpp"

struct Cell
{
    coord_type x;
    coord_type y;

    bool operator<(const Cell &other) const
    {
        return x < other.x || (x == other.x && y < other.y);
    }
};