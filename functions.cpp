// Implementation file for the main programs input and output functions.

#include <iostream>
#include <string>
#include <cstring>
#include "functions.h"
#include "LinkedList.h"
using namespace std;

//************************************************************************************************************************************
//                                                         USER INPUT FUNCTIONS 						     *
//************************************************************************************************************************************


//******************************************************************************************
// menuChoice Function									   *
//											   *											   
// This function prints the menu and prompts the user to enter a selection from the menu.  *
//******************************************************************************************

int menuChoice()
{
	int choice;															// Stores a variable of the user's menu choice.
	string custPrompt = "Please enter a number from the menu (1-6): ";  // Variable to hold the custom prompt for this function.

	// Display the menu, and prompt the user for a choice.
	// Then store the choice into the choice variable.
	cout << "\n\n1. Append\n";
	cout << "2. Insert\n";
	cout << "3. Delete\n";
	cout << "4. Print\n";
	cout << "5. Reverse\n";
	cout << "6. Search\n\n";
	cout << "Please choose a menu option: ";
	cin >> choice;

	// Check if choice is an integer and store it back into the variable.
	choice = isInteger(choice, custPrompt);

	return choice;
}

//******************************************************************************************************
// getPrimColor Function									       *
//												       *
// This function prompts the user to enter a primary color, and returns the color input.               *
//******************************************************************************************************

string getPrimColor()
{
	string color;  // Variable that holds the user's color input.

	// Clear the buffer.
	cin.clear();
	cin.ignore(10, '\n');

	// Prompt the user to enter a primary color and store it to color.
	cout << "Red, Yellow, or Blue: ";
	getline(cin, color);

	// Check if the input is a primary color, while it is not prompt the user for another input.
	while (!isPrimColor(color))
	{
		cout << "\nInvalid entry, '" << color << "' is not a primary color.\n";
		cout << "Please enter a primary color (red, yellow, or blue): ";
		getline(cin, color);
	}

	return color;
}

//******************************************************************************************************
// contProgram Function										       *
//												       *
// This function prompts the user to continue the program or not.				       *
//******************************************************************************************************

bool contProgram()
{
	int contChoice;   // Variable to hold the users continue or not choice.

	// Ask the user to continue the program or not.
	cout << "\nWould you like to go back to the menu or exit the program?\n";
	cout << "Enter the number '1' for the menu, or '2' to exit the program: ";
	cin >> contChoice;

	// While the input is outside the bounds of the request, print error message and prompt for another selection.
	while (cin.fail() || contChoice < 1 || contChoice > 2)
	{
		cout << "\nThat is not a valid entry.\n";

		// Clear the buffer.
		cin.clear();
		cin.ignore(10, '\n');

		cout << "Enter the number '1' for the menu, or '2' to exit the program: ";
		cin >> contChoice;
	}

	if (contChoice == 1)
	{
		return true;
	}
	else
	{
		cout << "\nGoodbye for now!\n\n";
		return false;
	}
}

//******************************************************************************************************
// getPosition Function										       *
//												       *
// This function gets a number from the user that represents where in the list they would like to      *
// insert a new node. The function checks if it is a number and returns the number.	               *
//******************************************************************************************************

int getPosition()
{
	int position;																	 // Variable to hold user's number entry.
	string custPrompt = "Re-enter your desired position in the list as a number: ";  // Variable to hold the custom prompt for this function.

	cout << "Enter your number here: ";
	cin >> position;

	// Check if position is an integer and store it back into the variable.
	position = isInteger(position, custPrompt);

	return position;
}



//************************************************************************************************************************************
//                                                      INPUT VALIDATION FUNCTIONS 													 *
//************************************************************************************************************************************


//******************************************************************************************************
// isInteger Function										       *
//											  	       *
// This function checks if an input is an integer. While the input is not an integer it prompts for    *
// a new number entry and returns that number. Otherwise, it returns the origional input.	       *
//******************************************************************************************************

int isInteger(int input, string custPrompt)
{
	int newNum = input;  // Variable that holds the new input from the user.

	// While the entry is not an integer, print error message and prompt again.
	while (cin.fail())
	{
		cout << "\nInvalid entry, input must be a number.\n";

		// Clear the buffer.
		cin.clear();
		cin.ignore(10, '\n');

		// Display the custom portion of the prompt from the function that called isInteger.
		cout << custPrompt;
		cin >> newNum;
	}

	return newNum;
}

//******************************************************************************************************
// isPrimColor Function										       *
//												       *
// This function checks if a string is a primary color.						       *
//******************************************************************************************************

bool isPrimColor(string color)
{
	// Make the copy of the string variable passed all lower case for testing.
	for (int count = 0; count < color.length(); count++)
	{
		color[count] = tolower(color[count]);
	}

	if (color == "red" || color == "yellow" || color == "blue")
	{
		return true;
	}
	else
	{
		return false;
	}
}
