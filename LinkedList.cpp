// Implementation file for a class template holding a linked list.

#include <iostream>
#include <string>
#include "LinkedList.h"
#include "functions.h"
using namespace std;


//*************************************************************************************************
// ~LinkedList Destructor									  *
//												  *
// The destructor moves through the list starting at the head and deletes each node of the list.  *
//*************************************************************************************************

LinkedList::~LinkedList()
{
	ListNode* nodePtr = head;      // To traverse the list starting at the head.
	ListNode* nextNode = nullptr;  // To point to the next node.

	// While nodePtr is not at the end of the list, delete content of the node, and point to the next node.
	while (nodePtr != nullptr)
	{
		// Point nextNode to the next node using the next member variable of the current node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Point nodePtr to the next node.
		nodePtr = nextNode;
	}
}

//*************************************************************************************************
// appendNode Function										  *
//												  *
// This function takes a value as an argurment and adds a new node to the end of the linked list  *
// with that value stored in it.								  *
//*************************************************************************************************

void LinkedList::appendNode(string colorChoice)
{
	ListNode* newNode = nullptr;  // To point to a new node.
	ListNode* nodePtr = head;     // To traverse the list starting at the head.

	// Allocate a new node and store the value of the passed variable there.
	newNode = new ListNode;
	newNode->value = colorChoice;

	// Make the next node pointed to null.
	newNode->next = nullptr;

	// If the list is empty, make newNode the first node.
	if (!head)
	{
		head = newNode;

		// Print a confirmation message.
		cout << "\nThe color '" << colorChoice << "' has been added to the end of the list.\n";
	}
	// Otherwise, insert NewNode at the end of the list.
	else
	{
		// Traverse the list to find the last node.
		// Do this by testing if the node's "next pointer" is empty, and setting nodePtr to that address if it is not.
		while (nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}

		// Make the new node the last node in the list.
		nodePtr->next = newNode;

		// Print a confirmation message.
		cout << "\nThe color '" << colorChoice << "' has been added to the end of the list.\n";
	}
}

//*************************************************************************************************
// insertNode Function										  *
//												  *
// This function takes a value as an argument and inserts a new node into a position in the list  *
// that the user has chosen, given that the head node is position '0'.				  *
//*************************************************************************************************

int LinkedList::insertNode(int position, string colorChoice)
{
	ListNode* newNode = nullptr;              // To point to a new node.
	ListNode* nodePtr = head;                 // To traverse the list starting at the head.
	ListNode* previousNode = nullptr;         // To point to the previous node.
	int counter = 0;						  // Counter variable to count iterations passed as the list is traversed.

	// Allocate a new node and store the value of the passed variable there.
	newNode = new ListNode;
	newNode->value = colorChoice;

	// If the list is empty, return a -1 status.
	if (!head)
	{
		return -1;
	}
	// Else, if position is at the head of the list, make the colorChoice the new head and return 1.
	else if (counter == position)
	{
		head = newNode;
		newNode->next = nodePtr;

		// Print a confirmation message.
		cout << "\nThe color in '" << colorChoice << "' has been placed into position '" << position << "' of the list.\n";

		return 1;
	}
	// Otherwise, continuing moving through the list to see if the position is in the list.
	else
	{
		// Initialize the nodePtr to the head node.
		nodePtr = head;

		// While the counter is not equal to the desired node to be deleted, continue the traverse.
		while (counter != position)
		{
			// If the nodePtr is pointing beyond the list, break the loop.
			if (nodePtr == nullptr)
			{
				break;
			}
			// Otherwise, traverse the list and increment the counter.
			else
			{
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
				counter++;
			}
		}

		// If the desired position was found in the list, insert the new node after the previous node, which will now be the position passed into the function.
		if (nodePtr)
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;

			// Print a confirmation message.
			cout << "\nThe color in '" << colorChoice << "' has been placed into position '" << position << "' of the list.\n";

			return 1;
		}
		// Otherwise, return a -1 flag to indicate that the desired node position was not found within the list.
		else
		{
			return -1;
		}
	}
}

//*************************************************************************************************
// reverseOrder Function									  *
//												  *
// This function reverses a linked lists order by traversing the list and reversing the next	  *
// pointer in each node to point to the previous node instead, and make the last node the head.   *
//*************************************************************************************************

void LinkedList::reverseOrder()
{
	ListNode* nodePtr = head;          // To traverse the list starting at the head node.
	ListNode* nextNode = nullptr;      // Points to the next node in the list after nodePtr;
	ListNode* previousNode = nullptr;  // Points to the node before nodePtr;

	// While nodePtr is not null, reverse the nodes pointer and traverse the list.
	while (nodePtr)
	{
		// Point nextNode to the next node from nodePtr's current position.
		nextNode = nodePtr->next;

		// Reverse the node next pointer to point to the previous node.
		nodePtr->next = previousNode;

		// Begin the traverse by pointing previousNode to the current node (nodePtr).
		previousNode = nodePtr;

		// Continue the traverse by pointing nodePtr to nextNode.
		nodePtr = nextNode;
	}

	// Replace the linked list head with the last node in the list,
	// which is now stored in the previousNode pointer.
	head = previousNode;

	// Print a confirmation message that the list has been reversed.
	cout << "\nYour list has been reversed!\n";
}

//*************************************************************************************************
// deleteNode Function										  *
//												  *
// This function takes a value as an argument, then searches the list for that value.  When a     *
// node is found who's member value variable matches the value passed, that node is deleted.	  *
//*************************************************************************************************

int LinkedList::deleteNode(int position)
{
	ListNode* nodePtr = nullptr;       // To traverse the list.
	ListNode* previousNode = nullptr;  // Points to the previous node in the list.
	int counter = 0;				   // Counter variable to count iterations passed as the list is traversed.

	// If the list is empty, return a -1 status.
	if (!head)
	{
		return -1;
	}
	// Else, if the user wishes to delete the first node, point to the next node, delete the head node, and make the nodePtr the new head node.
	// Return a 1 to flag that the node position exists within the list.
	else if (counter == position)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;

		// Print a confirmation of node deletion message.
		cout << "\nThe color in position '" << position << "' has been deleted.\n";

		return 1;
	}
	// Otherwise, continuing moving through the list to find see if the position passed is in the list.
	else
	{
		// Initialize the nodePtr to the first node of the list.
		nodePtr = head;

		// While the counter is not equal to the desired node to be deleted, continue the traverse.
		while (counter != position)
		{
			// If the nodePtr is pointing beyond the list, break the loop.
			if (nodePtr == nullptr)
			{
				break;
			}
			// Otherwise, traverse the list and increase the counter by 1.
			else
			{
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
				counter++;
			}	
		}

		// If the desired position was found in the list, delete that node and point the previous node to the next node.
		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;

			// Print a confirmation of node deletion message.
			cout << "\nThe color in position '" << position << "' has been deleted.\n";

			return 1;
		}
		// Otherwise, return a -1 flag to indicate that the desired node position was not found within the list.
		else
		{
			return -1;
		}
	}
}

//*************************************************************************************************
// displayList Function										  *
//												  *
// This function traverses through the linked list and displays each node in the list.		  *
//*************************************************************************************************

void LinkedList::displayList() const
{
	ListNode* nodePtr = head;  // To traverse the list starting at the head.

	// Title message for the displayed list.
	cout << "\nYour Primary Color List\n\n";

	// While the pointer points to a node, display the node and traverse the list.
	while (nodePtr)
	{
		// Display the number stored in the node.
		cout << "- " << nodePtr->value << "\n";

		// Point to the next node.
		nodePtr = nodePtr->next;
	}
}

//*************************************************************************************************
// searchList Function										  *
//												  *
// This function searches the list for a value equal to the one passed into the function and	  *
// returns the values position in the list. If it is not in the list it returns -1.		  *
//*************************************************************************************************

int LinkedList::searchList(string color)
{
	ListNode* nodePtr = nullptr;       // To traverse the list.
	ListNode* previousNode = nullptr;  // Points to the previous node in the list.
	int counter = 0;				   // Counter variable to count iterations passed as the list is traversed.

	// If the list is empty, return a -1 status.
	if (!head)
	{
		return -1;
	}
	// Otherwise, continuing moving through the list to find find a match.
	else
	{
		// Initialize the nodePtr to the first node of the list.
		nodePtr = head;

		// While nodePtr is not beyond the list and the counter is not equal to value in the node, continue to traverse the list.
		while (nodePtr != nullptr && color != nodePtr->value)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
			counter++;

		}

		// If a match was found return the counter and display a found message.
		if (nodePtr)
		{
			cout << "\nThe first iteration of '" << color << "' was found in position '" << counter << "'.\n";

			return counter;
		}
		// Otherwise, return a -1 flag to indicate that the value passed is not in the list.
		else
		{
			return -1;
		}
	}
}
