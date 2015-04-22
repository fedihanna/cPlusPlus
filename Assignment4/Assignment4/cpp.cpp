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
		string line;
		try
		{
			ifstream myfile(filePath);
			if (myfile.is_open())
			{
				while (!myfile.eof())
				{
					getline(myfile, line);//get line from file assign to str
					file.push_back(line); //adding the line to the array ...using "push_back"

				}
			}
			else
			{
				throw runtime_error("file reading error");
			}
		}
		catch (...)
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
		return file; //retyrn output
	}


	//*****************WRITING THE HTML FILE**********************
	static void fileParser::writeHtml(vector<string> file, string filePath)
	{
		try
		{
			ofstream HtmlFile(filePath);
			if (HtmlFile.is_open())
			{
				HtmlFile << "<PRE>";
				for (int line = 0; line < file.size(); line++) //loop for each line
				{
					HtmlFile << file[line] << "<br>";
				}
				HtmlFile << "</PRE>";
			}
			//if the file cant be opened, it produces an error
			else
			{
				throw runtime_error("file writing error");
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