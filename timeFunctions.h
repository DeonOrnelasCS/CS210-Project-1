// File: timeFunctions.h
// Author: Deon Ornelas
// Date: May 25, 2025

// Header file guards.
#ifndef TIMEFUNCTIONS_H
#define TIMEFUNCTIONS_H

#include <string>
#include <cstddef>

using namespace std; // Chose to use the standard namespace for convenience.

void welcomeMenu(); // Prints a welcome message.

string twoDigitString(unsigned int n); // Formats an integer 0–59 as two digits, adds leading zero if needed.

string nCharString(size_t n, char c); // Returns a string of length n filled with character c.

string formatTime24(unsigned int h, unsigned int m, unsigned int s); // Returns time as "hh:mm:ss" (24-hour, ISO 8601).

string formatTime12(unsigned int h, unsigned int m, unsigned int s); // Returns time as "hh:mm:ss AM/PM" (12-hour).

void printMenu(const char* strings[], unsigned int numStrings, unsigned char width); // Prints a boxed menu given an array of option strings.

void mainMenu(); // Main user input loop allowing time modifications or exit.

// Prompts the user to enter initial time for clock and validates the input.
// Uses pass by reference parameters.
void getInitialTime(unsigned int &h, unsigned int &m, unsigned int &s);

unsigned int getMenuChoice(unsigned int maxChoice); // Reads a user choice between 1 and maxChoice (inclusive).

void displayClocks(unsigned int h, unsigned int m, unsigned int s); // Displays both clocks side-by-side.

void addOneHour(); // Adds to the clock by one hour (rolls over at 23 to 0).

void addOneMinute(); // Adds to the clock by one minute (rolls over at 59 to 0 and calls addOneHour).

void addOneSecond(); // Adds to the clock by one second (rolls over at 59 to 0 and calls addOneMinute).

// Accessors (getters) and mutators (setters)
unsigned int getHour();
unsigned int getMinute();
unsigned int getSecond();
void setHour(unsigned int h);
void setMinute(unsigned int m);
void setSecond(unsigned int s);

// Header file guard.
#endif //TIMEFUNCTIONS_H
