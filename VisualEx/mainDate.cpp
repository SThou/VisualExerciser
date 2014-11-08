/*
 * main.cpp
 *
 *  Created on: Nov 7, 2014
 *      Author: spartans
 */


#include <stdio.h>
#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
date currentdate;
node* header;
currentdate.setList(header);
currentdate.getmonth();
currentdate.getyear();
currentdate.getday(header);
cout << "current date is: ";
currentdate.printDate();
currentdate.increment(header);
cout <<"date after incrementing: ";
currentdate.printDate();
}
