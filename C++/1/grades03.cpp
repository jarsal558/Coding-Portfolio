//grades03.cpp
//
//This program determines the
//average of a set of grades
//prompting for the grade
//values
//
//Author: Jared Salvatore
//Date:   January 18, 2011
//
//

#include <iostream>

using namespace std;

void	main(void){

	float		average;
	int		grade01;
	int		grade02;
	int		grade03;
	int		total;

	//
	//magic formula
	//

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout<<"Enter grade 01: ";
	cin>>grade01;
	cout<<"Enter grade 02: ";
	cin>>grade02;
	cout<<"Enter grade 03: ";
	cin>>grade03;
	cout<<"\n";

	total = grade01 + grade02 + grade03;

	average = total / 3.0;

	cout<<"The average grade: ";
	cout<<average;

}//end main