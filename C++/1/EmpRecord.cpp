//
//This program creates an employee record.
//

#include <iostream>
#include <string>

using namespace std;

//
//Function main
//
void	main(void){
  string		address;
  string		city;
  string		department;
  string		firstName;
  float			hourlyRate;
  string		lastName;
  int			nbrDependents;
  string		SSN;
  string		state;
  string		ZIPCode;
  bool			forever = true;

	while(forever){

	cout << "\nThis program creates an employee record.\n\n";

cout << "Enter first name: ";
cin >> firstName;
cout << "Enter last name: ";
cin >> lastName;
cout << "Enter street address: ";
cin >> address;
cout << "Enter city: ";
cin >> city;
cout << "Enter state code: ";
cin >> state;
cout << "Enter ZIP Code: ";
cin >> ZIPCode;
cout << "Enter SSN: ";
cin >> SSN;
cout << "Enter department: ";
cin >> department;
cout << "Enter hourly rate: ";
cin >> hourlyRate;
cout << "Enter number of dependents: ";
cin >> nbrDependents;

	}//end while
}//end main