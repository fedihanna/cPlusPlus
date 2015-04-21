#include "Student.cpp"
#include <iostream>
#include <conio.h>
#include "GUI.cpp" //include it is known in the source.cpp
#include <cstdio>
#include <regex>
using namespace std;

int main()
{
	regex YN("[y|n]"); //the validation expression
	GUI gui; // gui of type GUI class
	Student student; //student of type Student class
	string answer;

	do //do while loop testing the condition for both students being entered
	{
		gui.print("\nEnter student name: "); //gui printing the name

		//student using the setName function to refer to the name entered
		student.setName(gui.getline());


		do //do while loop for 
		{
			gui.print("Enter course: "); //gui printing the course
			student.addCourse(gui.getline()); //student calling on the addCourse function
			
			answer = "";
			while (!regex_match(answer, YN)) //regex matches the gui....then break
			{
				gui.print("Enter another course ? y/n "); //gui printing the course
				answer = gui.getline();
				if (!regex_match(answer, YN)){ //validating for yes or no
					cout << "Invalid. Try again." << endl; // if not then display the following match
				}										
			}

		} while (answer != "n"); //while loop that will keep looping
		//until the user enters "n"




		//as soon as "n" is pressed and then "Enter"
		gui.print(student.getName()); //user name is displayed
		gui.print(student.getNumCourses()); //the number of courses is displayed
		student.printList(); //prints the list using the printList function



		// Then next student is asked to enter name
		gui.print("\nEnter next student name: "); //gui wiull print name entered
		string nameTwo = gui.getline(); // getting the name for the 2nd student
		Student student2(student); //COPY CONSTRUCTOR is triggered now the next student becomes the first
		student2.setName(nameTwo); //sets the name
		gui.print(student2.getName()); //gets the name 
		gui.print(student2.getNumCourses()); //gets the courses
		student2.printList(); //prints the list


		//
		gui.print("\nFirst student after reset "); // displays this message
		gui.print(student.getName()); //gets the name
		student.reset(); //resets to zero
		gui.print(student.getNumCourses()); //prints zero...
		student = student2; //overloading the assignment operator

	} while (true); // causes this loop to go on, "ENTER STUDENT NAME"
	return 0; 
}

