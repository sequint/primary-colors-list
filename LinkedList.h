// Specficication file for a class template holding a linked list.

#ifndef NUMBERLIST_H
#define NUMBERLIST_H
#include <string>
using namespace std;

class LinkedList
{
private:
	// Declare list structure.
	struct ListNode
	{
		string value;			// Variable that holds the value of the node.
		struct ListNode* next;  // Pointer variable which points to the next node.
	};

	ListNode* head;				// Starting node for the linked list.

public:
	// Default Constructor
	LinkedList()
	{
		// Initialize starting node to a null address.
		head = nullptr;
	}

	// Destructor
	~LinkedList();

	// Linked list operations
	void appendNode(string);
	int insertNode(int, string);
	void reverseOrder();
	int deleteNode(int);
	void displayList() const;
	int searchList(string);
};
#endif
