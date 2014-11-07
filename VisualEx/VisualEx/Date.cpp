//============================================================================
// Name        : Date.cpp
// Author      : ST
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Date.h"
using namespace std;


/*
typedef struct Date{
	int month; // (1-12)
	int day;  //
	int year;
} date; // why is struct labeled and called with this and not Date

date Date; // create an instance of the struct
*/
void date::getmonth(){
	cout<<"Enter in the month"<<endl;
	cin>>currentDate.month;
}


void date::getday(){
	cout<<"Enter in the day"<<endl;
	cin>>currentDate.day;
}


void date::getyear(){
	cout<<"Enter in the year"<<endl;
	cin>>currentDate.year;
}


void date::displaydateline(){
	cout<<currentDate.month<<"/"<<currentDate.day<<"/"<<currentDate.year<<endl;
}

/*

void date:: increment(int days, int month, int year){ // increment the day (by this amount( day) )

		// match the month to an existing month value in database
/*
		for loop:  // handle the days and month
			if ( passed month = month in list)
				if (current day < max day in month list )
					increment day
				if (current day = 31 and month = december)
					increment year
				if (current day = max day in month list)
					increment month
				if (current day = 29 && month == feb )
					increment month
					// catch the leap year
				if (current day < max day in feb (28) && month is feb && year is multiple of 4)
					increment day // feb 29





}
*/

