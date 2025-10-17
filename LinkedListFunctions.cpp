/*
	Program will print a singly-linked list backwards
	Creates the node class
	Creates Node* data type functions to allow the caller to access the full list of nodes
	Creates void functions to print and delete the list
*/

#include <iostream>
#include <string>

using namespace std;

// Create Node class 
class Node {

public:
	char c; // Character to be stored in node variable
	Node* next; // Pointer to next node in list

	// constructor
	Node() { c = ' '; next = nullptr; }

	//parametrized constructor
	Node(char value) { c = value; next = nullptr; }
};

// Function will recieve a string input and return a pointer to the start of the created list
Node* buildList(string& input)
{
	Node* start{ nullptr };
	Node* end{ nullptr };
	Node* temp{ nullptr };

	// Create and append new node for each character in input
	for (char ch : input)
	{
		temp = new Node(ch); // Create a new node for the character
		if (start == nullptr) // If this is first character, set start to it
		{
			start = temp;
		}
		else
		{
			end->next = temp; // Otherwise, link the previous end 
		}
		end = temp; // Update end pointer to new node
	}
	return start; // Return pointer to the start of the list
}

// Function will recieve a pointer to a singly-linked list, reverse the order, and return the pointer to the updated list
Node* reverseList(Node* start)
{
	Node* current{ start };
	Node* prev{ nullptr };
	Node* temp{ nullptr };

	while (current != nullptr)
	{
		temp = current->next; // Save temp pointer to the node after current
		current->next = prev; // Make current->next point to the previous node
		prev = current; // Advance previous into current
		current = temp; // Advance current into temp
	}
	return prev; // Return list reversed
}

// Function will print the list given
void static printList(Node* start)
{
	Node* current{ start }; // Start at the given node
	while (current != nullptr)
	{
		cout << current->c; // Print current node
		current = current->next; // Advance to next node
	}
	cout << endl;
}

// Function will delete all nodes in the list given
void static deleteList(Node* start)
{
	while (start != nullptr)
	{
		Node* temp = start->next; // Store next node in temp
		delete start; // Delete the current node
		start = temp; // Move to the next node
	}
}

void main()
{
	string input;
	cout << "Please enter a string and I will reverse it: ";
	getline(cin, input);

	Node* start = buildList(input); // start now points to beginning of new list
	Node* reversedString = reverseList(start); // reversedString now points to the reversed list

	cout << "Reversed string: ";
	printList(reversedString); // Print the reversed list

	deleteList(reversedString); // Delete the created nodes
}