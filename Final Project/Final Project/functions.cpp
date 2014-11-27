#include "Header.h"


string userInput() {
    string input = "";
    cin >> input;
    return input;
}

void beginProgram() {
    bool firstTime;
    
    cout << "Welcome to MyCalendar! If this is is your first time using this program, please enter 'Y' below, otherwise, enter 'N'." << endl << endl << "Is this your first Time? (Y or N):";
    if(userInput() == "Y") {
        firstTime = true;
    }
    else if (userInput() == "N") {
        firstTime = false;
    }
    
    else cout << "Error";

    if(firstTime) {
        cout << "Please enter the path that you would like to save your calendar";
    }
    
    else if (!firstTime) {
        
    }




}
