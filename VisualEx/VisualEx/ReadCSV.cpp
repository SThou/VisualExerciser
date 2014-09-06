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

	string userweighthead; // heading for user weight
	string userweight;
	string exercise[30]; // individual exercise
	char malenationalstats;
};


int main(void)
{

    
    
// Begin reading data from file to parsing to data structure
stringstream ss;
string converted;
fstream file("CSVStats.csv");

 if (!file)
 { cerr << " File Could Not Open" ;
   exit(1);
 }

// represent dataset as two dimensional array to be read into
    string excelrecord[12][5]; // 12x5 record
    int row, col; // used to traverse
    
    string fileparsed[200]; // parsed data to


	    while (file)
	     {
	     file.seekg(0, file.end);
	     file.seekg(0, file.beg);

	     char *buffer = new char[328328];
	     file.read(buffer, 328328);


	     // token setup
	     char *tokenptr;
	     tokenptr = strtok(buffer, ",");
	     char converted[200];
	   
         int x = 0;
	 while (tokenptr != NULL) // parse token and convert data into strings
	 {
		  ss << tokenptr;
         if (x >= 1)
		{   ss >> converted;
            fileparsed[x] = converted;
		}
         x++;
         tokenptr = strtok(NULL, ","); // next token
	 }
         
             // Read data into array
             int i = 1;
             for(row = 0; row < 5; row++)
                 for(col =0; col<12; col++){
                     excelrecord[col][row] = fileparsed[i];
                     i++;
                 } // end for loop
             
       
         

            
	     } // end while loop
	     } // end main




// functions for reading and writing to data structure


