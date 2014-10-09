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
//#include "RWWeeklyStats.h"
//#include "Read_Write_Module.h"
#include "Data_Schedule.h"

using namespace std;


int main(){ // test .h
  

    
    
    
   
    // Test for Read_Write_Module.h//
    RWModule Weekly;
    Weekly.init("MainStatsFile.csv", "Test.csv");
    vector<string> Parsed = Weekly.parseCSVfile(Weekly.openfile());
    Weekly.writetofile(Weekly.fileMod(Parsed));
    
    
    
      
    stats_Schedule game;
    
    
   // test.init("MainStatsFile.csv", "Test.csv");
    
    
    
    
}






