#include <string>
#include <iostream>
using namespace std;

class Student //Student class created
			  //below are the 3 variables
{
private:

	string *courseList; //this is a pointer to the array "courseList"
						//dynamically declared array of strings used to store course names

	int numCourses; //declaring "numCourses" as int
					//tracks how many courses the student is enrolled in

	string name; //declaring a string "name"
				 //stores name of student

public:

	void printList() //function that prints the list of courses.
					//it works by going through the courses the user has entered
					 
	{
		for (int x = 0; x < numCourses; x++) //for loop for the number of courses
		{
			cout << courseList[x] << endl; //printing the course list
		}
	}//end void printList

	//creating a getter...getName
	//this is done so we can refer to the name entered
	string getName()
	{
		return this->name; //return the name inputted  
	}

	//creating a getter ....getNumCourses
	//this is done so we can refer to the courses entered
	string getNumCourses()
	{
		//returns the string with the representation of the value
		return to_string(this->numCourses); //return the number of courses
	}

	//function made to set name
	//this is done so the name will display when copy 
	void setName(string name)
	{
		this->name = name; //set the name inputted
						   //when the 1st student is entered, we only deal with this student
						  // and his courses
		//when the 2nd student is entered, we only deal with his name and courses
	}


//****************DEFAULT CONSTRUCTOR...defaulting everything to zero******************//

	//always start everything at 0
	//referiong to our student class
	Student()
	{
		courseList = NULL; //refering to this string
		numCourses = 0; //number of courses will equal zero
		name = ""; // name will be set to blank

	}
//********************************************************************************//


//*****************************ASSIGNMNET OVERLOAD********************************//

	//overloading the = operator so one student can equal another
	Student operator = (Student &rightSide)

	{
		cout << "assignment operator (=) triggered" << endl;

		// new array made for 2nd student courses
		// put on the right side for student 2 assignment operation
		//put on right side because arrays read from the left
		 string *tempArray = new string[rightSide.numCourses]; // temp array made 
		for (int x = 0; x < rightSide.numCourses; x++)
		{			
			tempArray[x] = rightSide.courseList[x]; //right side taking value of temp array 
			                                        //and amount entered in course list

		}
		
		if (numCourses > 0) //if there is any vlaues or new courses 
			                //entered, delete them
		delete[] courseList;

		//overload happening
		courseList = tempArray; //courselist being overloaded by temp array
		name = rightSide.name; //rightside.name overloading name
		numCourses = rightSide.numCourses; //rightside.numCourses overloading numCourses
		return *this; //"this" is reffering to this object, which is the 1st student
					 //1st student because when overloading it looks to the left hand side object
	}
	
//*************************************************************************************//



//**********************************COPY CONSTRUCTOR********************************//


	//const for constructor of student
	Student(const Student& studentToCopy)//copy constructor
	{
		// constructing a new student copying another one
		cout << "copy constructor triggered" << endl; //will display when the copy constructor is triggering
		name = ""; //left blank for user input //name is going to be blank
		numCourses = 0; // number of courses is going to be blank
		courseList = NULL; // must be NULL at start up


		//pointed to the address of the temp array to be copied
		string *tempArray = new string[studentToCopy.numCourses];
		//for loop for the copy when the values are entered
		for (int x = 0; x < studentToCopy.numCourses; x++)
		{

			tempArray[x] = studentToCopy.courseList[x]; //studentToCopy and the courseList take the value entered
			                                            //of the tempArray
		}
		courseList = tempArray; //tempArray has copied the courseList entered
		numCourses = studentToCopy.numCourses; //studentToCopy and the numCourses have copied numCourses from original
	}
//**************************************************************************************//


//***************************************DESTRUCTOR************************************//

	//String reaching end scope
	//needed to make sure evrything is gone so no leaks in the heap
	//"~" this sign means the scope is ending
	~Student()//destructor 
	{
		cout << "deconstructor triggered" << endl;
		if (this->courseList != NULL)
		{
			//delete this->strMem;//leaks
			delete[] this->courseList;//custom code works-no leaks
									// delets all elements
		}
		courseList = NULL; //then make it equal NULL
	}
//**************************************************************************************//


	//function that inputs values from user
	void addCourse(string course)
	{
		//pointing to the address of the temp array and allowing us to add courses to it
		string *tempArray = new string[numCourses + 1]; //because we are adding a course

		for (int x = 0; x < numCourses; x++) //for loop going through our array 
		{
			tempArray[x] = courseList[x]; //made a new array with the old elements in it
		}
		tempArray[numCourses] = course; //the array holding the number of courses entered

		if (numCourses > 0) //if there is courses
			delete[] courseList; //delete every element in this array

		courseList = tempArray; 
		numCourses++; //Increases course count to match num of courses
	}

	//function that resets number of classes to zero
	void reset()
	{
		if (numCourses > 0) // if number of courses equal zero
			delete[] courseList; //delete every element in this array
		numCourses = 0; //reset the number of courses to zero

	}

};


