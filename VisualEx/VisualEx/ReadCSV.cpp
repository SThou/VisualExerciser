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
#include <cstring>
#include <cstdio>
#include <stdio.h>
#include <sstream>

using namespace std;

/*record of one weight*/

struct record{

	//char userweighthead[14] = "user weight"; // heading for user weight
	string userweight;
	string exercise[30]; // individual exercise
	char malenationalstats;
};


int main(void)
{

stringstream ss;
string converted;
fstream file("CSVStats.csv");

 if (!file)
 { cerr << " File Could Not Open" ;
   exit(1);
 }



struct record testrecord; // make a blank struct


	    while (file)
	     {


	     file.seekg(0, file.end);
	     file.seekg(0, file.beg);

	     char *buffer = new char[328328];
	     file.read(buffer, 328328);


	     // token test
	     char *tokenptr;
	     tokenptr = strtok(buffer, ",");
	     int x = 0;
	     char converted[200];

	 while (tokenptr != NULL)
	 {
		  ss << tokenptr;

 	 if (x >= 1)
  	 {   ss >> converted;
 		 testrecord.exercise[x] = converted;}

 	  x++;
	  tokenptr = strtok(NULL, ","); // next token



	 }

	 cout<<"output: "<<testrecord.exercise[1]<<endl;
	 cout<<"output: "<<testrecord.exercise[2]<<endl;
	 cout<<"output: "<<testrecord.exercise[3]<<endl;
	 cout<<"output: "<<testrecord.exercise[4]<<endl;
	 cout<<"output: "<<testrecord.exercise[5]<<endl;


	     }
}







/*
int main()
{
// CSVStatsMod
    fstream file("CSVStats.csv");

    if (!file)
    { cerr << " File Could Not Open" ;
      exit(1);
    }


    // Read from file
    while (file)
     {
     string input;
     string charmatch = (",");
  //   getline(file, input);




     file.seekg(0, file.end);
  //   int length = file.tellg();
     file.seekg(0, file.beg);

     char *buffer = new char[328328];
  //   string arraystring[200];
     file.read(buffer, 328328);


     // token test

     char *tokenptr;

     cout << "the individuals words: \n" <<endl;

     tokenptr = strtok(buffer, ",");

     while (tokenptr != NULL){
    	 cout<<tokenptr<<endl;
    //	 arraystring[1] = tokenptr;
    //	 cout<< arraystring<<endl;
     }

   //  cout<<buffer<<endl; // us






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

    // } // end while loop

/*
    FILE *file2;
    fpos_t position =0;
    file2 = fopen("CSVStats.csv", "a");
    fsetpos (file2, &position);
    fputs ("TestST", file2);
    fclose (file2);



 cout<< "file process complete" << "\n" << endl;

    return 0;



}

*/
