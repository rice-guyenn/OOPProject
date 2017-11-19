#include "stdafx.h"
#include "Cell.h"

Cell::Cell(int x, int y){
	xCoord = x;
	yCoord = y;
	bomb = false;
	interested = false;
	flagged = false;
	revealed = false;
}

Cell::~Cell(){

}

bool Cell::isBomb(){
	return bomb;
}
bool Cell::isFlagged(){
	return flagged;
}
bool Cell::isInterested(){
	return interested;
}
int Cell::getX(){
	return xCoord;
}
int Cell::getY(){
	return yCoord;
}

void Cell::reveal(){
    if(flagged){
        // Do not reveal if flagged
        return;
    }
    // Do whatever has to be done to reveal it I guess.
}
