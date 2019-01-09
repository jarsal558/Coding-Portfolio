//
// Including libraries and header files
//

#include <cctype>
#include <climits>
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
//Function prototypes
//

int	binToInt(string);
string	binaryNbr;

//
//Function binToInt
//

int	binToInt(string binaryNbr) {

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

}//end bitToInt

//
//Function main
//

void	main(void) {

	int	valueInt;
	string	binaryNbr;

	cout << "Type in a number: ";
	cin  >> binaryNbr;
	cout << "\n";

	valueInt = binToInt(binaryNbr);
		cout << "This value is: "
	  	   << valueInt
	  	   << "\n";


	return;

}//end main