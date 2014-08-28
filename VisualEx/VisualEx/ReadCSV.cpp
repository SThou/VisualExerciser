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
#include <cstdio>

using namespace std;

int main()
{

    fstream file("CSVStats.csv");

    if (!file)
    { cerr << " File Could Not Open" ;
      exit(1);
    }


    int i = 0;
    int c = 0;
    int array [328328];

    // Read from file
    while (file)
     {
     string input;
     string inputstring;
     string charmatch = (",");
     getline(file, input);




     file.seekg(0, file.end);
  //   int length = file.tellg();
     file.seekg(0, file.beg);

     char * buffer = new char[328328];

     file.read(buffer, 328328);

     file.write("test", 11);
  //   cout<<buffer<<endl;

    // char charwrite = 'ST';
   //   cout<< buffer[10]<<endl;
/*
     // match the commas and mark their positions
    for (i = input.find(charmatch, 0 ); i != string::npos; i = input.find(charmatch, i))
    {

    	if (input.find(charmatch,i))
    	{
    		array[c] = i;
    		c++;
    	}
    		i++;
    }

    	// print back
    for (int b = 0; b <100; b++)
    {cout<<array[b]<<endl;}


*/

     } // end while loop

/*
    FILE *file2;
    fpos_t position =0;
    file2 = fopen("CSVStats.csv", "a");
    fsetpos (file2, &position);
    fputs ("TestST", file2);
    fclose (file2);

*/



    return 0;



}

