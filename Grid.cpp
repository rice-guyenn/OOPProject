#include <random>
#include <iostream>
#include "stdafx.h"
#include "Grid.h"

Grid::Grid(int w, int h){
	width = w;
	height = h;

	for(int i = 0; i < h; i++){
        std::vector<Cell *> rows;
        for(int j = 0; j < w; j++){
            Cell *nullPtr = NULL;
            rows.push_back(nullPtr);
        }
        cells.push_back(rows);
    }
}

Grid::Grid(int w, int h, int bombCount){
    std::random_device r;
    std::mt19937 rng(r());
    std::uniform_int_distribution<int> xRand(0, w - 1);
    std::uniform_int_distribution<int> yRand(0, h - 1);

    width = w;
	height = h;

	for(int i = 0; i < h; i++){
        std::vector<Cell *> rows;
        for(int j = 0; j < w; j++){
            Cell *nullPtr = NULL;
            rows.push_back(nullPtr);
        }
        cells.push_back(rows);
    }

	while(bombCount > 0){
        int x = xRand(rng);
        int y = yRand(rng);
        if(cells[x][y] == NULL){
            Bomb *b = new Bomb(x, y);
            addBomb(b);
            bombCount--;
            //toString();
        }
	}

	toString();

    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            int numBombs = getBombs(i, j);
            if(numBombs == 0){
                NoBombCell *cell = new NoBombCell(i, j);
                addNoBomb(cell);

                for(int a = -1; a < 2; a++){
                    for(int b = -1; b < 2; b++){
                        try{
                            cell->addAdjacency(cells.at(a + i).at(b + j));
                        }
                        catch(...){}
                    }
                }
            }
            else if(numBombs > 0){
                Cell *cell = new Cell(i, j);
                addCell(cell);
            }
        }
	}

}

/*
* returns the number of bombs in adjacent 8 cells
* if cell (x,y) is bomb returns -1
*/
int Grid::getBombs(int x, int y){
	int bombs = 0;

	if(cells.at(x).at(y) != NULL){
        if(cells.at(x).at(y)->isBomb()){
            return -1;
        }
	}

	for(int i = -1; i < 2; i++){
        for(int k = -1; k < 2; k++){
            if(cells.at(x).at(y) != NULL){
                cells.at(x).at(y)->isBomb();
            }

            try{
                if((x + i) >= 0 && (x + i) < cells.size() && (y + k) >= 0 && (y + k) < cells[0].size()){
                    if(cells.at(x + i).at(y + k) != NULL){
                        if(cells.at(x + i).at(y + k)->isBomb()){
                            bombs++;
                        }
                    }
                }
            }
            catch(...){}
        }
    }
    return bombs;
}

int Grid::addCell(Cell *cell){
	int x = cell->getX();
	int y = cell->getY();
	cells[x][y] = cell;
	return 1;
}

int Grid::addBomb(Bomb *cell){
    int x = cell->getX();
	int y = cell->getY();
	std::cout << "Adding bomb at (" << x << ", " << y << ")";
	cells[x][y] = cell;
	std::cout << " var check: " << cells[x][y]->isBomb() << endl;
	return 1;
}

int Grid::addNoBomb(NoBombCell *cell){
	int x = cell->getX();
	int y = cell->getY();
	cells[x][y] = cell;
	return 1;
}



void Grid::toString(){
    std::cout << "(0, 2) var check: " << cells[0][2]->isBomb() << endl << endl;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(cells[i][j] == NULL){
                std::cout << "N";
            }
            else if(cells[i][j]->isBomb()){
                std::cout << "*";
            }
            else if(getBombs(i, j) >= 0){
                std::cout << getBombs(i, j);
            }
            else{
                std::cout << "*";
            }
        }
        std::cout << "\n";
    }
}
