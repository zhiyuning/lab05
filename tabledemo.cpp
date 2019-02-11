//  tabledemo.cpp
//  W19 - Lab04

// tabledemo.cpp - demonstration program for Table

#include <stdio.h>


#include <iostream>
#include <fstream>
#include "table.h"
using namespace std;


int main() {
    
    cout << "Demonstrate very small table\n";
    Table t(7);
    t.put(7, "seven");
    t.put(9, "nine");
    t.put(17, "Seventeen");
    t.put(4, "four");
    t.put(36, "Thirty-six");
    cout << t;

    t=t;

    cout<<"\n"<<"self-check of t"<<endl;
    cout<<t;
    cout<<"----------------------------"<<endl;

    Table t2;
    t2=t;
    cout <<"\n"<<"t2:"<<"\n"<<t2;
    cout <<"\n"<< "change the value of t" <<endl;
    t.put(4396, "Clearlove 777");
    
    t.put(123, "NMD WSM");
    cout <<"\n"<<"Now the value of t2 becomes :"<<endl;
    cout << t2;

    
    cout <<"\n"<< "Now the values of t are :"<<endl;
    cout << t;

    cout <<"\n"<<"self-assign check:"<<endl;

    t2=t2;
    cout<< t2;
    
}
