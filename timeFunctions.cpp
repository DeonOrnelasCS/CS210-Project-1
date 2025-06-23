// File: timeFunctions.cpp
// Author: Deon Ornelas
// Date: May 25, 2025


// Program implements functions for clock formatting, display, and manipulation.

#include "timeFunctions.h" // Include declarations for time functions
#include <iostream>
#include <string>
#include <iomanip>

using namespace std; // Chose to use the standard namespace for convenience.

// Internal storage variables for clock values
static unsigned int currentHour;
static unsigned int currentMinute;
static unsigned int currentSecond;
const char* menuOptions[] = {"Add One Hour", "Add One Minute", "Add One Second", "Exit Program"};
const unsigned int menuSize = 4;
const unsigned char menuWidth = 30;

// Displays the welcome message for the clock program.
void welcomeMenu() {
    cout << "Welcome to the Chada Tech Clock!\n" << endl;
}

// Prompts the user to enter the initial time values and validates each.
void getInitialTime(unsigned int &h, unsigned int &m, unsigned int &s) {
    do { // Loop until a valid hour (0-23) is entered.
        cout << "Enter initial hours [0-23]: ";
        cin  >> h;
        if (h < 0 || h > 23) { // Validates input to required parameters.
            cout << "Invalid input. Enter a number between 0 and 23.\n" << endl;
        }
    } while (h > 23);

    do { // Loop until a valid minute (0-59) is entered.
        cout << "Enter initial minutes [0-59]: ";
        cin  >> m;
        if (m < 0 || m > 59) { // Validates input to required parameters.
            cout << "Invalid input. Enter a number between 0 and 59.\n" << endl;
        }
    } while (m > 59);

    do { // Loop until a valid second (0-59) is entered.
        cout << "Enter initial seconds [0-59]: ";
        cin  >> s;
        if (s < 0 || s > 59) { // Validates input to required parameters.
            cout << "Invalid input. Enter a number between 0 and 59.\n" << endl;
        }
    } while (s > 59);
}

string twoDigitString(unsigned int n) {
    string numConv;

    if (n <= 9) { // Checks if number needs leading zero.
        numConv = to_string(n);
        numConv.insert(0, "0"); // Inserts leading zero if needed.
    }
    else {
        numConv = to_string(n); // If no leading zero is needed, outputs value to clock.
    }
    return numConv;
}

string nCharString(size_t n, char c) {
    return string(n, c); // Generates string of repeated characters.
}

// Used to build output format for 24-hour clock.
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {

    string hh = twoDigitString(h);
    string mm = twoDigitString(m);
    string ss = twoDigitString(s);

    return hh + ":" + mm + ":" + ss;
}

// Used to build output format for 12-hour clock.
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {

    string amOrPm;

    // Used to determine if time output needs AM or PM.
    if (h < 12) {
        amOrPm = " A M";
    } else {
        amOrPm = " P M";
    }

    unsigned int hoursPast12 = h % 12;

    if (hoursPast12 == 0) { // Used to rollover time.
        hoursPast12 = 12;
    }
    string hh = twoDigitString(hoursPast12);
    string mm = twoDigitString(m);
    string ss = twoDigitString(s);

    return hh + ":" + mm + ":" + ss + amOrPm; // Output format.

}

void printMenu(const char* strings[], unsigned int numStrings, unsigned char width) {

    cout << nCharString(width, '*') << endl; // Draw top border.

    // Print each menu option with padding
    for (unsigned int i = 0; i < numStrings; i++) {
        cout << "* " << to_string(i + 1) << " - " << strings[i];

        unsigned int printLen = 2 + to_string(i + 2).length() + 3 + string(strings[i]).length(); // Calculate printed length

        unsigned int spacesNeeded = width - 1 - printLen; // Calculate padding spaces

        cout << nCharString(spacesNeeded, ' ') << "*" << endl; // Close with border char

        if (i + 1 < numStrings) { // Blank line between options
            cout << endl;
        }
    }
    cout << nCharString(width, '*') << endl; // Draw bottom border.
}

// Used to get user input and validate.
unsigned int getMenuChoice(unsigned int maxChoice) {
    unsigned int choice; // Stores user input.

    while (true) {
        cout << "Enter your choice: ";
        if (!(cin >> choice)) { // Used to validate input and clear screen.
            cin.clear(); // Clear any error flags
            cout << "Invalid input. Enter a number between 1 and " << maxChoice << "." << endl;
            continue;
        }
        if (choice > maxChoice || choice < 1) {
            cout << "Enter a number between 1 and " << maxChoice << "." << endl;
            continue;
        }
        if (choice == maxChoice) { // Used if 4 is selected and exits program with message.
            cout << "\nExiting Clock Program, Goodbye!" << endl;
        }
        return choice;
    }
}

// Shows both clock formats
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {

    cout << endl; // Added for cleaner formatting.
    cout << "Current Time:" << endl; // Added to show user that current times are being displayed.

    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl; // Top Border

    cout << nCharString(1, '*') << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << nCharString(3, ' ');

    cout << nCharString(1, '*') << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << endl;

    cout << endl; // cout an endl for a blank line

    cout << nCharString(1, '*') << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << nCharString(1, '*') << nCharString(3, ' ');

    cout << nCharString(1, '*') << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << nCharString(1, '*') << endl;

    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl; // Bottom border.

}

// Main interaction menu for program.
void mainMenu() {
    unsigned int selection;

    printMenu(menuOptions, menuSize, menuWidth); // Prints menu for user.
    while ((selection = getMenuChoice(4)) != 4) {
        switch (selection) { // Used to delegate user input to correct function.
            case 1:
                // Advance one hour and display the clocks
                addOneHour();
                break;

            case 2:
                // Advance one minute and display the clocks
                addOneMinute();
                break;

            case 3:
                // Advance one second and display the clocks
                addOneSecond();
                break;

            default:
                // Is not used.
                break;
        }
        displayClocks(getHour(), getMinute(), getSecond()); // Displays current clock time.
        printMenu(menuOptions, menuSize, menuWidth); // Prints menu for continued used or exit.
    }
}

void addOneHour() { // Adds one hour to clock time. Includes rollover if needed.
    unsigned int hours = getHour();

    if (hours < 23) {
        hours += 1;
    }
    else {
        hours = 0;
    }
    setHour(hours);
}

void addOneMinute() { // Adds one minute to clock time. Includes rollover if needed.
    unsigned int minutes = getMinute();

    if (minutes < 59) {
        minutes += 1;
    }
    else {
        minutes = 0;
        addOneHour();
    }
    setMinute(minutes);
}

void addOneSecond() { // Adds one second to clock time. Includes rollover if needed.
    unsigned int seconds = getSecond();

    if (seconds < 59) {
        seconds += 1;
    }
    else {
        seconds = 0;
        addOneMinute();
    }
    setSecond(seconds);
}

// Accessors (getters) and mutators (setters)

unsigned int getHour() {return currentHour;}
unsigned int getMinute() {return currentMinute;}
unsigned int getSecond() {return currentSecond;}

void setHour(unsigned int h) {currentHour = h;}
void setMinute(unsigned int m) {currentMinute = m;}
void setSecond(unsigned int s) {currentSecond = s;}