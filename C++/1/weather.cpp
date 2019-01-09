//
//This program creates weather reports
//
//The user will be prompted for low and high
//temperatures possible for the day
//
//author:Jared Salvatore
//date: February 24, 2011
//

#include <ctime>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//
//Function prototypes
//

int	avgTempF(int[],int);
int	avgTempHi(int[],int);
int	avgTempLo(int[],int);
string	cloudConditions(void);
bool	continueYesNo(void);
int	convertFtoC(int);
int	dailyHi(int[],int);
int	dailyLo(int[],int);
void	displayInstructions(void);
void	displayReport(int[],int);
int	getInt(string);
int	randInt(int,int);
string	str(float);
string	str(int);
string	windDirection(void);

//
//Function main
//

void	main(void) {
	int	avgTemp;
	int	currTemp;
	int	hiBound;
	int	hiTemp;
	int	loBound;
	int	loTemp;
	int	nbrReadings;
	int	readings[24];

displayInstructions();

do {

	nbrReadings = getInt("Enter number of readings: ");

	loBound = getInt("Enter a low range temperature: ");

	hiBound = getInt("Enter a high range temperature: ");

	for(int i = 0; i < nbrReadings; i++){
		readings[i] = randInt(loBound,hiBound);
		cout << "\nReading is: "
		     << readings[i];
		}//end for

	}while(continueYesNo());

displayReport(readings,nbrReadings);

return;

}//end main

//
//Function cloud Cond
//

string	cloudCond(void) {

	string conditions[12];
	int index;
	static
	int prevIndex;

	conditions[0] = "Chance of Rain";
	conditions[1] = "Cloudy";
	conditions[2] = "Drizzling";
	conditions[3] = "Gusts of Wind and Hail";
	conditions[4] = "Mostly Clear";
	conditions[5] = "Overcast Skies";
	conditions[6] = "Partly Cloudy";
	conditions[7] = "Partly Sunny";
	conditions[8] = "Raining";
	conditions[9] = "Snowing";
	conditions[10] = "Sunny";
	conditions[11] = "Thunderstorms";

do {
	index = randInt(0,11);
   }while(index == prevIndex);
	prevIndex = index;
	return conditions[index];

}//end cloudCond

//
//Function displayInstructions
//

void	displayInstructions(void) {

	cout << "The user will be prompted for low and high\n";
	cout << "temperatures possible for the day.\n";

}//end displayInstructions


//
//Function displayReport
//

void	displayReport(int readings[],int nbrReadings) {

	int avgTemp;
	int avgTempHi;
	int avgTempLo;
	int currTempC;
	int currTempF;
	string direction;
	int hiTempC;
	int hiTempF;
	string line01;
	string line02;
	string line03;
	string line04;
	string line05;
	string line06;
	int loTempC;
	int loTempF;
	string report;
	string sky;
	int windSpeed;

	line01 = "Today's Weather Report\n\n";
	line02 = "Current Temp.: " + str(currTempF) + "F (" + str(currTempC) + "C)\n";
	line03 = "High/Low: " +str(hiTempF) + "/" + str(loTempF) + "F (" + str(hiTempC) + "/" + str(loTempC) + "C)\n";
	line04 = "Average: " + str(avgTemp) + "F\n";
	line05 = "Cloud Conditions: " + sky + "\n";
	line06 = "Wind from the " + direction + " at " + str(windSpeed) + " mph\n";

return;

} //end displayReport

//
// Function str
//

string	str(float valueFloat) {

	string valueStr;
	stringstream out;

	out << valueFloat;
	valueStr = out.str();

	return valueStr;

} // end str

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
//Function dailyHi
//

int	dailyHi(int readings[],int nbrReadings){

	int	hiTemp;
	hiTemp = readings[0];
	for(int i = 1; i < nbrReadings; i++){
		if(readings[i] > hiTemp)
			hiTemp = readings[i];


		}//end dailyHi

	return hiTemp;

}//end hiTemp

//
//Function dailyLo
//

int	dailyLo(int readings[],int nbrReadings){

	int	loTemp;
	loTemp = readings[0];
	for(int i = 1; i < nbrReadings; i++){
		if(readings[i] < loTemp)
			loTemp = readings[i];


		}//end for

	return loTemp;

}//end dailyLo

//
//Function avgTempF
//

int	avgTempF(int readings[],int nbrReadings) {

	int	avgTemp;
	int	total;

	total = 0;

for(int i = 0;i < nbrReadings; i++) {
	total = total + readings[i];

	}//end for

	avgTemp = (float)total/nbrReadings;

	return avgTemp;

}//end avgTempF


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

}// end continueYesNo

//
//Function convertFtoC
//

int	convertFtoC(int tempF) {
		int tempC;

		tempC = ((5*(tempF - 32.0))/9.0 + 0.5);
	return tempC;

}//end convertFtoC

//
//Function convertCtoF
//

int	convertCtoF(int tempC) {
		int tempF;

		tempC = ((9*(tempF + 32.0))/5.0 + 0.5);
	return tempF;

}//end convertCtoF

//
//Function getInt
//

int getInt(string prompt) {

	int valueInt;

	cout << prompt;
	cin  >> valueInt;

	return valueInt;

}//end getInt



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

}// end randInt

//
//
//

//
//Function windDirection
//

string	windDirection(void){

	string compass[8];
	int index;
	static
	int prevIndex = -1;

	compass[0] = "N";
	compass[1] = "NE";
	compass[2] = "E";
	compass[3] = "SE";
	compass[4] = "S";
	compass[5] = "SW";
	compass[6] = "W";
	compass[7] = "NW";

do {
	index = randInt(0,7);
   }while(index == prevIndex);
	prevIndex = index;
	return compass[index];

}//end windDirection

//
//Function avgTempHi
//

int avgTempHi(int readings[], int nbrReadings) {

	int count = 0;
	int avgTemp;
	int avgHi;
	int total = 0;

	avgTemp=avgTempF(readings,nbrReadings);

	for(int i = 0; i < nbrReadings; i++) {
		if(readings[i] >= avgTemp) {
			total = total + readings[i];
			count = count + 1;
		}//end if

	}//end for

	avgHi = (((float)total/count) + 0.5);

	return avgHi;

}//end avgTempHi

//
//Function avgTempLo
//

int avgTempLo(int readings[], int nbrReadings) {

	int count = 0;
	int avgTemp;
	int avgLo;
	int total = 0;

	avgTemp=avgTempF(readings,nbrReadings);

	for(int i = 0; i < nbrReadings; i++) {
		if(readings[i] <= avgTemp) {
			total = total + readings[i];
			count = count + 1;
		}//end if

	}//end for

	avgLo = (((float)total/count) + 0.5);

	return avgLo;

}//end avgTempLo
