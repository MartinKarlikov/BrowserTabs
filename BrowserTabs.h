#pragma once
#include "DoubleLL.h"

//This is our main structure. It holds both the list and it's iterator and works with both 
// for the purpose of the asignment
class BrowserTabs
{
public:
	// a constructor to ensure that the iterator will start from the first element- "about:blank"
	BrowserTabs();

	//Wraped functions of the list structure
	void printElements() const;
	void forward();
	void back();

	void load(char* p);
	void insert(char* p);
	void remove();

	void sort(int type);
	
private:

	//A list instance and it's pointer
	DoubleLinkedList tabList;
	DoubleLinkedList::Iterator tabPointer;
};