#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <list>
#include "Command.h"
#include "Number.h"
#include "Exceptions.h"
using namespace std;

class App
{
public:
	App() {};
	void LoadParams(int argc, char *argv[]);
	string Compute();
	void addCommand(Command* c);
	~App() {};
private:

	Command* active;
	list<Command*> commands;
	vector<string> args;
};
