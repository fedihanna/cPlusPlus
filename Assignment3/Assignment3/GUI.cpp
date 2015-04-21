#include <string>
#include <iostream>
using namespace std;


//making a GUI class which will 
class GUI
{

	//the following are public so they are accesiable 
public:
	
	// function that allows us to print on the GUI
	//which has an output as string
	void print(string output) 
	{
		cout << output << endl; //displays the result of the output
	}

	//getline is a sttring that will allow to use tho following below
	string getline()
	{
		string input; // declaring a string input
		cin >> input; //putting what was typed into a variable
		return input; //returning the variable
	}
}; 