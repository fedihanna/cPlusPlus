#include "Lion.h"
#include "World.h"
#include <vector>
#include <algorithm>

Lion::Lion(){
	this->type = LION;
}

void Lion::move(World *world, int x, int y)
{
	this->starveCounter++; //lions strave counter
	this->breedCounter++; // lions breed counter

	if (starveCounter > 8)//greater than 8....(every 8 turns they should double)
	{ 
		starveCounter = 0; //it starves
		type = NEITHER; //then becomes neither
	}

	// The lion can move 8 directions. 
	// We add each direcion to an array, and shuffle it.
	// This way the lion wont have a priority to move up, or left, etc...
	// every turn.
	// "push_back" adds a new element at the end of the vector, after its current last element. The content of val is copied (or moved) to the new element
	//making a vector with specfic values for direction
	std::vector<Direction> directions;
	directions.push_back(LEFT);
	directions.push_back(RIGHT);
	directions.push_back(UP);
	directions.push_back(DOWN);
	directions.push_back(UP_LEFT);
	directions.push_back(UP_RIGHT);
	directions.push_back(DOWN_LEFT);
	directions.push_back(DOWN_RIGHT);
	std::random_shuffle(directions.begin(), directions.end()); //shuffle
	
	// We iterate over each direction in the shuffled array,
	// until the organism could move. Once it has moved,
	// we break out of the loop, and finish it's turn.
	for (Direction dir : directions)
	{
		if (hasMoved(dir, world, x, y))
		{
			break;
		}
	}
}

// Here we check to see if the direction is availible (we called this above).
// If it is: we move, then return a true value to the method above. (finishing the turn)
bool Lion::hasMoved(Direction direction, World *world, int x, int y){

	// Each organism has x and y coordinates on the grid. 
	// We check to see that adding one, or subtracting one to these coordinates
	// (intending to move the organism) will result in a coordinate on the grid.
	// For example: Moving an organism at 0,2 to -1,2 is not possible,
	// because -1,2 is not a location on the grid (all locations are positive numbers)

	// LION SPECIFIC DETAILS: The Lion will also check for another Lion at 
	// the tried location, as to not overwrite another Lion. However, the
	// Lion WILL overwrite and Ant (Eat it).

	// This part (Below) checks if the move will land on the grid. ((x - 1) >= 0) 
	// Remember arrays are 0-based, and 0 is a valid location
	// if its not a lion it can eat
	
//*********MOVING UP

                                                  //if organisim moves up and its not a lion, eat it 
	if ((x - 1) >= 0 && world->grid[x - 1][y].type != LION && direction == UP)
	{
		// If there's and Ant at this location, the starve counter (Needs to equal > 3 to starve)
		// Will reset (Because the Lion is about to eat it).
		// if the lion moves in the up direction an there is an ant there, it will eat the ant and then the starve counter goes to zero again 

		                //2D array [x-1][y]
		if (world->grid[x - 1][y].type == ANT)
		{
			starveCounter = 0; //starve counter is reset to zero
		}
		//so if it can do the above...do it, return true
		world->setMove(*this, x - 1, y, x, y); //x,y at end is old coordinate
		return true;
	}

//*************MOVING DOWN
	if ((x + 1) < GRID_HEIGHT && world->grid[x + 1][y].type != LION && direction == DOWN)
	{

		if (world->grid[x + 1][y].type == ANT)
		{
			starveCounter = 0;
		}

		world->setMove(*this, x + 1, y, x, y); //x,y at end is old coordinate

		return true;
	}

//*************MOVING LEFT
	if ((y - 1) >= 0 && world->grid[x][y - 1].type != LION && direction == LEFT)
	{
	
		if (world->grid[x][y - 1].type == ANT)
		{
			starveCounter = 0;
		}
		world->setMove(*this, x, y - 1, x, y); //x,y at end is old coordinate
		return true;
	}

//**************MOVING RIGHT
	if ((y + 1) < GRID_WIDTH && world->grid[x][y + 1].type != LION && direction == RIGHT)
	{
		
		if (world->grid[x][y + 1].type == ANT)
		{
			starveCounter = 0;
		}
		world->setMove(*this, x, y + 1, x, y); //x,y at end is old coordinate
		return true;
	}


//***********MOVING DIAGNOL

//****UP & RIGHT
	    
	if ((x - 1) >= 0 && (y + 1) < GRID_WIDTH && world->grid[x - 1][y +1].type != LION && direction == UP_RIGHT)
	{                 
		//so if it can do the above...do it, return true
		if (world->grid[x - 1][y + 1].type == ANT)
		{
			starveCounter = 0;
		}
		world->setMove(*this, x - 1, y + 1, x, y); //x,y at end is old coordinate
		return true;
	}

//****UP & LEFT
	if ((x - 1) >= 0 && (y - 1) >= 0 && world->grid[x - 1][y -1].type != LION && direction == UP_LEFT)
	{
		
		if (world->grid[x - 1][y - 1].type == ANT)
		{
			starveCounter = 0;
		}
		world->setMove(*this, x - 1, y - 1, x, y); //x,y at end is old coordinate
		return true;
	}

//****DOWN & LEFT
	if ((x + 1) < GRID_HEIGHT && (y - 1) >= 0 && world->grid[x + 1][y - 1].type != LION && direction == DOWN_LEFT)
	{
		
		if (world->grid[x + 1][y - 1].type == ANT)
		{
			starveCounter = 0;
		}
		world->setMove(*this, x + 1, y - 1, x, y); //x,y at end is old coordinate
		return true;
	}

//****DOWN & RIGHT
	if ((x + 1) < GRID_HEIGHT && (y + 1) < GRID_WIDTH && world->grid[x + 1][y + 1].type != LION && direction == DOWN_RIGHT)
	{
		
		if (world->grid[x + 1][y + 1].type == ANT)
		{
			starveCounter = 0;
		}
		world->setMove(*this, x + 1, y + 1, x, y); //x,y at end is old coordinate
		return true;
	}

	//Can't move the direction.
	return false;
}