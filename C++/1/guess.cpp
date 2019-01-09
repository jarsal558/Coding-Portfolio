#include <ctime>
#include <iostream>
#include <string>

using namespace std;

//
//Function prototype
//

string	msgsCorrect(void);
string	msgsIncorrect(void);
int	randInt(int,int);

void	main(void){

	int		guess;
	int		pick;
	bool	forever = true;
	bool	isCorrect;

	srand(time(0));

	while(forever){
		cout << "Guess a number from 1 to 25.\n\n";
		pick = randInt(1,25);

		isCorrect = false;
		while(!isCorrect){
			cout << "Pick a number: ";
			cin  >> guess;
			if(pick == guess){
				cout << msgsCorrect() 
				     << "\n";
				isCorrect = true;
			}//end if
			else {
				cout << msgsIncorrect() 
				     << "\n";
			}//end else
			if(guess < pick)
				cout << "Too low...\n";
			else
				cout << "Too high...\n";
		}//end while

	}//end while

}//end main

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
	}while(index == prevIndex);
	prevIndex = index;

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