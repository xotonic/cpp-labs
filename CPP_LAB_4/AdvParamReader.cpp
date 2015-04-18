#include "AdvParamReader.h"


bool AdvParamReader::CheckParams(int argc, char *argv[])
{
	istringstream input(argv[1]);
	std::string command;

	input >> command;

	if (command == "--add")
		operation = add;
	else if (command == "--sub")
		operation = sub;
	else if (command == "--mul")
		operation = mul;
	else if (command == "--div")
		operation = div;
	else operation = invalid;


	input.clear();
	input.str(argv[2]);

	int a, b;
	char dummy;
	input >> a >> dummy >> b;

	setFirst(Number(a, b));

	input.clear();
	input.str(argv[3]);
	input >> a >> dummy >> b;

	setSecond(Number(a, b));

	return true;
}

