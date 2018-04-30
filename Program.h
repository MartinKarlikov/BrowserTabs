#pragma once
#include "BrowserTabs.h"

//copy function for two char* variables
char* copyString(char* toCopy);

//compare funtion for the input commands
int commandCmp(char* p);

//--parses the input and turns it into a command--
//funtion that according to the comparison of the
// command comparison function tells the commandExecution function
// which procedure to call
void commandHandler(char* p,BrowserTabs& tabs);

//executes the right command, sent by the command handler
void commandExecution(int type,char* p, BrowserTabs& tabs);

//main function logic
void Engine(BrowserTabs& tabs);