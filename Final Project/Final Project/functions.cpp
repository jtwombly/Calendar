#include "Header.h"


string userInput() {
    string input = "";
    cin >> input;
    return input;
}

void beginProgram() {
    bool firstTime;
    string option;
    
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
    
    openCalendar();

}

void openCalendar() {
    string path;
    string _fileInput;
    string outFile;

    path  = userInput() + "/calendar.txt";
    
    ifstream fileRead(path);
    
    if ( !fileRead.is_open() ) {
        cout << "No calendar file, creating file...";
        _fileInput = "calendar.txt";
        fileRead.open(_fileInput.c_str());
    }
    
    else {
        cout << "Opening existing calendar file" << endl;
        fileRead.open(_fileInput.c_str());
    }
    
    
}
