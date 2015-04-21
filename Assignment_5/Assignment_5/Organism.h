#ifndef _Organism_H
#define _Organism_H
using namespace std;

class World;

//numerated types
//user-defined type that consists of the organisms or neither
enum Type { LION, ANT, NEITHER };
//numerated directions
//user-defined type that consists of the directions
enum Direction { LEFT, UP, RIGHT, DOWN, UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT };

class Organism
{
	//only the class of organisim can access it
protected:
	World *world;

public:
	Type type;
	bool moved;
	Organism();
	int starveCounter;
	int breedCounter;
	void move(World *world, int x, int y);
};

#endif
