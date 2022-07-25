#pragma once

#include <iostream>
#include <vector>
#include <set>
#include "Cell.hpp"

using namespace std;

class ConveyGoF
{
protected:
    set<Cell> liveCells;
    Cell deadCells[8];

    inline void addCell(coord_type x, coord_type y)
    {
        auto cell = Cell{x, y};
        liveCells.insert(cell);
    }

public:
    void initCells(set<Cell> &board)
    {
        liveCells = move(board);
    }

    void proceed()
    {
        set<Cell> nextLiveCells;

        for (const auto &cell: liveCells)
        {
            // dead cell around live cell may change its state duration the iteration
            int64_t deadCellCount = getDeadCells(cell, deadCells);

            // if there are 2 or 3 live cells around current live cell, the cell stay live
            int64_t liveAround = 8 - deadCellCount;
            if (liveAround == 2 || liveAround == 3)
            {
                nextLiveCells.insert(cell);
            }

            // check dead cell around current live cells, change its state if there are exactly 3 live cells around the dead cell
            for (int64_t i = 0; i < deadCellCount; ++i) {
                if (getLiveNeighborCount(deadCells[i]) == 3)
                {
                    nextLiveCells.insert(deadCells[i]);
                }
            }
        }

        liveCells = std::move(nextLiveCells);
    }

    void printCells(ostream &out)
    {
        out << "#Life 1.06\n";
        for (auto &cell : liveCells)
        {
            out << cell.x << " " << cell.y << "\n";
        }
        out << std::endl;
    }

protected:
    inline int64_t getDeadCells(const Cell &liveCell, Cell *aroundCells)
    {
        coord_type x = liveCell.x;
        coord_type y = liveCell.y;
        int64_t count = 0;
        /*  (-1, -1)  (-1, 0)  (-1, 1)
         *  (0, -1)   (0, 0)   (0, 1)
         *  (1, -1)   (1, 0)   (1, 1)
         */
        if (!liveCells.contains(Cell{x - 1, y - 1})) aroundCells[count++] = Cell{x - 1, y - 1};
        if (!liveCells.contains(Cell{x - 1, y})) aroundCells[count++] = Cell{x - 1, y};
        if (!liveCells.contains(Cell{x - 1, y + 1})) aroundCells[count++] = Cell{x - 1, y + 1};

        if (!liveCells.contains(Cell{x, y - 1})) aroundCells[count++] = Cell{x, y - 1};
        if (!liveCells.contains(Cell{x, y + 1})) aroundCells[count++] = Cell{x, y + 1};

        if (!liveCells.contains(Cell{x + 1, y - 1})) aroundCells[count++] = Cell{x + 1, y - 1};
        if (!liveCells.contains(Cell{x + 1, y})) aroundCells[count++] = Cell{x + 1, y};
        if (!liveCells.contains(Cell{x + 1, y + 1})) aroundCells[count++] = Cell{x + 1, y + 1};

        return count;
    }

    int64_t getLiveNeighborCount(const Cell& deadCell) const
    {
        coord_type x = deadCell.x;
        coord_type y = deadCell.y;
        int64_t count = 0;
        /*  (-1, -1)  (-1, 0)  (-1, 1)
         *  (0, -1)   (0, 0)   (0, 1)
         *  (1, -1)   (1, 0)   (1, 1)
         */
        if (liveCells.contains(Cell{x - 1, y - 1})) count++;
        if (liveCells.contains(Cell{x - 1, y})) count++;
        if (liveCells.contains(Cell{x - 1, y + 1})) count++;

        if (liveCells.contains(Cell{x, y - 1})) count++;
        if (liveCells.contains(Cell{x, y + 1})) count++;

        if (liveCells.contains(Cell{x + 1, y - 1})) count++;
        if (liveCells.contains(Cell{x + 1, y})) count++;
        if (liveCells.contains(Cell{x + 1, y + 1})) count++;

        return count;
    }
};
