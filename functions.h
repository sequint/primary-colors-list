// Steven Quintana
// Ch.18 Assignment - Linked List Project
// July 8th, 2020

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

// Output Functions

// Input Validation Functions
int isInteger(int, string);
bool isPrimColor(string);