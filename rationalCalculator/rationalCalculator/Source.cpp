#include <iostream>
#include <conio.h>
#include <regex>
#include <string>
#include "Rational.h" //include programmer defined header
using namespace std;


int main()
{

	//creating a regular expression
	//^0 or 1 negative number
	//from 0 to 9 digits
	//up to 1 to 8 numbers
	//then a slash
	//repeat for the denomi
	//at the end we want to be able to choose whether or not we want a denominator 
	regex regexRational("^-{0,1}[0-9]{1,8}(/-{0,1}[0-9]{1,8}){0,1}$");

	string str; //declaring our string as "str"
	int counter = 0; //will increment when slash  "/" is found int the string
	int intArray[2]; //made 2 because of 2 location ....num and dum

	while (true) //while loop used to validate
	{
		cout << "Enter a fraction" << endl; //displays "enter a fraction"
		getline(cin, str); //inputs your string

		if (regex_match(str, regexRational)) //regex matches the str....then break
		{
			break;
		}

		cout << "Invalid. Try again." << endl; // if not then display the following match
	}

	for (int i = 0; i < str.length(); i++){ //loop for every character in the string

		if (isdigit(str[i])){ //"isdigit" is checking if this character is a number
			//if so then let it take the first position in the array


			//calling on the array
			//"atoi" making sure the number is integral
			//taking that value and concatinting to 
			// "c_str" a pointer to an array ...would be the value of x in this case
			intArray[counter] = atoi(str.substr(i, 1).c_str()); //putting a character into an integer array if it is a number 
		}
		else
		{
			counter++; //its not a digit so it moves on the to the dum entry
		}
	}
	//first Rational fraction set to be enetered..."rational"
	Rational rational(intArray[0], intArray[1]);//set of first fraction
	counter = 0;

	while (true) //while loop used to validate
	{
		
		cout << "Enter another fraction" << endl; //displays "enter a fraction"
		getline(cin, str); //inputs your string

		if (regex_match(str, regexRational)) //regex matches the str....then break
		{
			break;
		}

		cout << "Invalid. Try again." << endl; // if not then display the following match
	}

	//loop for every character in the string
	for (int i = 0; i < str.length(); i++)
	{

		if (isdigit(str[i])){ //if this character is a number

			intArray[counter] = atoi(str.substr(i, 1).c_str()); //putting a character into an integer array if it is a number 
		}//end if
		else
		{
			counter++; //its not a digit so it moves on the to the dum entry
		}//end else
	}//end for 


	//second Rational fraction set to be enetered..."rational2"
	Rational rational2(intArray[0], intArray[1]); //set of second fraction


	//third Rational fraction set to be enetered..."rational3"
	Rational rational3 = rational + rational2;//
	rational3.normalize(); //reduce our fraction answer
	cout << "Fraction 1 + Fraction 2 = " << to_string(rational3.num) << "/" << to_string(rational3.dum) << endl;


	rational3 = rational - rational2;//
	rational3.normalize();
	cout << "Fraction 1 - Fraction 2 = " << to_string(rational3.num) << "/" << to_string(rational3.dum) << endl;


	rational3 = rational * rational2;//
	rational3.normalize();
	cout << "Fraction 1 * Fraction 2 = " << to_string(rational3.num) << "/" << to_string(rational3.dum) << endl;


	rational3 = rational / rational2;//
	rational3.normalize();
	cout << "Fraction 1 / Fraction 2 = " << to_string(rational3.num) << "/" << to_string(rational3.dum) << endl;


	if (rational == rational2){//checking if fractions are equal
		cout << "Fraction 1 == Fraction 2 = True" << endl;
	}
	else
	{
		cout << "Fraction 1 == Fraction 2 = False" << endl;
	}
	if (rational < rational2){
		cout << "Fraction 1 < Fraction 2 = True" << endl;
	}
	else
	{
		cout << "Fraction 1 < Fraction 2 = False" << endl;
	}
	if (rational > rational2){
		cout << "Fraction 1 > Fraction 2 = True" << endl;
	}
	else
	{
		cout << "Fraction 1 > Fraction 2 = False" << endl;
	}

	_getch();
}



