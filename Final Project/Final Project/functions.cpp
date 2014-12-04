#include "Header.h"


string userInput() {
    string input = "";
    cin >> input;
    return input;
}

void beginProgram() {
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
    cout << calendarOutPut;
    

}

string openCalendar(bool firstTime) {

    const string path  = userInput() + "/calendar.txt";
    string line;
    string contents;
    
    ifstream fileRead;
    fileRead.open(path.c_str());
    
    if ( !fileRead.is_open() ) {
        if(firstTime) {
            fileRead.close();
            cout << "No calendar file, creating file...";
            ofstream outFile;
            outFile.open(path.c_str());
            outFile << "Created" << "\n";
            outFile.close();
            fileRead.open(path.c_str());
        }
        else if(!firstTime) {
            cout << "No file found at this location";
        }
    }
    
    else {
        cout << "Opening existing calendar file" << endl;
    }
    
    
    while (getline(fileRead,line))
    {
        istringstream ss(line);
        ss >> contents;
    }
    
    fileRead.close();
    return contents;
}
