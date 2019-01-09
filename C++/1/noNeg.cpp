//
//This program prompts for two positive
//integer values and displays the product
//of them
//
//Author: Jared Salvatore
//Date: 3-7-11
//

#include <iostream>
#include <string>

using namespace std;

//
//Function prototypes
//

bool continueYesNo(void);
void displayInstructions(void);
int  randInt(int,int);

//
// Function continueYesNo
//

bool	continueYesNo(void) {

	bool	answer;
	bool	forever = true;
	string	yesNo;

	cout	<< "\n";

	while (forever) {

		cout << "Continue? (Yes/No): ";
		cin  >> yesNo;
	
		yesNo = yesNo.substr(0,1);

		if (yesNo == "Y" || 
		    yesNo == "y") {

			answer = true;
			break;

		}

		else if (yesNo == "N" ||
		         yesNo == "n") {

			answer = false;
			break;

		} // end if

	} // end while

	cout << "\n";
	return answer;

}// end continueYesNo

//
//Function displayInstructions
//

void	displayInstructions(void) {

	cout << "This program prompts for two positive\n";
	cout << "integer values and displays the product\n";
	cout << "of them.\n\n";
	cout << "Negative numbers are ignored. Three negative\n";
	cout << "integers in a row ends a cycle.\n";

}//end displayInstructions

//
//Function main
//

void	main(void) {
	int	countNeg;
	bool	haveValue;
	int	product;
	int	value01;
	int	value02;

	do {

	displayInstructions();

	countNeg = 0;
	haveValue = false;
	while(!haveValue&&(countNeg < 3)){
		value01 = randInt(-9,9)

		cout << "Enter Number: "
		     << value01
		     << "\n";
		cout << "Enter Number: "
		     << value02
		     << "\n"


	if (value01 > 0)
		haveValue = true;
	else
		countNeg = countNeg + 1;
	)//end while

if(countNeg < 3) {
	countNeg = 0;
	haveValue = false;
}//end if

while(!haveValue&&(countNeg < 3)){
		value02 = randInt(-9,9)

		cout << "Enter Number: "
		     << value02
		     << "\n"

	if (value02 > 0)
		haveValue = true;
	else
		countNeg = countNeg + 1;
	)//end while

if(countNeg >= 3){

	cout << "Cycle ended.";
	continue;
}//end if

else {
	product = value01 * value02;
	cout << "Product is: "
	     << product;
}//end else

}//end while

return;

}//end main
