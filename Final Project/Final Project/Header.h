//
//  Header.h
//  Final Project
//
//  Created by Jonah Allibone on 11/19/14.
//  Copyright (c) 2014 Jonah Allibone. All rights reserved.
//

#ifndef Final_Project_Header_h
#define Final_Project_Header_h

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
#include <sstream>
#include <ctime>


using namespace std;


string userInput(); //to accept user input
void loadCalendar(string path); //load an old calendar
string beginProgram(); //Begin Program, return the active path for the file
void pathSetup(); //Setup path for the first time
string openCalendar(bool firstTime); //Open already made calendar
void createNewEvent(string path);
void findEvent();
void returnEvent();
bool validateMonth(string month);
bool validateDay(int day, int monthatx, bool leapYr);
bool validateYear(int num, int year);
int getMonthIndex(string month);
int getNum();
bool decideIfLeapYear(int year);
/********************
 To make for tomorrow
 ********************/
void displayMenu(string path); //Display options for the program after starting it up
void doChoice(int choice, string path); //Do what it asks to do. Possibly not necessary.
void parseDay(string path);
void addEventToFile(string path,string month, int monthIndex, int day,int year,string notes);

#endif
