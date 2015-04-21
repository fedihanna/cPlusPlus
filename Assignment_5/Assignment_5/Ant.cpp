#include "Ant.h"
#include "World.h"
#include <vector>
#include <algorithm>

Ant::Ant(){
	this->type = ANT; //refering to this TYPE organisim (ANT)
}

void Ant::move(World *world, int x, int y) 
{
	this->breedCounter++; //refering to this breed counter for(ANT)

	// The ant can move 4 directions. 
	// We add each direction to an array, and shuffle it.
	// This way the ant wont have a priority to move up, or left, etc...
	// every turn.
	//making a vector with specfic values for direction
	std::vector<Direction> directions;
	directions.push_back(LEFT);
	directions.push_back(RIGHT);
	directions.push_back(UP);
	directions.push_back(DOWN);
	std::random_shuffle(directions.begin(), directions.end()); //shuffle

	// We iterate over each direction in the shuffled array,
	// until the organism could move. Once it has moved,
	// we break out of the loop, and finish it's turn.
	for (Direction dir : directions){
		if (hasMoved(dir, world, x, y)){
			break;
		}
	}
}

// Here we check to see if the direction is availible (we called this above).
// If it is: we move, then return a true value to the method above. (finishing the turn)
bool Ant::hasMoved(Direction direction, World *world, int x, int y){
	if ((x - 1) >= 0 && 
		world->grid[x - 1][y].type != LION && 
		world->grid[x - 1][y].type != ANT &&
		direction == UP)
	{
		world->setMove(*this, x - 1, y, x, y);
		return true;
	}
	//GRID_HEIGHT grows from the right
	if ((x + 1) < GRID_HEIGHT && 
		world->grid[x + 1][y].type != LION && 
		world->grid[x + 1][y].type != ANT && 
		direction == DOWN)
	{
		world->setMove(*this, x + 1, y, x, y);
		return true;
	}
	if ((y - 1) >= 0 && 
		world->grid[x][y - 1].type != LION  &&
		world->grid[x][y - 1].type != ANT &&
		direction == LEFT)
	{
		world->setMove(*this, x, y - 1, x, y);
		return true;
	}
	//GRID_WIDTH grows from the right
	if ((y + 1) < GRID_WIDTH && 
		world->grid[x][y + 1].type != LION &&
		world->grid[x][y + 1].type != ANT &&
		direction == RIGHT)
	{
		world->setMove(*this, x, y + 1, x, y);
		return true;
	}

	// Can't move the direction.
	return false;
}