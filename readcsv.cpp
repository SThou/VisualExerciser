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
#include <string>
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

bool isInt(char* str) //check to see whether tokenptr is an int or not
{
string emptystr = " ";
string firstchar;
string tempstr;
string newstr;
char temp[20];

tempstr = str;
firstchar = tempstr.at(0);

//check to see if tokenptr first char is a space, weird chars :(
if(firstchar == emptystr)
{
    for(int i=1; i < strlen(str); i++) //strlen might be a problem
    {
        temp[i] = str[i];
    }
    newstr = temp;
}
else
    newstr = str;
cout << newstr  << endl; //outputting newstr, getting weird chars

if (newstr.empty() || (!isdigit(newstr[0])))
    return false;

char *retptr;
strtol(newstr.c_str(), &retptr, 10); //function to convert a cstring to an integer form
//in this manner, if retptr is zero after running this function, the input string is not an integer value
return (*retptr==0);
}

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

	 while (tokenptr != NULL)
	 {
	       cout << tokenptr << endl;
	     /*if(strcmp(tokenptr, " biceps") == 0) //have to use strcmp because normal == will just compare the pointer values
         {
             cout << "This is the header" << endl;
         }
         */
         // implementing isInt function, obviously still doesnt work
         if(isInt(tokenptr))
            cout <<"This is data" << endl;
            if(!isInt(tokenptr))
            cout <<"This is a header" << endl;
		  ss << tokenptr;
 	 if (x >= 1)
  	 {   ss >> converted;
  	 	  testrecord.exercise[x] = converted;}

 	  x++;
	  tokenptr = strtok(NULL, ","); // next token



	 }
	 int i = 1;
	 while (i<10){
	 cout<<"output: "<<testrecord.exercise[i]<<endl;
	 i++;}



	     }
	     }

