//
//  CSV_Schedule.cpp
//  VIsualEx
//
//  Created by ST on 10/16/14.
//  Copyright (c) 2014 ST. All rights reserved.
//

#include "CSV_Schedule.h"

Schedule::Schedule(){}; // constructor


//void Schedule::readSchedule(){
    
    
    
//}


vector<string> Schedule::parseCSVfile(fstream FileIn){
    
    
    // represent dataset as two dimensional array to be read into
    vector<vector<string>> record(17, vector<string>(3)); // 12x4 record
    vector<string> fileparsed; // parsed data to
    
    while (FileIn)
    {
        FileIn.seekg(0, FileIn.end);
        long flength = FileIn.tellg();
        FileIn.seekg(0, FileIn.beg);
        
        char *buffer = new char[3000];
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
    cout<<"Parse Derived"<<endl;
    
    
    return fileparsed;
    
}


vector<vector<string>> Schedule::fileMod(vector<string> ParsedData){
    
    vector<vector<string>> record(17, vector<string>(3));
    // Read data into array
    
    unsigned int i = 0;
    int row, col; // used to traverse
    for(row = 0; row < 17; row++)
        for(col =0; col<4; col++){
            record[row][col] = ParsedData[i];
            i++;
        } // end for read data for loop
    
    

vector<vector<string>> record2(17, vector<string>(3)); // 17x4 record to copy original file into and write to
    
    
    for( int rowcout= 0; rowcout<17; rowcout++){ // start below header
        for(int colcout = 0; colcout<4; colcout++)
        if(rowcout != 16)
        {
            record2[rowcout][colcout] = record[rowcout+1][colcout];
        }
    }
    cout<<"filemod Derived"<<endl;
    
    return record2;
    
}


void Schedule::writetofile(vector<vector<string>> modFile){
    
    ofstream outputfile;
    outputfile.open(OutgoingFile.c_str());
    int rows, cols;
    for(rows = 0; rows< 17; rows++){
        for(cols=0; cols<4; cols++){
            outputfile << modFile[rows][cols]<<",";
           // if(rows == 0 && cols ==3){
             //   outputfile<<"\n";
            //}
            
        } // end for read data for loop
        
        if(4 == cols){
            outputfile<<"\n";
        }
    }
    
    cout<<"Close derived"<<endl;
    outputfile.close();
    
}

