#include <iostream>
#include "Grid.h"

using namespace std;

int main()
{
    Grid *grid = new Grid(5, 5, 3);

    grid->toString();

    return 0;
}
