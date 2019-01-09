#include <iostream>

using namespace std;

void	main(void){
	int difference;
	bool forever = true;
	int myAge;
	int yourAge;

cout << "This program calculates the\n"
     << "difference between our ages.\n";

	while(forever){
		myAge = 0;

		while(myAge < 1 || myAge > 110){
		cout << "Enter my age: ";
		cin >> myAge;

		}//end while
		yourAge = 0;

		while(yourAge < 1 || yourAge > 110){
		cout << "Enter your age: ";
		cin >> yourAge;

		}//end while
		difference = myAge - yourAge;
	
	if (difference > 0){
		cout << "I am older by "
			 << difference
			 << " years.\n";
	}//end if
	else if (difference < 0){
		difference = difference * -1;
		cout << "You are older by "
			 << difference
			 << " years.\n";
	}//end else if
	else {
		cout << "We are the same age.\n";
	}//end else
	}//end while
	}//end main