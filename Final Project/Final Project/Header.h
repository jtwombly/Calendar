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

using namespace std;


string userInput(string question); //to accept user input
void loadCalendar(string path); //load an old calendar
void beginProgram(); //Begin Program
void pathSetup(); //Setup path for the first time
string openCalendar(bool firstTime); //Open already made calendar



#endif
