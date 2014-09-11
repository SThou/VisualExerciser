//============================================================================
// Name        : VisualExPC.cpp
// Author      : ST
// Version     :
// Copyright   :
// Description : This is the main file to read the start CSV file and write user input to the CSV file.
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


// functions for reading data structure to console
void readdata(string records[][5]){
    int row = 0, col = 0;
    for(row = 0; row < 12; row++)
        for(col = 0; col<5; col++){
            cout<<setw(7)<<records[row][col]<<"|";
   
        }
    cout << endl;
}

//void UserStatsAdjustment(string records[][5], inputcol, inputrow) // will have to be adjusted depending on interface method
void UserStatsAdjustment(string records[][5]){ //A user selects a specific row & col to input values
    
        string input;
        int inputcol = 4; // only user can adjust user stats
        int inputrow; // limited to row 1+
        char exit = 0; // exit value
    
    
        while(exit != 'N')
        {
          
        cout << "Enter in row ";
        cin >> inputrow;
    

        if(0 == inputrow ){
        cout<< "This row cannot be selected" <<endl;
        cout<< "Enter in a new row" << endl;
            cin >>inputrow;
            } // end if
    
        cout<< "Enter in user stat" <<endl;
        cin >> input;
    
        records[inputrow][inputcol] = input;
        
        cout<< "Enter another( Y )  or exit (N)?"<<endl;
        cin>>exit;
            
        }
    
    
}

void writetofile(string records[][5]){
    ofstream outputfile;
    outputfile.open("outputfile.csv");
    int row, col;
    for(row = 0; row < 12; row++){
        for(col=0; col<5; col++){
            outputfile << records[row][col]<<",";
        } // end for read data for loop
       
        if(5 == col && 0 != row ){
        outputfile<<"\n";
        }
    }
    
    
    outputfile.close();
    
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
    UserStatsAdjustment(excelrecord); // write to initial file
    
    
    
    // write a new heading manually
    
    for (int i = 0; i <5 ; i++){
        stringstream appended;
        appended <<"Week"<<i+1;
        string done;
        done = appended.str();
        excelrecord[0][i] = done;
        
    }
    
    
    for(int x = 1; x<12; x++){ // start below header
        for(int y = 0; y<4; y++){ // clear all other data
            if(y == 0){
                excelrecord[row][y] = excelrecord[row][5];} // move userstat in the fifth column to the begging of the first
            else excelrecord[x][y] = " " ;
            }
            
            
        
        
        
        
    }
    
    
    readdata(excelrecord);
    
    
    
    writetofile(excelrecord); // write to v1 of the stats file.
  //  cout<<excelrecord[0][5];

    
    
} // end main








