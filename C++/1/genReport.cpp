//
// This program
//
// Author: Firstname Lastname
// Date:   Month dd, yyyy
//

//
// Including libraries and header files
//

#include <cctype>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>

//
// Using the standard namespace
//

using namespace std;

//
// Function prototypes
//

void	displayInstructions(void);

//
// User defined global constants
//

//
// Function main
//

void	main(void) {

	int avg;
	int classSize;
	int courseNbr = 0;
	ifstream fileIn;
	ofstream fileOut;
	int grade;
	int largest;
	int smallest;
	int total;

	fileIn.open("genGrades.txt");;
	fileOut.open("genReport.txt");

	while(fileIn >> classSize) {
		
		total = 0;
		courseNbr++;

		for(int count = 0;count < classSize;count++) {
			fileIn >> grade;
			total = total + grade;

			if(count == 0) {
				smallest = grade;
				largest = grade;
			}
			else if(grade < smallest)
				smallest = grade;
			else if(grade > largest)
				largest = grade;

		}//end for

		avg = (float)total/classSize;

		cout << "Course "
		     << courseNbr
		     << ")b"
		     << classSize
		     << " grades were entered\n"
		     << "  Smallest grade: "
		     << smallest
		     << "\n"
		     << "  Largest grade: "
		     << largest
		     << "\n"
		     << "Average grade: "
		     << avg
		     << "\n\n";

	}//end while

	//
	// Seeding the random number generator
	//

	srand(time(0));

	//
	// Magic formula
	//

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);

	return;

} // end main

//
//Function displayInstructions
//

void	displayInstructions(void) {

	cout << "\nThis program determines the average, smallest,\n"
	     << "and largest grades for a set of courses.\n";
	     
	return;

}//end displayInstructions