#ifndef BOMB_H
#define BOMB_H
#include "Cell.h"

using namespace std;
class Bomb : public Cell {
	public:
		Bomb(int x, int y);
		~Bomb();
};

#endif

