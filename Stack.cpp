#include "Stack.h"

// constructor to initialize an empty stack
Stack::Stack() : head(nullptr) {};

Stack::~Stack() { // deconstructor to clear memory
	node* current = head; // initializing current and temp to head and the 2nd node
	node* temp = current->next;

	while (current != nullptr) { // while loop to iterate through the stack until it reaches the end (null) and all nodes have been deleted
		delete current; // delete the element pointed to by current
		current = temp; // move current to temp (the node ahead of it)
		temp = current->next; // move temp to the next node
	}
	head = nullptr; // set head to nullptr, declares the stack to be empty
}

void Stack::push(int value) { // function to push a value to the top of the stack
	if (head == nullptr) // checks if the stack is empty
		head = new node(value, nullptr); // adds the first node of the stack and points head to it
	else {
		node* top = new node(value, head); // creating a new top node
		head = top; // setting head to the newly created top node
	}
}

void Stack::pop() { // function to pop the top element out of the stack
	if (head == nullptr) // checks if the stack is empty (no nodes to pop)
		exit(0);

	node* current = head; // initialize current to the head
	head = head->next; // move head to the next node
	delete current; // pop out the top node
}

void Stack::clear() { // function to clear the stack
	node* current = head; // initializing the current and temp to the first and second nodes
	node* temp = current->next;

	while (current != nullptr) { // while loop to iterate through the stack and delete every node
		delete current; // deletes the current node
		current = temp; // moves current to the next node
		if (current != nullptr) // if the list isn't empty, move temp to the next node
			temp = current->next;
	}
	head = nullptr; // set head to nullptr to declare the list empty
}

void Stack::print() { // function to print the stack
	if (head == nullptr) { // checks if the stack is empty
		cout << "The stack is empty." << endl;
		exit(0);
	}
	node* current = head; // initializing current to head

	while (current != nullptr) { // while loop to iterate through the stack and print the elements vertically
		cout << current->data << endl;
		current = current->next; // move current to the next node after printing
	}
	cout << "NULL" << endl << endl; // print NULL at the end of the stack
}

void Stack::reverse() { // function to reverse the stack
	node* current = head; // initializing current and left to the head
	node* left = head;
	node* right = head->next; // initialzing right to the 2nd node

	while (right != nullptr) { // while loop to iterate through the stack until nullptr
		node* left = new node(right->data, head); // initialize a copy of the node pointed by right to the top of the stack
		head = left; // move head to the new top node
		right = right->next; // move right to the next node
	}
	current->next = nullptr; // set current's next node to nullptr, thus cutting off the stack
}

void Stack::duplicate() { // function to duplicate the top element and add it to the stack
	this->push(head->data);
}

int Stack::top() { // function to print the top element of the stack
	return head->data;
}

int Stack::size() { // function to return the size of the stack
	int count = 0; // use count to keep track of the size
	node* current = head; // initialize current to the head

	while (current != nullptr) { // while loop to iterate through the stack and count the nodes
		count++;
		current = current->next;
	}
	return count; // return the size of the stack
}

int Stack::peek(int index) { // function to return the element of the stack at a given index
	if (this->size() < index || index < 0) // checks if the given index is valid for our stack
		return -1;

	node* current = head; // initialize current to head
	for (int i = 0; i < index; i++) // for loop to find the node of the given index
		current = current->next;

	return current->data; // return the data at the given index
}

int* Stack::toArray() { // function to return the stack as an array
	if (head == nullptr) { // checks if the stack is empty
		int* array = new int; // creates an empty array and returns it
		return array;
	}
	int* array = new int[this->size()]; // creating an array with the same size as the stack
	node* current = head; // initialize current to head and the counting index
	int i = 0;

	while (current != nullptr) { // while loop to iterate through the stack and copy the stack's elements to the array
		array[i] = current->data;
		i++;
		current = current->next;
	}
	return array; // returns the newly copied array
}

int Stack::min() { // function to return the minimum value of the stack
	if (head == nullptr) { // checks if the stack is empty
		cout << "The stack is empty." << endl;
		exit(0);
	}
	node* current = head->next; // set current to the 2nd node of the stack
	int min = head->data; // set min to the value of the 1st node

	while (current != nullptr) { // iterate through the stack and check each node to find the min value
		if (current->data < min) // replaces min's data with the current node's data if it's lower
			min = current->data;
		current = current->next;
	}
	return min; // return the minimum value
}

int Stack::max() { // function to return the maximum value of the stack
	if (head == nullptr) { // checks if the stack is empty
		cout << "The stack is empty." << endl;
		exit(0);
	}
	node* current = head->next; // set current to the 2nd node of the stack
	int max = head->data; // set max to the value of the 1st node

	while (current != nullptr) { // iterate through the stack and check each node to find the max value
		if (current->data > max) // replaces max's data with the current node's data if it's greater
			max = current->data;
		current = current->next;
	}
	return max; // return the maximum value
}

bool Stack::isEmpty() { // function to check if the stack is empty
	if (head == nullptr) // if the head == nullptr, the stack is empty
		return true;
	else // if it isn't nullptr, the stack has values
		return false;
}

bool Stack::contains(int value) { // function to check if the stack contains a given value
	if (head == nullptr) // checks if the function is empty
		return false; // if the function is empty, it can't contain the given value

	node* current = head; // initialize current to head

	while (current != nullptr) { // while loop to iterate through the stack and check if it contains the value
		if (current->data == value) // if the current node contains the value, return true
			return true;
		current = current->next;
	}
	return false; // if the while loop completes without returning, the stack doesn't have the value
}