//Assingment 4 (without header)




// working directory:
// E:\IT COURSE 2014-15 (PART 3)\PROG 2100\Assignment4\Assignment4
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <vector>


using namespace std;

class fileParser
{
public:

	//*****************READING THE CPP FILE**********************

	static vector<string> fileParser::getCppFileArray(string filePath) //input string 
	{
		vector<string> file; //array of strings
		string line; //declaring line as string
		try
		{
			//the CONSTRUCTOR ifstream ...making "myfile"
			ifstream myfile(filePath);
			if (myfile.is_open())
			{
				while (!myfile.eof()) //when the myfile reaches eof(end of line)
				{
					getline(myfile, line);//get line from file assigned to string
					//PUSH_BACK adds a new element at the end of the vector, after its current last element
					file.push_back(line); //adding the line to the array ...using "push_back"

				}
			}
			else
			{
				throw runtime_error("file reading error");
			}
		}
		catch (...)//catches if it cant read it....dipalys the "file reading error"
		{
			cout << "file reading error" << endl;
		}
		return file;
	}

	//method that is returning an array which replaces chevorons
	static vector<string> fileParser::replaceChev(vector<string> file)
	{
		for (int line = 0; line < file.size(); line++) //loop for each line
		{
			string tempLine; //temp line to hold chevoron replacement line
			for (int character = 0; character < file[line].length(); character++) // loop for each character
			{
				switch (file[line].at(character)) //switch case comes in and looks for characters and symbols
				{
				case '<': tempLine += "&lt;"; //when it hits this  "<" change to &lt
					break;
				case '>': tempLine += "&gt;";//when it hits this ">" change to &gt
					break;
				default: tempLine += file[line].at(character);//if neither chevrons are found...add character that is already there
					break;
				}
			}
			file[line] = tempLine; //make the file equal to the new temp line
		}
		return file; //return output
	}


	//*****************WRITING THE HTML FILE**********************
	static void fileParser::writeHtml(vector<string> file, string filePath) //input string
	{
		try
		{
			//output stream that operates the file
			ofstream HtmlFile(filePath);
			if (HtmlFile.is_open())
			{
				HtmlFile << "<PRE>" << endl; //inserts "<PRE> at beginning
				for (int line = 0; line < file.size(); line++) //loop for each line
				{
					HtmlFile << file[line] << endl; //finshes going through the html file
				}
				HtmlFile << "</PRE>"; //inserts "/<PRE>" at end
			}
			//if the file cant be opened, it produces an error
			else
			{
				//the exception being thrown is a runtime error
				throw runtime_error("file writing error"); // messgae if an  throw error occurs
			}
		}
		catch (...)
		{
			cout << "file writing error" << endl; //displays the error on screen
		}
	}
};

//******************GETTING THE USER INPUTS*****************
int main()
{
	string input, output;
	cout << "Please enter cpp file name" << endl;
	cin >> input;
	cout << "Please enter html file name" << endl;
	cin >> output;

	//write an html file after replacing all the chevs in a cpp file (the cpp contents are held in array)
	fileParser::writeHtml(fileParser::replaceChev(fileParser::getCppFileArray(input)), output);
	cout << "conversion is a success" << endl;
	_getch();
	return 0;
}//end main
