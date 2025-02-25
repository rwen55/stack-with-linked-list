#pragma once

#include <iostream>

using namespace std;

class node {
public:
	int data; // holds the value of the node
	node* next; // holds the address of the next node
	node() { data = 0; next = nullptr; } // constructor to initialize an empty node
	node(int v, node* next_node) { this->data = v; this->next = next_node; } // constructor to initialize a desired node
};

class Stack {
public:
	// constructor + deconstructor
	Stack();
	~Stack();
	// void functions
	void push(int);
	void pop();
	void clear();
	void print();
	void reverse();
	void duplicate();
	// int returning functions
	int top();
	int size();
	int peek(int);
	int* toArray();
	int min();
	int max();
	// bool returning functions
	bool isEmpty();
	bool contains(int);
	// pointer for the top of the stack
	node* head;
};