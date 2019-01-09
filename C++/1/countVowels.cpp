#include<ctime>
#include<iostream>
#include<string>

using namespace std;

//
//Function prototypes
//

bool	continueYesNo(void);
int	countVowels(string);
void	displayInstructions(void);
string	getSentence(void);
bool	isVowel(string);
int	randInt(int,int);

//
//Function main
//

void	main(void) {
	int count;
	string sentence;

	displayInstructions();

	do{
	   sentence = getSentence();
	   count = countVowels(sentence);
	   cout << "Sentence is: "
		<< sentence
		<< ".\n\n";
	   cout << "Count of vowels found: "
		<< count
		<< "\n";
	}while(continueYesNo());
	
	return;

}//end main

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
//Function countVowels
//

int	countVowels(string text) {

	int	count = 0;
	int	length = text.length();
	
	for(int i = 0;i < length;i++) {

	if(isVowel(text.substr(i,1)))
		count = count + 1;

		}//end for

	return count;

}//end countVowels

//
//Function isVowel
//

bool	isVowel(string letter) {
	bool vowel = false;

	if(letter == "a"||
	   letter == "e"||
	   letter == "i"||
	   letter == "o"||
	   letter == "u"||
	   letter == "A"||
	   letter == "E"||
	   letter == "I"||
	   letter == "O"||
	   letter == "U")
	vowel = true;

	return vowel;

}//end isVowel

//
//Function getSentence
//

string	getSentence(void) {

	int	index;
	static
	int	prevIndex;
	string	sentences[10];

sentences[0] = "You weren't reading below the bridge.";
sentences[1] = "Were those bartenders eating in London?";
sentences[2] = "I wasn't skiing last Monday.";
sentences[3] = "I was praying in the doghouse.";
sentences[4] = "Cathy was eating near the station.";
sentences[5] = "I have a little pair of pliers.";
sentences[6] = "He has a pen.";
sentences[7] = "This is Meg's clock.";
sentences[8] = "This isn't Alfred's niece's letter.";
sentences[9] = "Bruce doesn't own a new pair of scissors.";

	do{
	   index = randInt(0,9);
	}while(index == prevIndex);
	prevIndex = index;
	return sentences[index];

}//end getSentences

//
//Function displayInstructions
//

void	displayInstructions(void) {

	cout << "This program gets a sentence and\n";
	cout << "determines the number of vowels in\n";
	cout << "each sentence.\n\n";

}//end displayInstructions

//
// Function randInt
//

int randInt(int loBound, int hiBound) {

	int intervalSize;
	int randomOffset;
	int value;

	intervalSize = (hiBound - loBound) + 1;

	randomOffset = rand() % intervalSize;
	value = loBound + randomOffset;

	return value;

} // end randInt