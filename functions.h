// Function prototype file for functions of the main program.

#pragma once

#include <string>
#include "LinkedList.h"
using namespace std;

// User Input Functions
int menuChoice();
string getPrimColor();
bool contProgram();
int getPosition();

// Input Validation Functions
int isInteger(int, string);
bool isPrimColor(string);
