#include "Header.h"


string userInput() {
    string input = "";
    cin >> input;
    return input;
}

string getNotes() {
    string fullNote = "";
    char input[100];
    cin.ignore(256, '\n');
    cin.getline(input,100);
    fullNote = input;
    return fullNote;
}

int getNum() {
    int input = 0;
    cin >> input;
    return input;
}

string beginProgram() {
    bool firstTime;
    string option;
    string calendarOutPut;
    
    cout << "Welcome to MyCalendar! If this is is your first time using this program, please enter 'Y' below, otherwise, enter 'N'." << endl << endl << "Is this your first Time? (Y or N): ";
    
    option = userInput();
    
    if(option == "Y" || option == "y") {
        firstTime = true;
    }
    else if (option == "N" || option == "n") {
        firstTime = false;
    }
    
    else cout << "Error";

    if(firstTime) {
        cout << "Enter location where you would like to save your calendar file: ";
    }
    
    else if (!firstTime) {
        cout  << "Enter location where are already have a saved file: ";
    }
    
    calendarOutPut = openCalendar(firstTime);
    return calendarOutPut;
}

string openCalendar(bool firstTime) {

    const string path  = userInput() + "/calendar.txt";
    
    ifstream fileRead;
    fileRead.open(path.c_str());
    
    if ( !fileRead.is_open() ) {
        if(firstTime) {
            cout << "No calendar file, creating file..." << endl;
            ofstream outFile;
            outFile.open(path.c_str());
            outFile.close();
        }
        else if(!firstTime) {
            cout << "No file found at this location";
        }
    }
    
    else {
        cout << "Opening existing calendar file" << endl;
    }
    fileRead.close();
    return path;
}

void createNewEvent(string path) {
    string month = "";
    int day = 0;
    string notes = "No notes about this event";
    int year = 0;
    int monthIndex = 0;
    bool monthVal = false;
    bool dayVal = false;
    bool yearVal = false;

    //Get year from ctime//
    
    time_t currentTime;
    struct tm *localTime;
    time(&currentTime);
    localTime = localtime(&currentTime);
    
    int compYear   = localTime->tm_year + 1900; //Year starts at 1900 plus time since
    
    while(!yearVal) {
        cout << "Please enter the year of your new event: ";
        year  = getNum();
        yearVal = validateYear(year, compYear);
    }
    
    bool isLeapYear = decideIfLeapYear(year); //Decide if its a leap year after the year is over.
    
    
    while(!monthVal) {
        cout << "Please enter the month code for your new event (first three characters): ";
        month = userInput();
        monthVal = validateMonth(month);
    }
    
    monthIndex = getMonthIndex(month);
    
    while(!dayVal) {
        cout << "Please enter the day for your new event: ";
        day = getNum();
        dayVal = validateDay(day, getMonthIndex(month), isLeapYear);
    }
    
    cout << "Please enter any notes for your new event: ";
    notes = getNotes();
    replace(notes.begin(), notes.end(),' ', '^');
    
    addEventToFile(path,month,monthIndex,day,year,notes);
    
    displayMenu(path);
}


//Check for a leap year
//Ask for the year first

bool validateYear(int num, int year) {
    bool isVal = false;
    
    if(num >= year) {
        isVal = true;
    }
    
    return isVal;
}

//Make sure month exists in reality
bool validateMonth(string month) {
    bool isVal = false;
    const string monthCodes[] = {"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};
    
    for(int x=0;x<12;x++) {
        if(monthCodes[x] == month) {
            isVal = true;
        }
    }
    
    return isVal;
}

//Make sure it is a valid day for month it falls under
bool validateDay(int day, int monthIndex, bool leapyr) {
    
    int numOfDays[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    bool isVal = false;
    
    if(leapyr){
        numOfDays[1] = 29;
    }
    
    if(numOfDays[monthIndex]>=day) {
        isVal = true;
    }
    
    return  isVal;
}



//Get the index of the month in the array, so that the number of days can be cross checked.
int getMonthIndex(string month) {
   const string monthCodes[] = {"jan","feb","mar","apr","jun","jul","aug","sep","oct","nov","dec"};
    int code = 0;
    for(int x=0;x<12;x++) {
        if(monthCodes[x] == month) {
            code = x;
        }
    }
    
    return code;

}


//Decide if it's a leap year

bool decideIfLeapYear(int year) {
    bool isVal = false;
    
    if((year % 4 == 0 && year % 100 != 0)||( year % 400 == 0)) {
        isVal = true;
    }
    
    else  {
        isVal = false;
    }
    
    return isVal;
}

void displayMenu(string path) {
    cout << "Enter the number of the option below you would like to do --" << endl;
    cout << "1. Create New Event" << endl;
    cout << "2. View Events for a given day" << endl;
    cout << "3. Export day schedule to a file" << endl;
    cout << "4. View all events" << endl;
    cout << "5. Exit" << endl;
    
    doChoice(getNum(),path);
    
}



void doChoice(int choice,string path) {
    
    if(choice == 1) {
        createNewEvent(path);
    }
    
    else if (choice == 2) {
        parseDay(path);
    }
}

void addEventToFile(string path,string month, int monthIndex, int day,int year,string notes) {
    
    ofstream outFile;
    outFile.open(path.c_str(),ios::app);
    outFile << monthIndex << " " << day << " " << year << " " << month << " " << notes << "\n";
    outFile.close();
    
}

void parseDay(string path) {
    
    string line;
    string contents;
    string dayKey;
    int eCounter = 0;
    
    cout << "Enter the month of the day you would like to view: ";
    int monthReq = getMonthIndex(userInput());
    cout << "Enter the number of the day you would like to view: ";
    int dayReq = getNum();
    cout << "Enter the year of the event you would like to view: ";
    int yrReq = getNum();
    
    stringstream conv;
    conv << monthReq << dayReq << yrReq;
    dayKey = conv.str();
    
    ifstream fileRead;
    fileRead.open(path.c_str());
    
    
    if ( !fileRead.is_open() ) {
        
        cout << "Error" << endl;
        
    }
    else {
        while (getline(fileRead, line)) {
            int monthIndex = 0;
            int day = 0;
            int year = 0;
            string month = "";
            string notes = "";
            string key = "";
            
            istringstream iss(line);
            
            if (!(iss >> monthIndex >> day >> year >> month >> notes)) {
                cout << "No events in this file";
                break;
            }
            
            else  {
                stringstream reconv;
                reconv << monthIndex << day << year;
                key = reconv.str();
                
                replace(notes.begin(), notes.end(),'^', ' ');
                
                if(key == dayKey) {
                    cout << "MONTH: " << month + " DAY: " << day << " YEAR: " << year << " NOTES: " << notes << "\n";
                    eCounter++;
                }
                
            }
            
            if (eCounter==0) {
                cout << "No events on this day";
            }

        }
    }
    
    fileRead.close();
    displayMenu(path);

    
}