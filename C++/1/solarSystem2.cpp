//solarSystem2.cpp
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
//user defined types
//

struct Planet_type {
	string	name;
	int	diameter;
	float	distance;
};

//
//Function Prototypes
//


void	displayPlanets(const Planet_type[],int);
void	loadPlanets(ifstream&, Planet_type[],int);


//
//Function main
//

void	main(void) {
	ifstream	fileIn;
	const
	int		count = 9;
	Planet_type	planets[count];


//
//Magic formula
//

	cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);

	fileIn.open("solarSystem.txt");

	if(!(fileIn.fail())) {
		loadPlanets(fileIn,planets,count);
		displayPlanets(planets,count);
		fileIn.close();
	}//end if

	else
		cout << "Failed to open data file.\n\n";

	return;

}//end main


//
//Function loadPlanets
//

void	loadPlanets(ifstream& fileIn,Planet_type planets[],int count) {

	for(int i = 0;i < count;i++) {

		fileIn >> planets[i].name
		       >> planets[i].diameter
		       >> planets[i].distance;

	}//end for

	return;

}//end loadData

//
//Function displayPlanets
//

void	displayPlanets(const Planet_type planets[],int count) {

	for(int i = 0;i < count;i++) {
		cout << "Planet " 
		     << (i+1) 
		     << ": "
		     << planets[i].name
		     << "\nDiameter: " 
		     << planets[i].diameter
		     << " (KM)\nDistance: "
		     << planets[i].distance
		     << " (million KM)\n\n";
	}//end for

	return;

}//end displayData