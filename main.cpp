#include "Program.h"
#include <Windows.h>


int main()
{
	BrowserTabs tabs;
	//Engine(tabs);



	//a little benchmark i left to check how fast it can add millions of elements
	//and sorts them afterwards..
	// typically around 20 seconds in release mode and 40 in debug modå
	time_t begin, end;

	DoubleLinkedList::Iterator;
	for (size_t i = 1; i <15'100'000; ++i)
	{

		size_t size = log10(i) + 1;
		char* temp = new char[size + 1];
		_itoa_s(i,temp, size+1, 10);
		
		tabs.insert(temp);
		delete[] temp;

	}

	begin = time(NULL);
	tabs.sort(2);
	end = time(NULL);
	cout << end - begin << endl;

	return 0;
}