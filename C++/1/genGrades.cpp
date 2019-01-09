//
// This program creates a file named grades.txt
//
// Author: Jared Salvatore
// Date:   May 2, 2011
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

int	randInt(int,int);

//
// User defined global constants
//

//
// Function main
//

void	main(void) {

	int classSize;
	ofstream fileOut;
	int classCount;
	int grade;
	int nbrClasses;

	fileOut.open("genGrades.txt");
	if(fileOut.fail()) {
		cout << "\n\nFile could not be opened.\n\n";

		return;
	}//end if

	nbrClasses = randInt(7,14);
	classCount = 0;
	while(classCount < nbrClasses) {
		classSize = randInt(10,24);
		fileOut << classSize
			<< "\n";

		for(int i = 0;i < classSize;i++) {
			grade = randInt(50,100);
			fileOut << grade
				<< "\n";
		}//end for
		
		classCount = classCount + 1;

	}//end while

	fileOut.close();

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
// Function randInt
//

int randInt(int loBound, int hiBound) {

	int intervalSize;
	int randomOffset;
	int value;

	intervalSize = (hiBound - loBound) + 1;

	randomOffset = rand() % intervalSize;
	value = loBound + randomOffset;

	return value;

} // end randInt