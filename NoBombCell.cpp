#include "stdafx.h"
#include "NoBombCell.h"

NoBombCell::NoBombCell(int x, int y): Cell(x, y){

}

void NoBombCell::addAdjacency(Cell *cell){
    adjacentCells.push_back(cell);
}

void NoBombCell::reveal(){
    if(revealed){
        return;
    }
    revealed = true;
    for(int i = 0; i < adjacentCells.size(); i++){
        adjacentCells.at(i)->reveal();
    }
}
