//============================================================================
// Name        : VisualExPC.cpp
// Author      : ST
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdlib> // for exit functions
#include <iostream>
#include <fstream> // stream class to both read and write from/to files
#include <string>

using namespace std;

int main()
{
    char data[100];


    fstream file("CSVStats.csv");


    if (!file)
    { cerr << " File Could Not Open" ;
      exit(1);
    }


    int i = 0;
    int commapp = 0;
    int c = 0;
    int array [328328];
    // Read from file
     while (file)
     {
     string input;
     string charmatch = (",");
     getline(file, input);

//11 is the first occurance

    for (i = input.find(charmatch, 0 ); i != string::npos; i = input.find(charmatch, i))
    {

    	if (input.find(charmatch,i))
    	{
    		array[c] = i;
    		c++;
    	}
    	commapp++;
    	i++;
    }

    for (int b = 0; b <100; b++){

    	cout<<array[b]<<endl;
    }
     }

    ;;

    return 0;



}

