#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <list>
#include "Command.h"
#include "Number.h"
using namespace std;

class App
{
public:
	App() {};
	bool LoadParams(int argc, char *argv[]);
	string Compute();
	void addCommand(Command* c);
	~App() {};
private:
	
	Command* active;
	list<Command*> commands;
	vector<string> args;
};

