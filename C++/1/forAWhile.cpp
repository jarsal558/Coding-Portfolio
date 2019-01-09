//
//This program compares
//while loops to for loops
//
//Author: Jared Salvatore
//Date: February 22, 2011
//

#include <iostream>
#include <string>

using namespace std;

void	main(void) {
	int	count;
	bool	forever = true;
	int	loBound;
	int	hiBound;
	
	cout << "Enter a loBound: ";
	cin  >> loBound;

	cout << "Enter a hiBound: ";
	cin  >> hiBound;
	
	count = loBound;
	cout << "Before for loop.\n";
	for(count = loBound; count<= hiBound; count ++)
	cout << "Inside loop: "
	     << count
	     << "\n";
}//end for
	cout << "After for loop.\n";

cout << "After-while loop.\n";

}//end main





//while loop
	cout<< "Before while loop.\n";
	while(count <= hiBound) {
		cout << "Inside loop: "
		     << count
		     << "\n";
		count = count + 1;
		}//end while

cout << "After-while loop.\n";