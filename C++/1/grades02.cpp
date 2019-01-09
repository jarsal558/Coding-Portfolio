//grades02.cpp
//
//This program determines the
//average of a set of grades
//with a fixed decimal point.
//
//Author: Jared Salvatore
//Date: January 18, 2011
//
//

#include <iostream>

using namespace std;

void	main(void){

	float	average;
	  int	 grade01;
	  int	 grade02;
	  int	 grade03;
	  int	 total;

//
// magic formula
//

cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);

	grade01 = 92;
	grade02 = 73;
	grade03 = 84;

	total = grade01 + grade02 + grade03;

	average = total / 3.0;

cout << "The average grade: ";
cout << average;

	return;

} // end main
