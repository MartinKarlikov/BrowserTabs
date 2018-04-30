#pragma once
#include <ctime>
#include <iostream>

using namespace std;

//Just a node struct. This will be the most "primitive" structure that we will use.
// It's just the base element for our structure. Holds a pointer to the next and previous node
//and some basic data
struct Node
{
	~Node()
	{
		delete[] url;
	}
	char* url;
	time_t timeStamp;
	Node* prev;
	Node* next;

};

//This is our DoublyLinked List structure. Pretty standard
class DoubleLinkedList
{

public:
	//A constructor to ensure our 1 element that we must always have- a "about:blank" tab
	// And a destructor for our url pointers and nodes that are allocated dynamically
	DoubleLinkedList();
	~DoubleLinkedList();

	//This is our Iterator for the doubly linked list
	class Iterator;

	//the typical functions for the list structure
	void load(Iterator current, char* p);
	void insert(Iterator& current, char* p);
	void remove(Iterator& current);

	Node* getFirst() const;

	void reloadUrl(char* p, Iterator it);

	void print(Iterator current);

	//our sorting algorithm, well known 
	Node* mergeSort(Node * head, int type);

	//function that moves the pointer to the first element, in case the sort stirs them up
	void setFirst(Iterator current);

	//the list creating a iterator itself
	Iterator getIterator() const;

private:

	// some helper functions and other necessary for our sorting algorithm
	Node* beg;

	Node* createNode(char* p);
	bool nodeCmp(Node* first, Node* second, int type);

	Node* merge(Node* first, Node* second, int type);
	Node* split(Node* head);

};

//Iterator for a doubly linked list structure
class DoubleLinkedList::Iterator
{
public:
	//friend class enabling us to use private data from the list. Example the head pointer - 'beg'
	friend class DoubleLinkedList;

	// basic construcors
	Iterator();
	Iterator(Node* other);

	//asignment operators both for another NodePtr or a "primitive" node
	Iterator& operator=(Node* other);
	Iterator& operator=(const Iterator& other);

	//decrement operators , both prefix and postfix
	Iterator& operator--();
	Iterator operator--(int);

	//increment operators , both prefix and postfix
	Iterator& operator++();
	Iterator operator++(int);

	//some useful bool operators
	bool operator==(const Iterator& other) const;
	bool operator!=(const Iterator& other) const;
	operator bool() const;

	//dereference operator
	Node& operator*() const;

	//function telling us if the iterator has reached the last element of the list
	bool atEnd() const;

private:

	//pointer to a node element
	//this iterator could have a pointer to the list , but for this assignemnt 
	// it isn't neccessary as we use only one list
	Node* curr;
};