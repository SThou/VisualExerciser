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

//double readdata(string *excelrecordptr);

// functions for reading and writing to data structure
void readdata(string records[][5], int column){
    int colcount = column; //set to num columns in csv file
    int row, col;
    for(row = 0; row < 12; row++)
        for(col = 0; col<5; col++){
            cout<<records[row][col] << " ";
            colcount--;
            if(colcount == 0)
            {
                cout << endl;
                colcount = column; //set to number of columns in csv file
            }
        }
        cout << endl;
}


//record of one weight
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
fstream filecomma("CSVStats.csv"); //didnt know how to use the same filestream again lol
fstream filerow("CSVStats.csv"); // " "
fstream file("CSVStats.csv");

 if (!file)
 { cerr << " File Could Not Open" ;
   exit(1);
 }
 if (!filecomma)
 {
     cerr << " File Coult Not Open" ;
     exit(1);
 }
 if (!filerow)
 {
     cerr << " File Coult Not Open" ;
     exit(1);
 }

// represent dataset as two dimensional array to be read into
    string excelrecord[12][5]; // 12x5 record
    int row, col; // used to traverse


    string fileparsed[200]; // parsed data to
    int commacount = 0;
    int rowcount = 0;
    int columncount;
    string datacount;


//HK: counting number of rows and columns
string line; //arbitrary, just need for getline
string token; //separate string for nested getline
	while (getline(filecomma,line))
	{
		stringstream s(line);
		while (getline(s,token,','))
		{
			commacount++;
		}
	}

	while (getline(filerow,line))
	{
		stringstream s(line);
		while (getline(s,token,'\n'))
		{
			rowcount++;
		}
	}

	    while (file)
	     {
	     file.seekg(0, file.end);
	     int flength = file.tellg(); //HK: determine exact size of file
	     file.seekg(0, file.beg);

	    //char *buffer = new char[328328];
	     //file.read(buffer, 328328);

	     char *buffer = new char[flength]; //HK: using actual file size for the buffer
	     file.read(buffer, flength);

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
	 } // end while parsing loop

	     } // end file while loop

// HK: calculation to get the number of columns
columncount = commacount/rowcount;


    // Read data into array
    int i = 1;
    for(row = 0; row < 12; row++)
        for(col =0; col<5; col++){
            excelrecord[row][col] = fileparsed[i];
            i++;
        } // end for read data for loop
          readdata(excelrecord,columncount);

} // end main





