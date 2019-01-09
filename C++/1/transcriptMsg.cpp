
//
//This program presents a transcript message for individual students.
//
//Author: Jared Salvatore
//Date:   February 10, 2011
//

#include <iostream>
#include <string>

using namespace std;

//
//Function prototype
//

string	transcriptMsg(float);

//
//	Function transcriptMsg
//

string transcriptMsg(float GPA) {

	int	index;
	string	messages[5];

	messages[0] = "Failed semester - registration suspended.";
	messages[1] = "On probation for the next semester.";
	messages[2] = "Average student rating.";
	messages[3] = "Dean's list for semester.";
	messages[4] = "Highest honors for semester.";

	if ((GPA >= 0.0) && (GPA < 1.0))
		index = 0;

	else if ((GPA >= 1.0) && (GPA < 2.0))
		index = 1;

	else if ((GPA >= 2.0) && (GPA < 3.0))
		index = 2;

	else if ((GPA >= 3.0) && (GPA < 3.5))
		index = 3;

	else if ((GPA >= 3.5) && (GPA <= 4.0))
		index = 4;

	return messages[index];

	}//end transcriptMsg


//
// Function main
//

void	main(void) {

	string	firstName;
	bool	forever = true;
	float	GPA;
	string	lastName;
	string	message;

cout << "This program presents a transcript message for individual students.\n"
	 << "After entering the students' first and last names, enter their GPA.\n\n";
	 

while(forever){

	cout << "Student First Name: ";
	cin  >> firstName;

	cout << "Student Last Name: ";
	cin  >> lastName;

	do{
			cout << "GPA: ";
			cin  >> GPA;
	}while(GPA < 0.0 || GPA > 4.0);

	message = transcriptMsg(GPA);

	cout << "\n"
		 << "\t"
		 << firstName
		 << " "
		 << lastName
		 << ": "
		 << message
		 << "\n\n";

	}//end while

}//end main

