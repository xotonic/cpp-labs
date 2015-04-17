#include "ParamReader.h"

ParamReader::ParamReader() : first(), second() {}

void ParamReader::CheckParams(int argc, char *argv[])
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

	//apaapapapap
	input.clear();
	input.str(argv[2]);

	int a, b;
	char dummy;
	input >> a >> dummy >> b;

	first = Number(a, b);

	input.clear();
	input.str(argv[3]);
	input >> a;

	second = Number(a, 1);
}

Number ParamReader::getFirst()
{
	return first;
}
Number ParamReader::getSecond()
{
	return second;
}

ParamReader::~ParamReader() {}