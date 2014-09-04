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

using namespace std;

/*record of one weight*/

struct record{

	//char userweighthead[14] = "user weight"; // heading for user weight
	int userweight;
	char exercise[25]; // individual exercise
	int malenationalstats;
};


int main(void)
{


//fstream file("CSVStats.csv");

// if (!file)
// { cerr << " File Could Not Open" ;
//   exit(1);
// }



FILE *fileptr; // pointer to file

struct record testrecord = { 0, "", 0};

cout<<"test:"<<testrecord.userweight<<endl;

if ( ( fileptr = fopen( "CSVStats.csv", "rb") ) == NULL)
{printf ("File could not be opened\n");
}

else {
	 // Read from file
	    while (!feof (fileptr))
	     {
	 //    string input;
	  //   string charmatch = (",");

	 //    file.seekg(0, file.end);
	 //    file.seekg(0, file.beg);

	  //   char *buffer = new char[328328];
	 //    file.read(buffer, 328328);

	  //   struct record *n= (struct record*)malloc(sizeof(struct record));

	     fread(&testrecord,sizeof(struct record), 1, fileptr);
	     // token test
	 //    char *tokenptr;


	 };
	    fclose(fileptr);

	    cout<<"test2\n"<<testrecord.exercise<<endl;

	 //   cout<< testrecord.userweight<<endl;

	   //  tokenptr = strtok(buffer, ",");

	 //    while (tokenptr != NULL)
	 //    {
	 //   	 cout<<tokenptr<<endl;
	  //  	 tokenptr = strtok(NULL, ","); // exit
//



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
