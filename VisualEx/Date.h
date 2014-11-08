/*
 * Date.h
 *
 *  Created on: Oct 27, 2014
 *      Author: spartans
 */

#ifndef DATE_H_
#define DATE_H_

#include <stdio.h>
#include <iostream>
using namespace std;


struct Date{
	int month; // (1-12)
	int day;  //
	int year;
};

struct month{
	int name;
	int maxday;
};

struct node{
	month data; //data type is going to be struct month
	struct node* next;
};

class date{
    
public:
Date currentDate; // create an instance of the struct
void setList(node* &header);
void getday(node* &header);
void getmonth();
void getyear();
void increment(node* &header);
void displaydateline();
void populatemonths();
void printDate();
    
};





#endif /* DATE_H_ */
