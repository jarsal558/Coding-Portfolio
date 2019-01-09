//
//This program sorts two integer
//values into ascending order.
//

#include <iostream>

using namespace std;

void	main(void){

	bool forever = true;
	int holder;
	int value01;
	int value02;

cout << "This program sorts two integer\n"
	 << "values into ascending order.\n\n";

	 while(forever){

		 cout << "Enter Value 1: ";
		 cin >> value01;

		 cout << "Enter Value 2: ";
		 cin >> value02;
		 cout << "\n";

			  if(value01 > value02){
				  holder = value01;
				  value01 = value02;
				  value02 = holder;
			cout << "The values were swapped.\n";
			  }//end if

cout << "Value 1 is: "
	 << value01
	 << "\nValue 2 is: "
	 << value02
	 << "\n\n";
	 }//end while

	 return;

			  }//end while