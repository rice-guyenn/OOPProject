#include "Grid.h"


Grid::Grid(int w, int h){
	width = w;
	height = h;
}

/*
* returns the number of bombs in adjacent 8 cells
* if cell (x,y) is bomb returns -1
*/
int Grid::getBombs(int x, int y){
	int bombs = 0;
	if(!cells.at(x).at(y).isBomb()){
		for(int i=-1;i<2;i++){
			for(int k=-1;k<2;k++){
				if(cells.at(x+i).at(y+k).isBomb()){
					bombs++;
				}
			}
		}
		return bombs;	
	}
	return -1;
}

int Grid::addCell(Cell cell){
	int x = cell.getX();
	int y = cell.getY();
	cells[x][y] = cell;
}