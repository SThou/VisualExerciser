//============================================================================
// Name        : Date.cpp
// Author      : ST
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Date.h"
using namespace std;


/*
typedef struct Date{
	int month; // (1-12)
	int day;  //
	int year;
} date; // why is struct labeled and called with this and not Date

date Date; // create an instance of the struct
*/

struct month{
    int name;
    int maxday;
};


typedef struct node{
    month data; //data type is going to be struct month
    struct node* next;
}node;


void populatemonths(){

    month Jan;
    month Feb;
    month Mar;
    month Apr;
    month May;
    month Jun;
    month Jul;
    month Aug;
    month Sep;
    month Oct;
    month Nov;
    month Dec;
    
    Jan.name = 1;
    Jan.maxday = 31;
    
    //Jan->name = 1;
    //Jan->maxday = 31;
    
    Feb.name = 2;
    Feb.maxday = 28;
    
    Mar.name = 3;
    Mar.maxday = 31;
    
    Apr.name = 4;
    Apr.maxday = 30;
    
    May.name = 5;
    May.maxday = 31;
    
    Jun.name = 6;
    Jun.maxday = 30;
    
    Jul.name = 7;
    Jul.maxday = 31;
    
    Aug.name = 8;
    Aug.maxday = 31;
    
    Sep.name = 9;
    Sep.maxday = 30;
    
    Oct.name = 10;
    Oct.maxday = 31;
    
    Nov.name = 11;
    Nov.maxday = 30;
    
    Dec.name = 12;
    Dec.maxday = 31;
    
    
    //HK: code for month linked list
    node* current; // for traversal and linking
    node* n;
    node* header; // leave as header for the linkedlist
    n = new node;
    n->data = Jan;
    current = n;
    header = n; // leave as header
    
    n = new node;
    n->data = Feb;
    current->next = n;
    
    n = new node;
    n->data = Mar;
    current->next = n;
    
    n = new node;
    n->data = Apr;
    current->next = n;
    
    n = new node;
    n->data = May;
    current->next = n;
    
    n = new node;
    n->data = Jun;
    current->next = n;
    
    n = new node;
    n->data = Jul;
    current->next = n;
    
    n = new node;
    n->data = Aug;
    current->next = n;
    
    n = new node;
    n->data = Sep;
    current->next = n;
    
    n = new node;
    n->data = Oct;
    current->next = n;
    
    n = new node;
    n->data = Nov;
    current->next = n;
    
    n = new node;
    n->data = Dec;
    current->next = n;
    n->next = NULL; //end of the list


}


void date::getmonth(){
	cout<<"Enter in the month"<<endl;
	cin>>currentDate.month;
}


void date::getday(){
	cout<<"Enter in the day"<<endl;
	cin>>currentDate.day;
}


void date::getyear(){
	cout<<"Enter in the year"<<endl;
	cin>>currentDate.year;
}


void date::displaydateline(){
	cout<<currentDate.month<<"/"<<currentDate.day<<"/"<<currentDate.year<<endl;
}



void date::increment(){ // increment the day (by this amount( day) )

    month Jan;
    month Feb;
    month Mar;
    month Apr;
    month May;
    month Jun;
    month Jul;
    month Aug;
    month Sep;
    month Oct;
    month Nov;
    month Dec;
    
    Jan.name = 1;
    Jan.maxday = 31;
    
    //Jan->name = 1;
    //Jan->maxday = 31;
    
    Feb.name = 2;
    Feb.maxday = 28;
    
    Mar.name = 3;
    Mar.maxday = 31;
    
    Apr.name = 4;
    Apr.maxday = 30;
    
    May.name = 5;
    May.maxday = 31;
    
    Jun.name = 6;
    Jun.maxday = 30;
    
    Jul.name = 7;
    Jul.maxday = 31;
    
    Aug.name = 8;
    Aug.maxday = 31;
    
    Sep.name = 9;
    Sep.maxday = 30;
    
    Oct.name = 10;
    Oct.maxday = 31;
    
    Nov.name = 11;
    Nov.maxday = 30;
    
    Dec.name = 12;
    Dec.maxday = 31;
    
    
    //HK: code for month linked list
    node* current; // for traversal and linking
    node* n;
    node* header; // leave as header for the linkedlist
    n = new node;
    n->data = Jan;
    current = n;
    header = n; // leave as header
    
    n = new node;
    n->data = Feb;
    current->next = n;
    
    n = new node;
    n->data = Mar;
    current->next = n;
    
    n = new node;
    n->data = Apr;
    current->next = n;
    
    n = new node;
    n->data = May;
    current->next = n;
    
    n = new node;
    n->data = Jun;
    current->next = n;
    
    n = new node;
    n->data = Jul;
    current->next = n;
    
    n = new node;
    n->data = Aug;
    current->next = n;
    
    n = new node;
    n->data = Sep;
    current->next = n;
    
    n = new node;
    n->data = Oct;
    current->next = n;
    
    n = new node;
    n->data = Nov;
    current->next = n;
    
    n = new node;
    n->data = Dec;
    current->next = n;
    n->next = NULL; //end of the list
    n = header;

    for (int i = 0; i < 12; i++)
    {
        cout << "linked list elem: " << n->data.name << endl;
    n = n->next;
    }
    
    
		// match the month to an existing month value in database
    bool done;
    
    while(!done){ // handle the days and month
        
        for (int i = 0; i<12; i++){
          
            if (currentDate.month == current->data.name)
            {
                cout<<"month entered"<<currentDate.month<<endl;
                cout<<"month searched"<<current->data.name<<endl;
                
            }
            else{
            cout<<"month iterated:"<<current->data.name<<endl;
                
            
            }
            current = current->next;
            
        }
        
        
        
    
    /*
    
    for loop:  // handle the days and month
			if ( passed month = month in list)
				if (current day < max day in month list )
					increment day
				if (current day = 31 and month = december)
					increment year
				if (current day = max day in month list)
					increment month
				if (current day = 29 && month == feb )
					increment month
					// catch the leap year
				if (current day < max day in feb (28) && month is feb && year is multiple of 4)
					increment day // feb 29

*/



}
}