//
// This program calculates payroll for individual employees.
//
// Author: Jared Salvatore
// Date:   February 21, 2010
//

#include <iostream>
#include <string>

using namespace std;

//
// Function prototypes
//

float	calculateGross(float, float);
float	calculateOT(float, float);
float	calculateRegular(float, float);
bool	continueYesNo(void);
void	displayEmpRecord(string, string, float, float, float);
void	displayInstructions(void);
void	getEmployee(string&, string&, float&, float&);

//
// Function main
//

void	main(void) {

	string	firstName;
	float		grossPay;
	float		hours;
	float		hourlyRate;
	string	lastName;
	float		overtimePay;
	float		regulayPay;

	displayInstructions();

	do {

		getEmployee(firstName, lastName, hours, hourlyRate);

		regulayPay  = calculateRegular(hours, hourlyRate);
		overtimePay = calculateOT(hours, hourlyRate);
		grossPay    = calculateGross(regulayPay, overtimePay);

		displayEmpRecord(firstName, lastName, regulayPay, overtimePay, grossPay);

	} while(continueYesNo());

} // end main

//
//Function calculate gross
//

float		calculateGross(float regPay,float OTPay){

	float		grossPay;
	
	grossPay = regPay + OTPay;

	return	grossPay;
}// end calculateGross

//
//Function CalculateOT
//

float	calculateOT(float hours,float rate){

	float		OTPay;

	if(hours <= 40.0)
	   OTPay = 0.00;
	else
	    OTPay = (hours - 40.0) * (rate * 1.5);

	return	OTPay;

}//end calculateOT

//
//Function calculateRegular
//

float		calculateRegular(float hours, float rate){

	float regPay;
	if(hours < 40.0)
		regPay = hours * rate;
	else
		regPay = 40.0 * rate;

	return	regPay;

}//end calculateRegular

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
//Function empRecord
//

void	 displayEmpRecord(string firstName, string lastName, float regularPay, float overtimePay, float grossPay){

//
//Magic Formula
//

cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);

cout << "\n\n"
	<< firstName
	<< " "
	<< lastName
	<< " salary:\n\n"
	<< "\tRegular: $"
	<< regularPay
	<< ", Overtime: $"
	<< overtimePay
	<< ", Gross: $"
	<< grossPay
	<< "\n\n";

	return;

}//end EmpRecord

//
//Function displayInstructions
//

void displayInstructions(void){

	cout << "This program calculates payroll for individual employees.\n\n";

	return;

}//end displayInstructions

//
//Function getEmployee
//

void getEmployee(string& firstName, string& lastName, float& hours, float& hourlyRate){

cout << "Employee first name: ";
cin  >> firstName;

cout << "Employee last name: ";
cin	>> lastName;

cout << "Hours worked: ";
cin	>> hours;

cout	<< "Hourly rate: ";
cin	>> hourlyRate;

	return;

}//end getEmployee