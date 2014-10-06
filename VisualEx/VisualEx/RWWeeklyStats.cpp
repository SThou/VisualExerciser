//
//  RWWeeklyStats.cpp
//  VIsualEx
//
//  Created by ST on 9/10/14.
//  Copyright (c) 2014 ST. All rights reserved.
//  Description: this will take the userstat filled out by user in ReadCSV.CPP
//               and log data to a weekly file used for calculation on stats.
//               User press log data will write data to the ReadCSV.CPP

#include "RWWeeklyStats.h"
#include <vector>

using namespace std;

void transStats(){
    
    fstream FileIn;
    FileIn.open("MainStatsFile.csv"); // open edited main user stat file
    
    if (!FileIn)
    { cerr << " File Could Not Open" ;
        exit(1);
    }
    
    
    // represent dataset as two dimensional array to be read into
    vector<vector<string>> record(12, vector<string>(5)); // 12x5 record
    vector<string> fileparsed; // parsed data to
    
    while (FileIn)
    {
        FileIn.seekg(0, FileIn.end);
        long flength = FileIn.tellg();
        FileIn.seekg(0, FileIn.beg);
        
        char *buffer = new char[flength];
        FileIn.read(buffer, flength+1);
        

        char *tokenptr;
        tokenptr = strtok(buffer, ",");
        
       
        int x = 0;
        while (tokenptr != NULL) // parse token and convert data into strings
        {
      
            if(x >= 0)
            {
                fileparsed.push_back(tokenptr);
            }
            x++;
            
            tokenptr = strtok(NULL, ",\r"); // next token

        } // end while parsing loop
     
    } // end file while loop
    
    
    // Read data into array
    int i = 0;
    int row, col; // used to traverse
    for(row = 0; row < 12; row++)
        for(col =0; col<5; col++){
            record[row][col] = fileparsed[i];
            i++;
        } // end for read data for loop
    

    // write a new heading manually
    vector<vector<string>> record2(12, vector<string>(5)); // 12x5 record to copy original file into and write to
    
    for (int i = 0; i <5 ; i++){
        stringstream appended;
        appended <<"Week"<<i+1;
        string done;
        done = appended.str();
        record2[0][i] = done;
        
    }


    for( int rowcout= 0; rowcout<12; rowcout++){ // start below header
        if(rowcout!=0)
        {
            record2[rowcout][0] = record[rowcout][4]; // move userstat in the fifth column to the begging of the first
        }
    }
    
        
    
    
        ofstream outputfile;
        outputfile.open("WeeklyStats.csv");
        int rows, cols;
        for(rows = 0; rows< 12; rows++){
            for(cols=0; cols<5; cols++){
                outputfile << record2[rows][cols]<<",";
                if(rows == 0 && cols ==4){
                    outputfile<<"\n";
                }
                
            } // end for read data for loop
            
            if(5 == cols && 0 != rows ){
                outputfile<<"\n";
            }
        }
        
        
        outputfile.close();
    
  

} // end function
