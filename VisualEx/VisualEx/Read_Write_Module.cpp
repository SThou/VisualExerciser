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
    file = std::move(FileIn);
    return file;
}


void RWModule::parseCSVfile(fstream FileIn){
    
    string fileparsed[200]; // parsed data to
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
    cout<< "success";
}
