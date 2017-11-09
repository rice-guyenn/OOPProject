#ifndef GRID_H
#define GRID_H
#include "Cell.h"
#include <vector>

using namespace std;
class Grid {
	protected:
		int width;
		int height;
		std::vector<std::vector<Cell> > cells;
	public:
		Grid(int w, int h);
		~Grid();
		int getBombs(int x, int y);
		int addCell(Cell c);
};

#endif

