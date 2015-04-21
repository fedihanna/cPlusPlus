#ifndef _Ant_H
#define _Ant_H
#include "Organism.h" //includes organisim

class Ant : public Organism
{
public:
	Ant();
	void move(World *world, int x, int y);
	bool hasMoved(Direction direction, World *world, int x, int y);//adding direction to make ant AI
};
#endif
