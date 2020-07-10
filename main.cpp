// Steven Quintana
// Ch.18 Assignment - Linked List Project
// July 8th, 2020

#include <iostream>
#include <string>
#include "LinkedList.h"
#include "functions.h"
using namespace std;


//***************************
//      MAIN FUNCTION       *
//***************************

int main()
{
	LinkedList primaryColors;  // LinkedList object to store the primary colors list.
	string colorChoice;		   // Variable that temporarily holds a color selection.   
	int position,			   // Variable that temporarily holds a the position within the list.
		trueFalse;			   // Variable that temporarily holds an integer that represents a true/false test.

	do
	{
		// Call the member function of LinkedList that the user has chosen from menuChoice.
		switch (menuChoice())
		{
			// Clear the buffer.
			cin.clear();
			cin.ignore(10, '\n');

		case 1:

			// Customer color prompt for adding to the end of the list.
			cout << "\nWhat primary color would would you like to add to the end of the list?\n";

			// Get a primary color from the user and store is into colorChoice.
			colorChoice = getPrimColor();

			// Add a node to the end of the list with the colorChoice stored as it's value.
			primaryColors.appendNode(colorChoice);

			break;

		case 2:

			// Customer color prompt for inserting a color to the list.
			cout << "\nWhat color would you like to insert into the list?\n";

			// Get a primary color from the user and store is into colorChoice.
			colorChoice = getPrimColor();

			// Customer position prompt for inserting a color to the list.
			cout << "\nWhat position would you like to insert the color into the list?\n";

			// Get the desired node position and store it into position.
			position = getPosition();

			// Run insertNode function with user position and color input, and store it into trueFalse.
			trueFalse = primaryColors.insertNode(position, colorChoice);

			// If the deleteNode function returns -1, display fail message.
			if (trueFalse == -1)
			{
				cout << "\n**I'm sorry but there is no position " << position << " in the linked list.\n";
			}

			break;

		case 3:

			// Customer position prompt for deleting a node in the list.
			cout << "\nWhat is the position of the color you would like to delete in the list?\n";

			// Get the desired node position to be deleted from the list.
			position = getPosition();

			// Run deleteNode function with user position input, and store it into trueFalse.
			trueFalse = primaryColors.deleteNode(position);

			// If the deleteNode function returns -1, display fail message.
			if (trueFalse == -1)
			{
				cout << "\n**I'm sorry but there is no position " << position << " in the linked list.\n";
			}

			break;

		case 4:

			// Print the current list.
			primaryColors.displayList();

			break;

		case 5:

			// Reverse the order of the primaryColors object using the reverseOrder member function.
			primaryColors.reverseOrder();

			break;

		case 6:

			// Clear the buffer.
			cin.clear();
			cin.ignore(10, '\n');

			// Prompt the user for a value they wish to search for and store the input to colorChoice.
			cout << "\nEnter a color that you want to search the list for. Input must match origional input (case sensitive): ";
			getline(cin, colorChoice);

			// Search for the input value in the linked list and store the returned position into trueFalse.
			trueFalse = primaryColors.searchList(colorChoice);

			// If the deleteNode function returns -1, display fail message.
			if (trueFalse == -1)
			{
				cout << "\n**I'm sorry but '" << colorChoice << "' was not found in the linked list.\n";
			}

			break;

		default:

			// If 1-6 are not selected, prompt the user for a vaild input from the menu.
			cout << "\nError '" << menuChoice() << "' is not on the menu.\n";
			cout << "Please enter a valid number (1-6)\n";

			break;
		}

	} while (contProgram());

	return 0;
}