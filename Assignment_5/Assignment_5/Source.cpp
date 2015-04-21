#include "World.h"
#include <ctime>


using namespace std;

int main()
{
	World world;

	// The battle must last 100 turns. 
	// We move all organisms 100 times.
	for (int turn = 0; turn < 100; turn++)
	{

		if (world.lions == 0 || world.ants == 0)
		{
			break;
		}
		// Here we iterate over each location of the world array.
		for (int row = 0; row < GRID_HEIGHT; row++){
			for (int column = 0; column < GRID_WIDTH; column++){

				// Before we move an organism, we check that it
				// exists, and whether or not it has already moved during
				// this turn.
				if ((world.grid[row][column].type == ANT ||
					world.grid[row][column].type == LION) && 
					world.grid[row][column].moved == false){ //hasnt moved yet

					// This calls the "Move" method in the Organism.cpp (Line 9)
					world.grid[row][column].move(&world, row, column);
				}
			}
		}
		//here we actually allow the organisms to move
		for (int row = 0; row < GRID_HEIGHT; row++)
		{
			for (int column = 0; column < GRID_WIDTH; column++)
			{
				world.grid[row][column].moved = false;
			}
		}
//*********************PRINTS WORLD AND CURRENT TURN (COUNTER)
		world.printWorld();
		cout << turn + 1 << endl;
		cout << "Lions: " << world.lions << endl;
		cout << "Ants " << world.ants << endl;

//*********************TIMER
		int temp = time(NULL) + 1; //timer pauses for 1 sec
		while (temp>time(NULL));
	}
	//so when lions or ants are extinct
	if (world.lions == 0 || world.ants == 0){
		cout << "Extinction Event" << endl;
	}
	//keeping the window open using getch
	int getch;
	std::cin >> getch;
	return 0;
}