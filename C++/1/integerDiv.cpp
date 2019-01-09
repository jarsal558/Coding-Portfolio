// integerDiv.cpp
//
//This Program will perform integer division.
//The user will be prompted for both
//a numerator and a denomenator.
//
#include <iostream>

using namespace std;

//
//Function Main
//

void	main(void){
	int denomenator;
	bool forever = true;
	int numerator;
	int remainder;
	int result;

cout << "This Program will perform integer division.\n"
	 << "The user will be prompted for both\n"
	 << "a numerator and a denomenator.\n";

while(forever){

	cout << "Enter a numerator as an integer: ";
	cin >> numerator;

	cout << "Enter a denomenator as an integer: ";
	cin >> denomenator;

	result = numerator / denomenator;
	remainder = numerator % denomenator;

	cout << "\n  "
		 << numerator
		 << " / "
		 << denomenator
		 << " = "
		 << result
		 << ", remainder of "
		 << remainder
		 << "\n";
}//end while
	return;
}//end main