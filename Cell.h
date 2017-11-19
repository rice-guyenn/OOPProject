#ifndef CELL_H
#define CELL_H

using namespace std;
class Cell {
	protected:
		int xCoord; //x coord in grid
		int yCoord; //y coord in grid
		bool bomb; //cell is bomb
		bool flagged; //cell is flagged as bomb
		bool interested; //interested flag -- question mark
		int numBombs; //adjacent bomb cells
		bool revealed;
	public:
		Cell(int x, int y);
		~Cell();
		int getX();
		int getY();
		bool isBomb();
		bool isFlagged();
		bool isInterested();
		void reveal();
};

#endif

