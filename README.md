# CS250 Project 1

# Chada Tech Clock

A simple C++ console application that simulates a clock, displaying both 12-hour and 24-hour formats and allowing the user to increment hours, minutes, or seconds via a nicely boxed menu.

---

## Features

- **Dual-format display**  
  Shows the current time side-by-side in 12-hour (with AM/PM) and 24-hour (ISO 8601) formats.
- **Interactive menu**  
  Text-based menu lets you add one hour, one minute, or one second, or exit the program.
- **Input validation**  
  Prompts until a valid initial time (hours 0–23, minutes 0–59, seconds 0–59) is entered.
- **Clean, reusable design**  
  Separation of concerns via `timeFunctions.h`/`.cpp` and a minimal `main.cpp`.

---
