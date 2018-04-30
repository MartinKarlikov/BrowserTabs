#include "BrowserTabs.h"

//normal constructor. Initializes the iterator using the list function
BrowserTabs::BrowserTabs()
{ 
	tabPointer = tabList.getIterator();
}

//wrapped print function
void BrowserTabs::printElements() const
{
	tabList.print(tabPointer);
}

//wrapped forward function using the iterator increment operator
void BrowserTabs::forward()
{
	++tabPointer;
}

//wrapped back function using the iterator decrement operator
void BrowserTabs::back()
{
	--tabPointer;
}

//wrapped load function
void BrowserTabs::load(char* p)
{
	tabList.load(tabPointer, p);
}

//wrapped insert function
void BrowserTabs::insert(char * p)
{
	tabList.insert(tabPointer, p);
}

//wrapped remove funtion
void BrowserTabs::remove()
{	
	tabList.remove(tabPointer);
}

//wrapped sort funtion
//sets the right first element of the list
void BrowserTabs::sort(int type)
{

	tabPointer = tabList.mergeSort(tabList.getFirst(),type);
	tabList.setFirst(tabPointer);
	tabPointer = tabList.getFirst();

}


