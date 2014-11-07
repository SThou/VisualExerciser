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
    
typedef struct month{
    int name;
    int maxday;
    } month;

    
typedef struct node{
month data; //data type is going to be struct month
struct node* next;
    }node;
    
public:
Date currentDate; // create an instance of the struct
    month *Jan;
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
void getday();
void getmonth();
void getyear();
void displaydateline();
void increment();
void populatemonths();
    
};





#endif /* DATE_H_ */
