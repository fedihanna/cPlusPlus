#include "Organism.h"
#include "World.h"
#include <iostream>

Organism::Organism(){

}

void Organism::move(World *world, int x, int y){
	this->moved = true;
	// At this point we don't know whether this organism is 
	// an ant, or lion. So we call upon the World class
	// to DOWNCAST this object - World.cpp (Line 62) 
	world->move(this,  x, y);
}