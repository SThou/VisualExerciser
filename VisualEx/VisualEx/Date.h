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




typedef struct month{
int name;
int maxday;
}month;

typedef struct node{
month data; //data type is going to be struct month
node* next;
}node;

void populatemonths()
{
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
node* header; // leave as header for the linkedlist
n = new node;
n->data = Jan;
current = n;
header = n; // leave as header

n = new node;
n->data = Feb;
current->next = n;

n = new node;
n->data = Mar;
current->next = n;

n = new node;
n->data = Apr;
current->next = n;

n = new node;
n->data = May;
current->next = n;

n = new node;
n->data = Jun;
current->next = n;

n = new node;
n->data = Jul;
current->next = n;

n = new node;
n->data = Aug;
current->next = n;

n = new node;
n->data = Sep;
current->next = n;

n = new node;
n->data = Oct;
current->next = n;

n = new node;
n->data = Nov;
current->next = n;

n = new node;
n->data = Dec;
current->next = n;
n->next = NULL; //end of the list
}

class date{

typedef struct Date{
	int month; // (1-12)
	int day;  //
	int year;
} Date;

public:
Date currentDate; // create an instance of the struct
void getday();
void getmonth();
void getyear();
void displaydateline();
};









#endif /* DATE_H_ */
