/*
 * File: main.cpp
 * Author: Deon Ornelas
 * Date: May 25, 2025
 * Description: Main program for Chada Tech Clock simulation program.
 */

#include <iostream>
#include "timeFunctions.h" // Include declarations for time functions.

using namespace std; // Chose to use the standard namespace for convenience.

/*
 * Retrieves initial time from user and displays initial then manipulated clock time.
 * Starts user input loop for manipulation.
 */

int main() {
    unsigned int h, m, s;  // Variables to hold hours, minutes, seconds.

    welcomeMenu(); // Display a welcome message to the user.

    getInitialTime(h, m, s); // Gets and sets initial time from the user.

    // Initialize the internal clock with user-provided time.
    setHour(h);
    setMinute(m);
    setSecond(s);

    displayClocks(getHour(), getMinute(), getSecond()); // Displays both 12 and 24-hour clock formats.

    mainMenu(); // Enters the main menu loop to allow time change(s) or exit.

    return 0;
}