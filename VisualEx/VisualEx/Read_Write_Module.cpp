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
   
    FileIn.open(IncomingFile.c_str()); // open edited main user stat file * when IncomingFile is a pointer this turns into ->, why?
    
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


vector<string> RWModule::parseCSVfile(fstream FileIn){
    
    
    // represent dataset as two dimensional array to be read into
    vector<vector<string>> record(12, vector<string>(5)); // 12x5 record
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
    cout<<"Parse"<<endl;
    
    
return fileparsed;

}


vector<vector<string>> RWModule::fileMod(vector<string> ParsedData){
  
    vector<vector<string>> record(12, vector<string>(5));
    // Read data into array
    
    for(int x =0 ; x < 300; x++)
    {
        cout << ParsedData[x] << endl;;
    }
    
    unsigned int i = 0;
    int row, col; // used to traverse
    for(row = 0; row < 12; row++)
        for(col =0; col<5; col++){
            record[row][col] = ParsedData[i];
            i++;
        } // end for read data for loop
    
    /*
    for(int row = 0; row < 12; row++)
        for(int col =0; col<5; col++){
            cout<< record[row][col]<<"\n";
        } // end for read data for loop
    */
    
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
    cout<<"filemod"<<endl;
   
    


    
     return record2;
    
}


void RWModule::writetofile(vector<vector<string>> modFile){

ofstream outputfile;
outputfile.open(OutgoingFile.c_str());
int rows, cols;
for(rows = 0; rows< 12; rows++){
    for(cols=0; cols<5; cols++){
        outputfile << modFile[rows][cols]<<",";
        if(rows == 0 && cols ==4){
            outputfile<<"\n";
        }
        
        } // end for read data for loop
        
        if(5 == cols && 0 != rows ){
            outputfile<<"\n";
        }
        }
        
    cout<<"Close"<<endl;
        outputfile.close();

}