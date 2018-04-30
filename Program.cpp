#include "Program.h"

//copy function
char* copyString(char* toCopy)
{
	size_t size = strlen(toCopy) + 1;
	char* p = new char[size];
	strcpy_s(p, size, toCopy);

	return p;
}

//command comparison function
int commandCmp(char* p)
{

	if (strcmp(p, "GO") == 0)
	{
		return 1;
	}

	if (strcmp(p, "INSERT") == 0)
	{
		return 2;
	}

	if (strcmp(p, "BACK") == 0)
	{
		return 3;
	}

	if (strcmp(p, "FORWARD") == 0)
	{
		return 4;
	}

	if (strcmp(p, "REMOVE") == 0)
	{
		return 5;
	}

	if (strcmp(p, "PRINT") == 0)
	{
		return 6;
	}

	if (strcmp(p, "SORT") == 0)
	{
		return 7;
	}

	return -1;
}

//input to command parser
void commandHandler(char* p, BrowserTabs& tabs)
{
	char* run = p;

	if (run[0] != '$' || run[1] != ' ')
	{
		cout << "Unkown command! -Missing '$' ?" << endl;
		return;
	}

	run += 2;
	char buffer[20];
	int offset = 0;

	for (int i = 0; run[i] != ' ' && run[i]; ++i)
	{

		buffer[i] = run[i];
		++offset;
	}

	buffer[offset] = '\0';
	run += offset;

	int type = commandCmp(buffer);

	if (!strcmp(run,"") || !strcmp(run," "))
	{
		commandExecution(type, "about:blank", tabs);
		return;
	}

	commandExecution(type,++run, tabs);

}

//executes the parsed commands
void commandExecution(int type,char* run ,BrowserTabs& tabs)
{

	if (type == 0)
	{
		cout << "Unknown command!" << endl;
	}

	if (type == 1)
	{
		char* url = copyString(run);

		tabs.load(url);

		delete[] url;
		return;
	}

	if (type == 2)
	{
		char* url = copyString(run);

		tabs.insert(url);

		delete[] url;
		return;
	}

	if (type == 3)
	{
		tabs.back();
		return;
	}

	if (type == 4)
	{
		tabs.forward();
	}

	if (type == 5)
	{
		tabs.remove();
	}

	if (type == 6)
	{
		tabs.printElements();
	}

	if (type == 7)
	{
		char* sortBy = copyString(run);

		if (strcmp(sortBy, "TIME") == 0)
		{
			tabs.sort(1);
		}
		else if (strcmp(sortBy, "URL") == 0)
		{
			tabs.sort(2);
		}
		else
		{
			cout << "Unknown command!" << endl;
		}
		delete[] sortBy;
		return;
	}

	if (type == -1)
	{
		cout << "Unknown command!" << endl;
	}

}


void Engine(BrowserTabs& tabs)
{

	char buffer[1024];

	while (true)
	{
		cin.getline(buffer, 1024);

		if (strcmp(buffer, "$ EXIT") == 0)
		{
			return;
		}

		char* command = copyString(buffer);

		commandHandler(command, tabs);

		delete[] command;
	}
}
