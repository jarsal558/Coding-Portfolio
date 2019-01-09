//
// This program converts binary numbers
// into integer values.
//
// Author:  Firstname Lastname
// Date:    April 07, 2011
//

//
// Including libraries and header files
//

#include <cctype>
#include <climits>
#include <cmath>
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

int	binToInt(string);
void	displayResult(string, int);
void	displayWelcome(void);
string	getBinary(string);
bool	isBinary(string);
string	lPad(string, int, string);

//
// Function main
//

void	main(void) {
	
	string	binaryNbr;
	bool	forever = true;
	int	valueInt;

	displayWelcome();

	while(forever) {

		binaryNbr = getBinary("Enter binary number: ");
		valueInt = binToInt(binaryNbr);
		displayResult(binaryNbr, valueInt);

	} // end while

} // end main

//
// Function binToInt
//

int binToInt(string binaryNbr) {

	string	bit;
	int	nbrBits;
	int	power;
	int	valueInt;

	valueInt = 0;

	nbrBits = binaryNbr.length();

	for(int i = 0;i < nbrBits;i++) {
		bit = binaryNbr.substr(i,1);
		power = (nbrBits - 1) - i;
		
		if(bit == "1")
			valueInt = valueInt + pow(2.0,power);
	}//end for

	return valueInt;

} // end binToInt

//
// Function displayResult
//

void	displayResult(string binaryNbr, int valueInt) {

	cout << binaryNbr
	     << " = "
	     << valueInt
	     << "\n";

	return;

}// end displayResult

//
// Function displayWelcome
//

void	displayWelcome(void) {

	cout << "\nThis program converts binary numbers\n"
		 << "into integer values.\n\n";

	return;

} // end displayWelcome

//
// Function getBinary
//

string getBinary(string prompt) {

	string	binaryNbr;

	do {

	cout << prompt;
	cin  >> binaryNbr;

	}while(!isBinary(binaryNbr));

	binaryNbr = lPad(binaryNbr,8,"0");

	return binaryNbr;

}// end getBinary

//
// Function isBinary
//

bool	isBinary(string binaryNbr) {

	bool	binary;
	string	bit;
	int	nbrBits;

	nbrBits = binaryNbr.length();
	binary = true;

	for(int i = 0; i < nbrBits; i++) {

	bit = binaryNbr.substr(i,1);
	if((bit != "0") && (bit != "1"))
		binary = false;

	}//end for

	return binary;

}//end isBinary

//
// Function lPad
//

string lPad(string valueStr, int width, string fillChar) {

	int		countPad;
	int		length;

	length = valueStr.length();
	countPad = width - length;

	for(int i = 0; i < countPad; i++) {

		valueStr = fillChar + valueStr;

	} // end for

	return valueStr;

} // end lPad