//
//  Read_Write_Module.h
//  VIsualEx
//
//  Created by ST on 9/17/14.
//  Copyright (c) 2014 ST. All rights reserved.
//  Description, this is the base class for all read / write operations

#ifndef __VIsualEx__Read_Write_Module__
#define __VIsualEx__Read_Write_Module__

#include <iostream>
#include <fstream> // stream class to both read and write from/to files
#include <string>
#include <sstream>
using namespace std;

#endif /* defined(__VIsualEx__Read_Write_Module__) */


class RWModule {

    public:
    string IncomingFile; // file to be opened and read
    string OutgoingFile; // modified and written to file
    fstream OpenFileLink;
    
    public: // File operations
    
     RWModule(); // constructor
    ~RWModule() {} // destructor
    
    
    void init(string In, string Out); // setup file names
    
    fstream openfile(); // open incoming file to be worked on, includes closing file
    void parseCSVfile(fstream FileIn); // the parsing of a CSV file
    void fileMod(); // modification for specific file types to be modified.
                    // Default is read / write from Mainstats to RW WeeklyStats
    void writetofile(); // copy the data structure into a written CSV file
    
    
   
};
