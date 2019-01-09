//
// This program converts an integer into a
// text expression representing its value.
//
// Author: James Salvatore
// Date:   April 04, 2011
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
// User defined global constants
//

const
bool	AUTOMATIC = false;

//
// Function prototypes
//

bool	continueYesNo(void);
string	digitsToText(int);
void	displayResult(string);
void	displayWelcome(void);
int	getInt(string, int, int);
string	hundredsToText(int);
string	intToText(int);
int	randInt(int, int);
string	teensToText(int);
string	tensToText(int);
string	thousandsToText(int);

//
// Function main
//

void	main(void) {

	int	valueInt;
	string	valueStr;

	//
	// Seeding the random number generator
	//

	srand(time(0));

	displayWelcome();

    do {

		valueInt = getInt("Enter an integer: ", -9999, 9999);
		valueStr = intToText(valueInt);
		displayResult(valueStr);
		
	} while(continueYesNo());

	return;

} // end main

//
// Function continueYesNo
//

bool	continueYesNo(void) {

	bool	answer;
	bool	forever = true;
	string	yesNo;

	cout	<< "\n";

	while (forever) {

		cout << "Continue? (Yes/No): ";
		cin  >> yesNo;
	
		yesNo = yesNo.substr(0,1);

		if (yesNo == "Y" || 
		    yesNo == "y") {

			answer = true;
			break;

		}

		else if (yesNo == "N" ||
		         yesNo == "n") {

			answer = false;
			break;

		} // end if

	} // end while

	cout << "\n";

	return answer;

} // end continueYesNo

//
// Function digitsToText
//

string	digitsToText(int valueInt) {

	string	valueText;
	
	switch (valueInt) {

		case 0:
			
			valueText = "Zero";
			break;

		case 1:
			
			valueText = "One";
			break;

		case 2:

			valueText = "Two";
			break;

		case 3:
			
			valueText = "Three";
			break;
            
		case 4:

			valueText = "Four";
			break;

		case 5:

			valueText = "Five";
			break;

		case 6:

			valueText = "Six";
			break;

		case 7:

			valueText = "Seven";
			break;

		case 8:

			valueText = "Eight";
			break;

		case 9:
			
			valueText = "Nine";
			break;
	
	} // end switch

	return valueText;

} // end digitsToText

//
// Function displayResult
//

void	displayResult(string valueStr) {

	cout << valueStr
		<< "\n\n";

	return;

} // end displayResult

//
// Function displayWelcome
//

void	displayWelcome(void) {
	
	cout << "\nThis program converts an integer into a\n"
         << "text expression representing its value.\n\n";

	return;

} // end displayWelcome

//
// Function getInt
//

int	getInt(string prompt, int loBound, int hiBound) {

	int	valueInt;
	static
	int	prevValueInt = -1;

	do {
		if(AUTOMATIC) {
			do {
				valueInt = randInt((loBound - 10),(hiBound + 10));
				cout << prompt
				     << valueInt
				     << "\n";
			}while(valueInt == prevValueInt);
			prevValueInt = valueInt;

		}

		else {
			cout << prompt;
			cin  >> valueInt;
		}//end if

	}while((valueInt < loBound) || (valueInt > hiBound));

	return valueInt;

} // end getInt

//
// Function hundredsToText
//

string	hundredsToText(int valueInt) {

	string	valueText;

	valueText = digitsToText(valueInt) + " Hundred";

	return valueText;

} // end hundredsToText

//
// Function intToText
//

string	intToText(int valueInt) {

	int	digits;
	int	hundreds;
	string	spacer;
	int	tens;
	int	thousands;
	string	valueText = "";

	if(valueInt < 0){
		valueText = "Negative ";
		valueInt = abs(valueInt);

	}//end if

	thousands = valueInt / 1000;
	hundreds = valueInt / 100 - (thousands * 10);
	tens = valueInt / 10 - (thousands * 100) - (hundreds * 10);
	digits = valueInt % 10;

	if(thousands > 0)
		valueText = valueText + thousandsToText(thousands);
	if(hundreds > 0){
		if(thousands > 0)
			spacer = " ";
		else
			spacer = "";
		valueText = valueText + spacer + hundredsToText(hundreds);
	}
	if(tens > 0){
		if((thousands > 0) || (hundreds > 0))
			spacer = " ";
		else
			spacer = "";
		if(tens == 1){
			valueText = valueText + spacer + teensToText(digits);
			digits = 0;
		}//end if
		else
			valueText = valueText + spacer + tensToText(tens);
	}//end if
	if(digits > 0){
		if(((thousands > 0) || (hundreds > 0)) && (tens == 0))
			spacer = " ";
		else if(tens >= 2)
			spacer = "-";
		else
			spacer = "";
		valueText = valueText + spacer + digitsToText(digits);

	}
	else if((thousands == 0) && (hundreds == 0) && (tens == 0))
		valueText = "Zero";


	return valueText;

} // end intToText

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

//
// Function teensToText
//

string	teensToText(int valueInt) {

	string	valueText;
	
	switch (valueInt) {

		case 0:

			valueText = "Ten";
			break;

		case 1:

			valueText = "Eleven";
			break;

		case 2:

			valueText = "Twelve";
			break;

		case 3:

			valueText = "Thirteen";
			break;

		case 4:

			valueText = "Fourteen";
			break;

		case 5:

			valueText = "Fifteen";
			break;

		case 6:

			valueText = "Sixteen";
			break;

		case 7:

			valueText = "Seventeen";
			break;

		case 8:

			valueText = "Eighteen";
			break;

		case 9:

			valueText = "Nineteen";
			break;

	} // end switch

	return valueText;

} // end teensToText

//
// Function tensToText
//

string	tensToText(int valueInt) {

	string	valueText;
	
	switch (valueInt) {

		case 2:

			valueText = "Twenty";
			break;

		case 3:
			
			valueText = "Thirty";
			break;

		case 4:
			
			valueText = "Forty";
			break;

		case 5:
			
			valueText = "Fifty";
			break;

		case 6:
			
			valueText = "Sixty";
			break;

		case 7:
			
			valueText = "Seventy";
			break;

		case 8:
			
			valueText = "Eighty";
			break;

		case 9:
			
			valueText = "Ninety";
			break;

	} // end switch

	return valueText;

} // end tensToText

//
// Function thousandsToText
//

string	thousandsToText(int valueInt) {

	string	valueText;

	valueText = digitsToText(valueInt) + " Thousand";

	return valueText;

} // end thousandsToText