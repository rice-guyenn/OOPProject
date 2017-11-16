#include "stdafx.h"
#include "Bomb.h"

Bomb::Bomb(int x, int y): Cell(x, y){
	bomb = true;
	flagged = false;
	interested = false;
}

Bomb::~Bomb(){

}