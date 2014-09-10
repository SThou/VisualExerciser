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
#include <iomanip> // string printout adjustment

using namespace std;


// functions for reading and writing to data structure
void readdata(string records[][5]){
    int row = 0, col = 0;
    for(row = 0; row < 12; row++)
        for(col = 0; col<5; col++){
            cout<<setw(7)<<records[row][col]<<"|";
   
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
    fstream file("CSVStats.csv");
    
    
    if (!file)
    { cerr << " File Could Not Open" ;
        exit(1);
    }
    
    // represent dataset as two dimensional array to be read into
    string excelrecord[12][5]; // 12x5 record
    int row, col; // used to traverse
    
    
    string fileparsed[200]; // parsed data to
    string datacount;
    

    
    while (file)
    {
        file.seekg(0, file.end);
        long flength = file.tellg();
        file.seekg(0, file.beg);
        
        char *buffer = new char[flength];
        file.read(buffer, flength+1);
        
        // token setup
        char *tokenptr;
        tokenptr = strtok(buffer, ",");
        
        int x = 0;
        while (tokenptr != NULL) // parse token and convert data into strings
        {
                fileparsed[x] = tokenptr;
                x++;
            tokenptr = strtok(NULL, ","); // next token
        } // end while parsing loop
        
    } // end file while loop

    
    
    // Read data into array
    int i = 0;
    for(row = 0; row < 12; row++)
        for(col =0; col<5; col++){
            excelrecord[row][col] = fileparsed[i];
            i++;
        } // end for read data for loop
   
    // print back data
    readdata(excelrecord);
 
 
} // end main


