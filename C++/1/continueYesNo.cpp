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

} // end continueYesNo