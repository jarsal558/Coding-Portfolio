//
// This program
//
// Author: Firstname Lastname
// Date:   Month dd, yyyy
//

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
// Function prototypes
//

//
// User defined global constants
//

//
// Function main
//

void	main(void) {

	//
	// Seeding the random number generator
	//

	srand(time(0));

	//
	// Magic formula
	//

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);

	return;

} // end main