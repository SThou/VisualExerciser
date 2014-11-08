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



void date::setList(node* &header){
	month Jan;
	month Feb;
	month Mar;
	month Apr;
	month May;
	month Jun;
	month Jul;
	month Aug;
	month Sep;
	month Oct;
	month Nov;
	month Dec;

	Jan.name = 1;
	Jan.maxday = 31;

	Feb.name = 2;
	Feb.maxday = 28;

	Mar.name = 3;
	Mar.maxday = 31;

	Apr.name = 4;
	Apr.maxday = 30;

	May.name = 5;
	May.maxday = 31;

	Jun.name = 6;
	Jun.maxday = 30;

	Jul.name = 7;
	Jul.maxday = 31;

	Aug.name = 8;
	Aug.maxday = 31;

	Sep.name = 9;
	Sep.maxday = 30;

	Oct.name = 10;
	Oct.maxday = 31;

	Nov.name = 11;
	Nov.maxday = 30;

	Dec.name = 12;
	Dec.maxday = 31;


	//HK: code for month linked list
	node* current; // for traversal and linking
	node* n;
	//node* header; //global head for  linkedlist
	//node* header; // leave as header for the linkedlist
	n = new node;
	n->data = Jan;
	current = n;
	header = n; // leave as header

	n = new node;
	n->data = Feb;
	current->next = n;
	current = n;

	n = new node;
	n->data = Mar;
	current->next = n;
	current = n;

	n = new node;
	n->data = Apr;
	current->next = n;
	current = n;

	n = new node;
	n->data = May;
	current->next = n;
	current = n;

	n = new node;
	n->data = Jun;
	current->next = n;
	current = n;

	n = new node;
	n->data = Jul;
	current->next = n;
	current = n;

	n = new node;
	n->data = Aug;
	current->next = n;
	current = n;

	n = new node;
	n->data = Sep;
	current->next = n;
	current = n;

	n = new node;
	n->data = Oct;
	current->next = n;
	current = n;

	n = new node;
	n->data = Nov;
	current->next = n;
	current = n;

	n = new node;
	n->data = Dec;
	current->next = n;
	n->next = NULL; //end of the list

	//return header;

}
//HK: edited getmonth for error handling
	void date::getmonth(){
		bool inRange = false;
		while (inRange == false)
		{
		cout << "Enter in the month" << endl;
		cin >> currentDate.month;
		if(currentDate.month > 12 || currentDate.month < 1)
		{
			cout << "Month is out of range, please enter again (1-12)" << endl;
		}
		else
			inRange = true;
		}
	}

//HK: Edited getday for error handling
	void date::getday(node* &header){
		node* current;
		current = header;
		bool inRange = false;
		while(inRange == false)
		{
		cout << "Enter in the day" << endl;
		cin >> currentDate.day;
		for(int i = 0; i < 12; i++)
		{
		if(currentDate.month == current->data.name)
		{
			//leap year exception
			if (currentDate.month == 2 && (currentDate.year % 4) == 0 && currentDate.day == current->data.maxday + 1)
			{
			inRange = true;
			break;
			}
			if(currentDate.day > current->data.maxday || currentDate.day < 1)
			{
				cout << "You have entered an invalid day for this month , please try again" << endl;
				break;
			}
			else
			{
				inRange = true;
				break;
			}
		}
		else
			current = current->next;
		}

		}
	}


	void date::getyear(){
		cout << "Enter in the year" << endl;
		cin >> currentDate.year;
	}


	void date::displaydateline(){
		cout << currentDate.month << "/" << currentDate.day << "/" << currentDate.year << endl;
	}

//HK:Finished increment function
	void date::increment(node* &header){ // increment the day (by this amount( day) )

		// match the month to an existing month value in database
				node* current;
				current = header; //setting the current node to beginning of linkedlist
				bool done = false;

				while (done == false){

					for (int i = 0; i < 12; i++){
						//month check
						if (currentDate.month == current->data.name)
						{
							cout << "Month has matched at: " << currentDate.month << endl;
							//checking year change
							if (currentDate.month == 12 && currentDate.day == current->data.maxday)
							{
								currentDate.month = 1;
								currentDate.day = 1;
								currentDate.year++;
								break;
							}
							//checking february leap year
							if (currentDate.month == 2 && (currentDate.year % 4) == 0 && currentDate.day == current->data.maxday)
							{
								currentDate.day++;
								break;
							}
							// checking last possible day of leap year
							if (currentDate.month == 2 && (currentDate.year % 4) == 0 && currentDate.day == current->data.maxday + 1)
							{
								currentDate.month++;
								currentDate.day = 1;
								break;
							}
							//checking day is not maxday of the month
							if (currentDate.day < current->data.maxday)
							{
								currentDate.day++;
								break;
							}
							//checking day is maxday of the month
							if (currentDate.day == current->data.maxday)
							{
								currentDate.month++;
								currentDate.day = 1;
								break;
							}
							break;
						}
						else
						{
							cout << "Current iteration at: " << current->data.name << endl;
						}

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

						*/

						current = current->next;

					}
					done = true;
				}
			}

	void date::printDate(){	//test function to make sure increment works
		cout << currentDate.month << "/" <<currentDate.day << "/" <<currentDate.year << endl;
	}
