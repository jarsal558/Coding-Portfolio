#include <iostream>
#include <sstream>

using namespace std;

//
// Function prototypes
//

string	str(bool);
string	str(double);
string	str(float);
string	str(int);

void	main(void) {

	bool	forever = true;
	bool	valueBool;
	double	valueDouble;
	float	valueFloat;
	int	valueInt;
	string	message;

	while (forever) {

		cout << "Enter an integer value: ";
		cin  >> valueInt;

		cout << "Enter a float value: ";
		cin  >> valueFloat;

		cout << "Enter a double value: ";
		cin  >> valueDouble;

		cout << "Enter a bool value (0 or 1): ";
		cin  >> valueBool;

		cout << "\n";

		message = "This is the integer value: " + str(valueInt) + ".\n";
		cout << message;

		message = "This is the float   value: " + str(valueFloat) + ".\n";
		cout << message;

		message = "This is the double  value: " + str(valueDouble) + ".\n";
		cout << message;

		message = "This is the bool    value: " + str(valueBool) + ".\n";
		cout << message;

		cout << "\n";

	} // end while

} // end main

//
// Function str
//

string	str(bool valueBool) {

	string valueStr;
	stringstream out;

	if(valueBool)
		valueStr = "true";

	else
		valueStr = "false";

	return valueStr;

} // end str

//
// Function str
//

string	str(double valueDouble) {

	string valueStr;
	stringstream out;

	out << valueDouble;
	valueStr = out.str();

	return valueStr;

} // end str

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