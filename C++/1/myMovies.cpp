
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
	string		title;
	int		index = 0;
	
	fileIn.open("myMovies.txt");

	if(fileIn.fail()) {
		cout << "\nThe file did not open.\n";

		}//end if

	while(getline(fileIn,title)) {
		cout << "Title "
		     << setw(2)
		     << setfill('0')
		     << index
		     << ": "
		     << title
		     << "\n";

		index = index + 1;

		}//end while

	getline(fileIn,title);

	fileIn.close();

	return;

}//end main