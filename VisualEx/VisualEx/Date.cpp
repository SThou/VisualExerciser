//============================================================================
// Name        : Date.cpp
// Author      : ST
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;



typedef struct Date{
	int month; // (1-12)
	int day;  //
	int year;
	int *test;
} date; // why is struct labeled and called with this and not Date

date Date; // create an instance of the struct

void getmonth(){
	cout<<"Enter in the monthx"<<endl;
	cin>>Date.month;
}


void getday(){
	cout<<"Enter in the day"<<endl;
	cin>>Date.day;
}


void getyear(){
	cout<<"Enter in the year"<<endl;
	cin>>Date.year;
}


void displaydateline(){
	cout<<Date.month<<"/"<<Date.day<<"/"<<Date.year<<"/"<<endl;
}

int main(){

	getmonth();
	getday();
	getyear();
	displaydateline();

}

