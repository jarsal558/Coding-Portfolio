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
//User defined types
//

struct	Menu_type{
	string	category;
	string	name;
	float	price;
	string	description;

};

//
// Function prototypes
//

void	displayData(Menu_type[], int);
void	loadData(ifstream&, Menu_type[], int&);

//
// User defined global constants
//

//
// Function main
//

void	main(void) {

	Menu_type	menu[100];
	int		menuSize = 0;
	ifstream	fileIn;

	//
	// Magic formula
	//

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	fileIn.open("owlsNestMenu.txt");

	loadData(fileIn, menu, menuSize);
	displayData(menu, menuSize);

	return;

} // end main

//
//Function loadData
//

void	loadData(ifstream& fileIn, Menu_type menu[], int& menuSize){
	string	priceStr;
	for(int i = 0; (getline(fileIn, menu[i].category)); i++){
		getline(fileIn, menu[i].name);
		getline(fileIn, priceStr);
		menu[i].price = atof(priceStr.c_str());
		getline(fileIn, menu[i].description);

		menuSize++;
	}//end for
}//end loadData

//
//Function displayData
//

void	displayData(Menu_type menu[], int menuSize){

for(int i = 0; i < menuSize; i++){
	cout << menu[i].category << "\n"
		<< menu[i].name << "\n"
		<< menu[i].price << "\n"
		<< menu[i].description << "\n\n";
}//end for

return;

}//end displayData