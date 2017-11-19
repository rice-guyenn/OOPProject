#ifndef NOBOMBCELL_H_INCLUDED
#define NOBOMBCELL_H_INCLUDED

#include <vector>
#include "Cell.h"

class NoBombCell : public Cell{
    protected:
        std::vector<Cell *> adjacentCells;
    public:
        NoBombCell(int x, int y);
        void addAdjacency(Cell *cell);
		void reveal();
};

#endif // NOBOMBCELL_H_INCLUDED
