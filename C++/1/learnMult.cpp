//
// This program helps elementary school
// students learn multiplication.
//
// Author: Jared Salvatore
// Date:   February 10, 2011
//

#include <ctime>
#include <iostream>
#include <string>

using namespace std;

//
// Function prototypes
//

string	msgsCorrect(void);
string	msgsIncorrect(void);
int		randInt(int, int);

//
// Function main
//

void	main(void) {

	bool	isCorrect;
	int		factor01;
	int		factor02;
	bool	forever = true;
	int		guess;
	static
	int		prevFactor01 = -1;
	static
	int		prevFactor02 = -1;
	int		product;

	//
	// Seeding the random number generator
	//

	srand(time(0));

	cout << "\nThis program helps elementary school\n"
		 << "students learn multiplication.\n\n";

	while(forever) {

		do{

		factor01 = randInt(1, 9);
		factor02 = randInt(1, 9);
		}while (((factor01 = prevFactor01)&&(factor02 == prevFactor02)) || ((factor01 = prevFactor02) && (factor02 == prevFactor01)));
		
		prevFactor01 = factor01;
		prevFactor02 = factor02;
		product = factor01 * factor02;

		isCorrect = false;

		while(!isCorrect){

			cout << "How much is "
				 << factor01
				 << " times "
				 << factor02
				 << " ? ";
			cin >> guess;

			if(product == guess){
				cout << msgsCorrect()
					 << "\n";
				isCorrect = true;
			}//end if

		else {
			cout << msgsIncorrect()
				 << "\n";


		} // end else

		cout << "\n\n";


		}//end while
	} // end while

	return;

} // end main

//
// Function msgsCorrect
//

string	msgsCorrect(void) {
		
	int		index;
	string	messages[10];
	static 
	int		 prevIndex = -1;

	do{
		index = randInt(0,9);
	}while(index==prevIndex);

	messages[0] = "Correct!";
	messages[1] = "Doing great.";
	messages[2] = "Excellent...";
	messages[3] = "Good work...";
	messages[4] = "Not too shabby...";
	messages[5] = "That's right.";
	messages[6] = "Very good!";
	messages[7] = "Yes, that's right.";
	messages[8] = "Yes...";
	messages[9] = "You're beautiful, kid!";

	index = randInt(0,9);
	while(index == prevIndex);
	prevIndex = index;

	return messages[index];

}// end msgsCorrect

//
// Function msgsIncorrect
//

string	msgsIncorrect(void) {
		
	int		index;
	string	messages[8];
	static
	int		prevIndex;

	messages[0] = "FAILure of EPIC proportions... Epic Fail...";
	messages[1] = "Not quite...";
	messages[2] = "Give it another try.";
	messages[3] = "Incorrect, try again.";
	messages[4] = "No, keep trying.";
	messages[5] = "Not too good.";
	messages[6] = "Sorry, it's not right.";
	messages[7] = "Sorry...";

	index = randInt(0, 7);
	while(index == prevIndex);
	prevIndex = index;

	return messages[index];

} // end msgsIncorrect

//
// Function randInt
//

int		randInt(int loBound, int hiBound) {

	int intervalSize;
	int randomOffset;
	int value;

	intervalSize = (hiBound - loBound) + 1;

	randomOffset = rand() % intervalSize;
	value = loBound + randomOffset;

	return value;

} // end randInt



