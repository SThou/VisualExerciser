//
//  CSV_Schedule.h
//  VIsualEx
//
//  Created by ST on 10/16/14.
//  Copyright (c) 2014 ST. All rights reserved.
//

#ifndef __VIsualEx__CSV_Schedule__
#define __VIsualEx__CSV_Schedule__

#include <stdio.h>
#include "Read_Write_Module.h"

#endif /* defined(__VIsualEx__CSV_Schedule__) */



class Schedule : public RWModule{



public:
    
   Schedule(); // constructor
  ~Schedule() {} // destructor
    
    
    //void dayofweek(); // reads in from CSV_Schedule day of week
   
    
   // void readSchedule(); // reads in the whole schedule
    
    virtual vector<string> parseCSVfile(fstream FileIn); // reads in from CSV_Schedule exercises data
                          // and rep / set data into a 2D array to match rep and set with exercise
    
   virtual vector<vector<string>> fileMod(vector<string> ParsedData); // modification for specific file types to be modified.
   
    virtual void writetofile(vector<vector<string>> modFile ); // copy the data structure into a written CSV file
    

};




