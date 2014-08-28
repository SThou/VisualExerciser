//
//  main.cpp
//  VisualEx
//
//  Created by ST on 8/26/14.
//  Copyright (c) 2014 ST. All rights reserved.
//

#include <iostream>
#include <fstream> // stream class to both read and write from/to files

using namespace std;

int main()
{
    char data[100];
    
    
    fstream file("CSVStats.csv");
    
  
    if (!file)
    { cerr << " File Could Not Open" ;
      exit (1);
    }

    
    int i = 0;
    // Read from file
     while (file)
     {
     string input;
     getline(file, input);
     cout<< input <<endl;
         i++;
     
     }
    
    ;;
    
    return 0;
    
    
    
}

