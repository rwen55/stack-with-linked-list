#include "Stack.h"

int main() {
	// initializing the stack
	Stack* stack1 = new Stack;
	cout << "Creating a New Stack:" << endl;
	// pushing values into the stack
	stack1->push(0);
	stack1->push(1);
	stack1->push(2);
	stack1->push(3);
	stack1->push(4);
	stack1->push(5);
	// printing the contents of the stack
	stack1->print();
	// printing the top element and the size of the stack
	cout << "The current top element of the stack: " << stack1->top() << endl; 
	cout << "The size of the stack: " << stack1->size() << endl << endl;
	// popping the top element out of the stack and printing the new top and size of the stack
	stack1->pop();
	cout << "Printing the Stack After Popping Once:" << endl;
	stack1->print();
	cout << "The current top element of the stack: " << stack1->top() << endl;
	cout << "The size of the stack: " << stack1->size() << endl << endl;
	// reversing the order of the stack and printing it
	stack1->reverse();
	cout << "Printing the Stack After Reversing:" << endl;	
	stack1->print();
	// checking if the stack contains a specific element
	int find = 2;
	stack1->contains(find)
		? cout << "The stack contains " << find << "." << endl << endl
		: cout << "The stack does not contain " << find << "." << endl << endl;
	// peeking at the element in a specific index
	int index = 3;
	stack1->peek(index) != -1
		? cout << "The element in index " << index << ": " << stack1->peek(index) << endl << endl
		: cout << "The stack does not contain this index." << endl << endl;
	// using toArray to initialize an array using our stack
	int* array = stack1->toArray();
	cout << "Printing the Stack as an Array:" << endl;
	for (int i = 0; i < stack1->size(); i++)
		cout << array[i] << '\t';
	cout << endl << endl;
	// finding the minimum and maximum elements of the stack
	cout << "The minimum element of the stack: " << stack1->min() << endl;
	cout << "The maximum element of the stack: " << stack1->max() << endl << endl;
	// duplicating the top element of the stack
	stack1->duplicate();
	cout << "Printing the Stack after Duplicating the First Element:" << endl;
	stack1->print();
	// clearing the stack
	stack1->clear();
	cout << "Printing the Stack After Clearing:" << endl;
	stack1->print();
}