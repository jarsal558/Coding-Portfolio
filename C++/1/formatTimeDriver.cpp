//
// This program is the driver for testing
// the function 'formatTime'.
//
// Author: Jared Salvatore
// Date:   March 28, 2011
//

//
//User global constants
//

const
int	MAX_PRESSURE = 700;
const
int	MIN_PRESSURE = 300;
const
int	PRESSURE_RANGE = (MAX_PRESSURE - MIN_PRESSURE);

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

bool	continueYesNo(void);
void	displayReading(int, int);
string	formatTime(int);
string	lPad(string, int, string);
int	nextReading(int);
int	pressureReading(void);
int	randInt(int, int);
string	str(int);

//
// Function main
//

void	main(void) {

	int	pressure;
	int	randInt(int,int);
	int	seconds = 0;
	string	timeStr;


	for(int i = 1; i < 10000; i++) {

		seconds = nextReading(seconds);
		pressure = pressureReading();
		displayReading(seconds,pressure);

		Sleep (250);

		}//end for

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
//Function displayReading
//

void	displayReading(int seconds,int pressure) {

	string	timeStr;

	timeStr = formatTime(seconds);

	cout << timeStr
	     << " Pressure is: "
	     << pressure;

	if(pressure >= MAX_PRESSURE)
		cout << " ***High Reading***\n";

	else if(pressure <= MIN_PRESSURE)
		cout << " ***Low Reading***\n";

	else
		cout << "\n";

	return;

}//end displayReading

//
// Function formatTime
//

string formatTime(int seconds) {

	int	hours;
	int	minutes;
	string	timeStr;

	hours = seconds / 3600;
	minutes = (seconds / 60) - (hours * 60);
	seconds = seconds % 60;
	
	timeStr = lPad(str(hours),2,"0") + 
	":"				 +
	lPad(str(minutes),2,"0")	 +
	":"				 +
	lPad(str(seconds),2,"0");

	return timeStr;

} // end formatTime

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
// Function str
//

string	str(int valueInt) {

	string valueStr;
	stringstream out;

	out << valueInt;
	valueStr = out.str();

	return valueStr;

} // end str


//
// Function nextReading
//

int		nextReading(int seconds) {

	seconds = seconds + randInt(120, 420);

	if(seconds > 86399)

		seconds = randInt(0, 59);

	return seconds;

} // end nextReading

//
// Function pressureReading
//

int		pressureReading(void) {

	int		hiBound;
	int		loBound;
	int		pressure;
	static
	int		prevPressure = randInt(MIN_PRESSURE, MAX_PRESSURE);

	loBound = prevPressure - (PRESSURE_RANGE * 0.10);

	if(loBound < MIN_PRESSURE)
		loBound = MIN_PRESSURE;

	hiBound = loBound + (PRESSURE_RANGE * 0.20);

	if(hiBound > MAX_PRESSURE)
		hiBound = MAX_PRESSURE;
		loBound = hiBound - (PRESSURE_RANGE * 0.20);

	do {
		
		pressure = randInt(loBound, hiBound);
		
	} while(((pressure % 25) != 0));
	
	prevPressure = pressure;

	return pressure;

} // end pressureReading
