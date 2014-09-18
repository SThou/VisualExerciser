//
//  Read_Write_Module.cpp
//  VIsualEx
//
//  Created by ST on 9/17/14.
//  Copyright (c) 2014 ST. All rights reserved.
//

#include "Read_Write_Module.h"

RWModule::RWModule(void){ };
void RWModule::init(string In, string Out)
{
    IncomingFile = In;
    OutgoingFile = Out;
    
    
    
}

fstream RWModule::openfile()
{
    fstream FileIn;
   
    OpenFileLink.open(IncomingFile.c_str()); // open edited main user stat file * when IncomingFile is a pointer this turns into ->, why?
    
    if (!FileIn)
    { cerr << " File Could Not Open\n" ;
        exit(1);
    }
    
    if(FileIn)
    { cerr << "File is open\n"; }
    
    fstream file;
    file = std::move(FileIn); // move copy assignment since we cannot copy or assign fstream object
    return file;
}


string RWModule::parseCSVfile(fstream FileIn, string ParsedData){
    
    string *fileparsed = new string[200]; // parsed data to
    stringstream ss;
    string converted;
    
    while (FileIn)
    {
        FileIn.seekg(0, FileIn.end);
        long flength = FileIn.tellg();
        FileIn.seekg(0, FileIn.beg);
        
        char *buffer = new char[33333];
        FileIn.read(buffer, 33333+1);
        
        // token setup
        char *tokenptr;
        tokenptr = strtok(buffer, ",");
        
        int x = 0;
        while (tokenptr != NULL) // parse token and convert data into strings
        {
            ss << tokenptr;
            if(x >= 1)
            {
                ss >> converted;
                //fileparsed[x] = tokenptr;
                fileparsed[x] = converted;
            }
            x++;
            tokenptr = strtok(NULL, ","); // next token
        } // end while parsing loop
        
    } // end file while loop
    cout<< "Parsed Successfully\n";
    return fileparsed;
}

void RWModule::fileMod(string ParsedData){
    
    // represent dataset as two dimensional array to be read into
    string record[12][5]; // 12x5 record *array init values has to be actual numbers rather than
                         //variables for a string type.
    
    // Read data into array
    int i = 0;
    for(int row = 0; row < 12; row++)
        for(int col =0; col<5; col++){
            record[row][col] = fileparsed[i+1]; //HK: fileparsed[i] would have included the 0(NULL) thats why it was messing up
            i++;
        } // end for read data for loop
    
    
    // write a new heading manually
    
    string record2[12][5]; // 12x5 record to copy original file into and write to
    
    for (int i = 0; i <5 ; i++){
        stringstream appended;
        appended <<"Week"<<i+1;
        string done;
        done = appended.str();
        record2[0][i] = done;
        
    }
    
    //uint32_t x;
    int rowcout; //HK: not using "x" because you declared earlier in program
    for( rowcout= 0; rowcout<12; rowcout++){ // start below header
        if(rowcout!=0)
        {
            cout<<record[rowcout][4]<<endl;
            record2[rowcout][0] = record[rowcout][4]; // move userstat in the fifth column to the begging of the first
        }
    }
    

    
}
