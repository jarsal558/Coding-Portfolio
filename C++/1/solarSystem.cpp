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
//Function Prototypes
//

void	displayData(string[],int[],float[],int);
void	loadData(ifstream,string[],int[],float[],int); //square brackets??
void	loadDiameters(int[],int);
void	loadDistances(float[],int);
void	loadPlanets(string[],int);

//
//Function main   local function??
//

void	main(void) {
	ifstream	fileIn;
	int		diameters[9];
	float		distances[9];
	string		planets[9];

	fileIn.open("solarSystem.txt");

	loadData(fileIn,planets,diameters,distances,9);
	displayData(planets,diameters,distances,9);

	fileIn.close();

	return;

}//end main

//
//Function loadData
//

void	loadData(ifstream dataFile,string planets[],int diameters[],float distances[],int count) {

	for(int i = 0;i < count;i++) {

		dataFile >> planets[i];
		dataFile >> diameters[i];
		dataFile >> distances[i];

	}//end for

	return;

}//end loadData

//
//Function loadPlanets
//

void	loadPlanets(string planets[],int Count) {

	planets[0] = "Mercury";
	planets[1] = "Venus";
	planets[2] = "Earth";
	planets[3] = "Mars";
	planets[4] = "Jupiter";
	planets[5] = "Saturn";
	planets[6] = "Uranus";
	planets[7] = "Neptune";
	planets[8] = "Pluto";

	return;

}//end loadPlanets

//
//Function loadDiameters
//

void	loadDiameters(int diameters[],int count) {

	diameters[0] = 4878;
	diameters[1] = 12102;
	diameters[2] = 12760;
	diameters[3] = 6786;
	diameters[4] = 142800;
	diameters[5] = 120660;
	diameters[6] = 52400;
	diameters[7] = 50460;
	diameters[8] = 2200;

	return;

}//end loadDiameters

//
//Function loadDistances
//

void	loadDistances(float distances[],int count) {

	distances[0] = 57.91;
	distances[1] = 108.2;
	distances[2] = 149.6;
	distances[3] = 227.94;
	distances[4] = 778.33;
	distances[5] = 14276.94;
	distances[6] = 2870.99;
	distances[7] = 4497.07;
	distances[8] = 5913.52;

	return;

}//end loadDistances

//
//Function displayData
//

void	displayData(string planets[], int diameters[],float distances[],int count) {

	cout << "\n";
	for(int i = 0;i < count;i++) {
		cout << planets[i] << "\n"
		     << diameters[i] << "\n"
		     << distances[i] << "\n";
	}//end for

	return;

}//end displayData