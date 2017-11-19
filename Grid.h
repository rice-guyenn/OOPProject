#ifndef GRID_H
#define GRID_H
#include "Cell.h"
#include "Bomb.h"
#include "NoBombCell.h"
#include <vector>

using namespace std;
class Grid {
	protected:
		int width;
		int height;
		std::vector<std::vector<Cell *> > cells;
		//Cell *cells[][];
	public:
		Grid(int w, int h);
		Grid(int w, int h, int bombCount);
		~Grid();
		int getBombs(int x, int y);
		int addCell(Cell *c);
		int addBomb(Bomb *c);
		int addNoBomb(NoBombCell *cell);
		void toString();
};

#endif

