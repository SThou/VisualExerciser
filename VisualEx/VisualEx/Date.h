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


class date{

typedef struct Date{
	int month; // (1-12)
	int day;  //
	int year;
} Date;

public:
Date currentDate; // create an instance of the struct
void getday();
void getyear();
void displaydateline();
};


#endif /* DATE_H_ */
