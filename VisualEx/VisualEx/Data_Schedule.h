//
//  Data_Schedule.h
//  VIsualEx
//
//  Created by ST on 10/8/14.
//  Copyright (c) 2014 ST. All rights reserved.
//

#ifndef __VIsualEx__Data_Schedule__
#define __VIsualEx__Data_Schedule__

#include <stdio.h>
#include "Read_Write_Module.h"

#endif /* defined(__VIsualEx__Data_Schedule__) */

//inherits the RWWeeklyStats.h class


class stats_Schedule: public RWModule
{
    

public: // File manipulation for specific file

    stats_Schedule(); // constructor
    ~stats_Schedule() {}; // deconstructor
    
    vector<vector<string>> fileMod(vector<string> ParsedData); // modification for specific file types to be modified
    
    
    // To do
    // Function for Date, DayOfWeek, to be populated
    void userInputStartDate(string startdate);
    
    
    // Function to align a pre initialized vector / array with exerises to populate
    // Function for user to input set/rep/weight/ completed
    void userinputInfo(int location, string dataset[]); // preemptive for apps, takes location of the data structure passed by dataset (set, rep, weight, completed) to be adjusted.
    
    void writetofile(vector<vector<string>> modFile); // copy parsed data to output CSV file
    
    

    

};