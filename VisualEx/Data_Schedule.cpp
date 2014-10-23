//
//  Data_Schedule.cpp
//  VIsualEx
//
//  Created by ST on 10/8/14.
//  Copyright (c) 2014 ST. All rights reserved.
//

#include "Data_Schedule.h"

int currentrownum; //used for having the current rownum for enterData
/*

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



void stats_Schedule::userInputStartDate(string startdate){ // "05/03/1988"
    
    int a = 0; // counter for inner loop to increment startdate
    
    int date[17]; // array to hold date
    for(int i = 0; i<17; i++){
        
        date[i] = startdate+a;
        date[i+1] = startdate+a;
        date[i+2] = startdate+a;
        
        i = i*3;
        b++;
        
        
    } // end for loop
    
    
 // take the date and figure out the day of the week
    
    int dayofweek[17]; // array to hold day of week
    for(int b = 0; b<17; b++){
    
        dayofweek[i] = convertdayofweek(date[i]); // find a function that can do the convertday of week
        
        
    }
    
    // load the exercises
    
    string exercises[17];
    
    exercises[0] = "Squat"; // come back to fill out the exercises in this manner
    
    
}




void stats_Schedule::userinputInfo(int location,string dataset[]){
    string entry; // all entrys default to strings and will be converted when necessary
    cout<<"what do you want to enter?"<<endl;
    
    cin>>entry;
    
    dataset[location] = entry;
}

string Data_Schedule::getDate()
{
string date;
cout << "Enter the date that you wish to input stats for : " << endl;
cin >> date;

return date;

}

vector<string> Data_Schedule::enterData(string date)
{
vector<string> rowData;
string temp;
//assume getrow is a function that converts date to a rownum to be used by later function exportFinalData
currentrownum = getdata(date);

cout << "please enter the amount of sets" << endl;
cin >> temp
rowData[0] = temp;
cout << "please enter the amount of reps" << endl;
cin >> temp
rowData[1] = temp;
cout << "please enter the amount of weight" << endl;
cin >> temp
rowData[2] = temp;
cout << "please enter whether you completed" << endl;
cin >> temp
rowData[3] = temp;

return rowData;
}

Data_Schedule::copytoFinal(vector<string> rowData, vector<vector<string>> scheduleData,string date,vector<vector<string>> inputFinal)
{
//vector<vector<string>> data2D;
inputFinal[currentrownum][0] = data;
inputFinal[currentrownum][1] = scheduleData[currentrownum][0];
inputFinal[currentrownum][2] = scheduleData[currentrownum][1];
inputFinal[currentrownum][3] = rowData[0];
inputFinal[currentrownum][4] = rowData[1];
inputFinal[currentrownum][5] = rowData[2];
inputFinal[currentrownum][6] = rowData[3];
}


*/