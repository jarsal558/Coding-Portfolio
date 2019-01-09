//
//This program converts a number of seconds
//into days, hours, minutes, and seconds.
//

#include <iostream>

using namespace std;

//
//Function Main
//

void	main(void){
	int seconds;
	bool forever = true;
	int days;
	int hours;
	int minutes;
	
	while(forever){

cout << "\nThis program converts a number of seconds\n"
		 << "into days, hours, minutes, and seconds.\n";

		seconds = 0;
while(seconds < 1 || seconds > 500000){
			cout << "Enter number of seconds: ";
			cin  >> seconds;
		}//end while

	days = seconds / 86400;
	hours = (seconds / 3600) - (days * 24);
	minutes = (seconds / 60) - (days * 1440) - (hours * 60);
	seconds = seconds % 60;
		
			if(days > 0){
				cout << "\tDays: "
					 << days
					 << "\n";
			}//end if

			if(hours > 0){
				cout << "\tHours: "
					 << hours
					 << "\n";
			}//end if

			if(minutes > 0){
				cout << "\tMinutes: "
					 << minutes
					 << "\n";
			}//end if



	}//end while

	return;
}//end main