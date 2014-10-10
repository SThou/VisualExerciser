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
#include "Read_Write_Module.h"

using namespace std;

int main(){ // test .h
  
   // transStats();
    
    RWModule Weekly;
    Weekly.init("MainStatsFile.csv", "Test.csv");
    vector<string> Parsed = Weekly.parseCSVfile(Weekly.openfile());
	vector<vector<string>> Parsed2D = Weekly.convert2D(Parsed);
    Weekly.writetofile(Weekly.fileMod(Parsed2D));
	vector<vector<int>> ParsedInt = Weekly.StringtoInt(Parsed2D);
	int average = Weekly.calcAvg(ParsedInt);
	cout << "Avg: " << average << endl;
	system("pause"); // HK: you can take this out , its just for the terminal not to close immediately after running
    
}






