#ifndef _Lion_H
#define _Lion_H
#include "Organism.h" //includes organisim

class Lion : public Organism
{
public:
	Lion();
	void move(World *world, int x, int y);
	bool hasMoved(Direction direction, World *world, int x, int y); //added direction to make lion AI
};
#endif
