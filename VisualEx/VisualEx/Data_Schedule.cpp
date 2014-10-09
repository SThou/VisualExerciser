//
//  Data_Schedule.cpp
//  VIsualEx
//
//  Created by ST on 10/8/14.
//  Copyright (c) 2014 ST. All rights reserved.
//

#include "Data_Schedule.h"



vector<vector<string>> stats_Schedule::fileMod(vector<string> ParsedData){
    vector<vector<string>> record(18, vector<string>(7));
    // Read data into array
    
    for(int x =0 ; x < 300; x++)
    {
        cout << ParsedData[x] << endl;;
    }
    
    unsigned int i = 0;
    int row, col; // used to traverse
    for(row = 0; row < 18; row++)
        for(col =0; col<5; col++){
            record[row][col] = ParsedData[i];
            i++;
        } // end for read data for loop
    
    
    // write a new heading manually
    vector<vector<string>> record2(18, vector<string>(7)); // 12x5 record to copy original file into and write to
    
    
    vector<string>usrDataHeading(7);
    usrDataHeading[0] = "Date";
    usrDataHeading[1] = "DayOfWeek";
    usrDataHeading[2] = "Exercise";
    usrDataHeading[3] = "Set";
    usrDataHeading[4] = "Rep";
    usrDataHeading[5] = "Weight";
    usrDataHeading[6] = "Completed";

    
    
    for (int i = 0; i <7 ; i++){
        stringstream appended;
        appended <<usrDataHeading[i];
        string done;
        done = appended.str();
        record2[0][i] = done;
        
    }
    
    
    for( int rowcout= 0; rowcout<18; rowcout++){ // start below header
        if(rowcout!=0)
        {
            record2[rowcout][0] = record[rowcout][4]; // move userstat in the fifth column to the begging of the first
        }
    }
    cout<<"filemod"<<endl;
    

    return record2;

    
    
}