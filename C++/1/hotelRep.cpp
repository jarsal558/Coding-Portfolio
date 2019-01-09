//
// Hotel Report
//
// Author: Jared Salvatore
// Date:   4-11-11
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

void	main;

//
//Function main
//

void	main(void) {

	int	nbrFloors;
	int	nbrRooms;
	int	nbrOccupy;
	int	totalRooms;
	int	totalOccupy;


	cout << "Enter number of floors: ";
	cin  >> nbrFloors;


	for(int i = 0; i < nbrFloors; i++) {

		nbrRooms = 0
		nbrOccupy = 0

		cout << "Enter number of rooms on Floor 1: ";
		cin  >> nbrRooms;
		cout << "Enter number of rooms occupied: ";
		cin  >> nbrOccupy;

		totalRooms = totalRooms + nbrRooms;

		totalOccupy = totalOccupy + nbrOccupy;
	

	if(i == 13)
		continue



	percent = (float)nbrOccupied/totalRooms;

	cout << "Floor is "
	     << ((nbrOccupy / nbrRooms) * 100)
	     << " % full.";


	cout << "Hotel is "
	     << ((totalOccupy / totalRooms) * 100)
	     << " % full";
		
