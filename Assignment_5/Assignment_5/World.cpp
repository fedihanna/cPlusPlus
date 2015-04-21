#include "World.h"
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>




// On creation of the world, the constructor randomly places 
// Ants and Lions throughout the world.
World::World()
{
	//makes every spot in the grid avaiable for an organism
	for (int rows = 0; rows < GRID_HEIGHT; rows++)
	{
		grid[rows] = new Organism[GRID_WIDTH];
	}

	//*****************PLACE ANT IN RANDOM LOCATION
	int ant = 0;
	while(ant <= START_ANT_AMOUNT)
	{
		
		//random location between zero and the grid height  
		int randRow = (rand() % (0 - GRID_HEIGHT)); //rows
		//random location between zero and the grid width
		int randColumn = (rand() % (0 - GRID_WIDTH)); //columns

		if (grid[randRow][randColumn].type != ANT && //if rows and columns are not ants
			grid[randRow][randColumn].type != LION) //if rows and columns are not lions
		{
			grid[randRow][randColumn] = *new Ant; //then place an ant
			ant++;
		}
	}

	//*****************PLACE LION IN RANDOM LOCATION
	int lion = 0;
	while(lion < START_LION_AMOUNT)
	{
		//random location
		int randRow = (rand() % (0 - GRID_HEIGHT));
		int randColumn = (rand() % (0 - GRID_WIDTH));

		if (grid[randRow][randColumn].type != ANT && 
			grid[randRow][randColumn].type != LION)
		{
			grid[randRow][randColumn] = *new Lion;
			lion++;
		}
	}
}

//********PRINT
 void World::printWorld()
{
	ants = 0;
	lions = 0;
	 system("cls");//clear the console after each turn
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //setting grid to white
	 for (int rows = 0; rows < GRID_HEIGHT; rows++)
	 {
		 for (int columns = 0; columns < GRID_WIDTH; columns++)
		 {
			 if (grid[rows][columns].type == LION){
				 //setting colors for LION to red
				 //handles the object........STD_OUTPUT_HANDLE
				 //4 (which is red)
				 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //x is red
				 cout << "x";
				 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //grid is white
				 lions++;

				 //setting colors for ANT to green
				 //handles the object........STD_OUTPUT_HANDLE
				 //2 (which is green)
			 }
			 else if (grid[rows][columns].type == ANT){
				 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); //o is green
				 cout << "o";
				 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //grid is white
				 ants++;
			 }
			 else{
				 cout << "-";
			 }
		 }
		 cout << endl;
	 }
}

 //*******************MOVES ANT & LION
 void World::move(Organism *organism, int x, int y)
 {
	 if (organism->type == ANT)
	 {
		 Ant *pointer = (Ant *) organism;
		 pointer->move(this,  x,  y); // This moves an Ant - Ant.cpp (Line 10)
	 }
	 else if (organism->type == LION)
	 {
		 Lion *pointer = (Lion *)organism;
		 pointer->move(this,  x, y); // This moves a Lion - Lion.cpp (Line 10)
	 }	 
}


 void World::setMove(Organism organism, int x, int y, int oldX, int oldY)
 {
	 //world grid for organisms
	 grid[x][y] = organism;

	 if ((grid[x][y].breedCounter < 8 && grid[x][y].type == LION) //making breed counter greater or equal to 8 for lion
		 || (grid[x][y].breedCounter <= 3 && grid[x][y].type == ANT)) //making breed counter greater or equal to 3 for ant
	 { 
		 
		 //these are the old locations....we are wiping to prevent duplication
		 grid[oldX][oldY].type = NEITHER; //its a lion, ant or neither.....(Organisism.h Line 6)
	 }
	 // BREED (Both Lion and Ant)
	 else 
	 {
		 // The old Organism (parent) has it's breed counter reset once it's bred!
		 //because the organism is a clone of the old one
		 grid[x][y].breedCounter = 0; //reseting new world
		 grid[oldX][oldY].breedCounter = 0; //reseting old world
	 }
 }