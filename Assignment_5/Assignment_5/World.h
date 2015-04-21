#ifndef _WORLD_H
#define _WORLD_H
#include "Lion.h"
#include "Ant.h"
#include <iostream>
using namespace std;

class Organism;

const int GRID_WIDTH = 20;
const int GRID_HEIGHT = 20;
const int START_LION_AMOUNT = 5;
const int START_ANT_AMOUNT = 100;

class World
{
public:
	int ants, lions;

	Organism *grid[GRID_HEIGHT];
	World();
	void printWorld();
	void move(Organism *organism, int x, int y);
	void setMove(Organism organism, int x, int y, int oldX, int oldY); //oldX and oldY so organisms don't duplicate
	
};
#endif