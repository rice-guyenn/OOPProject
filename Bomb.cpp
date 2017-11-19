#include "stdafx.h"
#include "Bomb.h"

Bomb::Bomb(int x, int y): Cell(x, y){
	bomb = true;
}

Bomb::~Bomb(){

}

void Bomb::reveal(){
    // You lose
}
