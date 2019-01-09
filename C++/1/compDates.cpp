//
// This program reads in two dates (using three integers for each) and
// compares them.  It will determine if the first date entered occurs
// before or after the second date.  When the dates are the same
// you will be informed.
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

using namespace std;

//
// User defined globals
//

const
bool		AUTOMATED = true;
const
int		MAX_YEAR = 2100;
const
int		MIN_YEAR = 1600;

//
// Function prototypes
//

int	compDates(int, int, int, int, int, int);
bool	continueYesNo(void);
void	displayDates(int, int, int, int, int, int, int);
void	displayInstructions(void);
void	displayWelcome(void);
void	getDate(int&, int&, int&);
void	getDates(int&, int&, int&, int&, int&, int&);
int	getDay(int, int);
int	getMonth(void);
int	getYear(void);
bool	isLeapYear(int);
bool	isValidDay(int, int, int);
string	monthStr(int);
int	randInt(int, int);
string	str(int);

//
// Function main
//

void	main(void) {

	int		compare;
	int		day01;
	int		day02;
	int		month01;
	int		month02;
	int		year01;
	int		year02;

//
//Seeding the random number generator
//

	srand(time(0));

	displayWelcome();

	do {
	    displayInstructions();
	    
	    getDates(year01,month01,day01,year02,month02,day02);
	    
	compare = compDates(year01,month01,day01,year02,month02,day02);

	displayDates(year01,month01,day01,year02,month02,day02,compare);

	cout <<"\n";

	} while(continueYesNo());

	return;

} // end main

//
// Function compDates
//

int		compDates(int year01, int month01, int day01,
				  int year02, int month02, int day02) {

	int	compare;
	int	equalTo = 0;
	int	greaterThan = +1;
	int	lessThan = -1;

	if(year01 < year02)
	   compare = lessThan;
	else if(year01 > year02)
	   compare = greaterThan;
	else if(month01 < month02)
	   compare = lessThan;
	else if(month01 > month02)
	   compare = greaterThan;
	else if(day01 < day02)
	   compare = lessThan;
	else if(day01 > day02)
	   compare = greaterThan;

	else
	    compare = equalTo;

	return compare;

} // compDates

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
// Function displayDates
//

void	displayDates(int year01, int month01, int day01,
			int year02, int month02, int day02,
			int compare) {

	string	comparePhrase;
	string	date01;
	string	date02;

	date01 = monthStr(month01) + " " + str(day01) + ", " + str(year01);
	date02 = monthStr(month02) + " " + str(day02) + ", " + str(year02);

	if(compare == 0)
		cout << "\nThe two dates are the same: "
		     << date01
		     << ".";

	else {
		if(compare < 0)
			comparePhrase = " comes before ";

	
		else if(compare > 0)
			comparePhrase = " comes after ";
		cout << "\nThe date "
		     << date01
		     << comparePhrase
		     << date02
		     << ".";

	}//end if

	return;

} // end displayDates

//
// Function displayInstructions
//

void	displayInstructions(void) {

	cout << "\nEnter integers for each value when prompted for:\n\n"
		 << "year (range 1600-2100), month (range 1, 12), day (range 1, 31)\n\n";

	return;

} // end displayInstructions

//
// Function displayWelcome
//

void	displayWelcome(void) {

	cout << "\nThis program reads in two dates (using three integers for each) and\n"
		 << "compares them.  It will deternine if the first date entered occurs\n"
		 << "before or after the second date.  When the dates are the same\n"
		 << "you will be informed.\n\n";

	return;

} // end displayWelcome

//
// Function getDate
//

void	getDate(int& year, int& month, int& day) {

	year = getYear();
	month = getMonth();
	day = getDay(year,month);

	return;

} // end getDate

//
//Function getDates
//

void	getDates(int& year01, int& month01, int& day01, int& year02, int& month02, int& day02) {

	cout << "Entering the first date:\n\n";
	getDate(year01, month01, day01);
	cout << "\nEntering the second date:\n\n";
	getDate(year02, month02, day02);

	return;

}//end getDates

//
// Function getDay
//

int	getDay(int year, int month) {

	int	day;
	static
	int	prevDay = -1;

	do {

		if(AUTOMATED) {
			do {
				day = randInt(0,34);
			}while(day == prevDay);
		
			prevDay = day;

			cout << "  Enter day: "
			     << day
			     << "\n";

			}//end

		else {

			cout << "  Enter day: ";
			cin  >> day;

		}//end if

	}while(!isValidDay(year,month,day));

	return day;

} // end getDay

//
// Function getMonth
//

int		getMonth(void) {

	int	month;
	static
	int	prevMonth = -1;

	do {

		if(AUTOMATED) {
			do {
				month = randInt(0,14);
			}while(month == prevMonth);
		
			prevMonth = month;

			cout << "  Enter month: "
			     << month
			     << "\n";

			}//end

		else {

			cout << "  Enter month: ";
			cin  >> month;

		}//end if

	}while((month < 1) || (month > 12));

	return month;

} // end getMonth

//
// Function getYear
//

int		getYear(void) {

	int		year;
	static
	int	prevYear = -1;

	do {

		if(AUTOMATED) {
			do {
				year = randInt((MIN_YEAR - 50),(MAX_YEAR - 50));

			}while(year == prevYear);
		
			prevYear = year;

			cout << "  Enter year: "
			     << year
			     << "\n";

			}//end

		else {

			cout << "  Enter year: ";
			cin  >> year;

		}//end if

	}while((year < MIN_YEAR) || (year > MAX_YEAR));

	return year;

} // end getYear

//
// Function isLeapYear
//

bool	isLeapYear(int year) {

	bool	leapYear;

	if((year % 4) != 0)
	   leapYear = false;
	else if((year % 400) == 0)
	   leapYear = true;
	else if((year % 100) == 0)
	   leapYear = false;

	else
	    leapYear = true;

    return leapYear;

} // end isLeapYear

//
// Function isValidDay
//

bool	isValidDay(int year, int month, int day) {

	bool	validDay;
	int	nbrDays[12];

	nbrDays[0] = 31;
	nbrDays[1] = 28;
	nbrDays[2] = 31;
	nbrDays[3] = 30;
	nbrDays[4] = 31;
	nbrDays[5] = 30;
	nbrDays[6] = 31;
	nbrDays[7] = 30;
	nbrDays[8] = 31;
	nbrDays[9] = 30;
	nbrDays[10] = 31;
	nbrDays[11] = 30;

	if(day <= 0)
		validDay = false;
	else if((isLeapYear(year)) && (month = 2) && (day <= 29))
		validDay = true;
	else if(day <= nbrDays[month - 1])
		validDay = true;
	else
		validDay = false;

	return validDay;

} // end isValidDay

//
// Function monthStr
//

string	monthStr(int monthNbr) {

	string	months[12];
	months[0] = "January";
	months[1] = "February";
	months[2] = "March";
	months[3] = "April";
	months[4] = "May";
	months[5] = "June";
	months[6] = "July";
	months[7] = "August";
	months[8] = "September";
	months[9] = "October";
	months[10] = "November";
	months[11] = "December";

	return months[monthNbr - 1];

} // end monthStr

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