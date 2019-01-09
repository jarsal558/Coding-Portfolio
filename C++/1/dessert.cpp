
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
//Function main
//

void	main(void) {

	ifstream	fileIn;
	string		dessert;
	int		index = 1;
	
	fileIn.open("dessertsAll.txt");

	if(fileIn.fail()) {
		cout << "\nThe file did not open.\n";

		}//end if

	while(getline(fileIn,dessert)) {
		cout << "Dessert "
		     << setw(2)
		     << setfill('0')
		     << index
		     << ": "
		     << dessert
		     << "\n";

		if((index % 5) == 0)
			cout << "\n";

		index = index + 1;

		}//end while

	getline(fileIn,dessert);

	fileIn.close();

	return;

}//end main
