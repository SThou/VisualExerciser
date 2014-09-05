//============================================================================
// Name        : VisualExPC.cpp
// Author      : ST
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdlib> // for exit functions
#include <iostream>
#include <fstream> // stream class to both read and write from/to files
#include <cstring>
#include <cstdio>
#include <stdio.h>
#include <sstream>

using namespace std;

/*record of one weight*/

struct record{

	//char userweighthead[14] = "user weight"; // heading for user weight
	string userweight;
	string exercise[30]; // individual exercise
	char malenationalstats;
};


int main(void)
{

stringstream ss;
string converted;
fstream file("CSVStats.csv");

 if (!file)
 { cerr << " File Could Not Open" ;
   exit(1);
 }



struct record testrecord; // make a blank struct


	    while (file)
	     {


	     file.seekg(0, file.end);
	     file.seekg(0, file.beg);

	     char *buffer = new char[328328];
	     file.read(buffer, 328328);


	     // token test
	     char *tokenptr;
	     tokenptr = strtok(buffer, ",");
	     int x = 0;
	     char converted[200];
	     char key[] = "Squat";
	     char key2[] = "100";
	 while (tokenptr != NULL)
	 {
		  ss << tokenptr;
 	 if (x >= 1)

		{   ss >> converted;
			if( strcmp(key, converted) == 0){
  	 	  testrecord.exercise[x] = converted;}
		}

 	  x++;
	  tokenptr = strtok(NULL, ","); // next token



	 }
	 int i = 1;
	 while (i<10){
	 cout<<"output: "<<testrecord.exercise[i]<<endl;
	 i++;}



	     }
	     }

