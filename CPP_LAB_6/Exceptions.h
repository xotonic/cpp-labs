#pragma once
#include <string>
#include <sstream>
#include "Number.h"
#include "Command.h"

using namespace std;

class Exception
{
public:
	Exception(int _line, string _file = "unknown", string _func = "unknown"):
	line(_line), file(_file), func(_func){}

	string what()
	{
		ostringstream os;
		os << "Line : " << line <<
			"\nFile : " << file <<
			"\nFunction : " << func << endl;

		return os.str();
	}
private:
	int line;
	string file, func;
};

class StringException : Exception
{
	string n;
public:
	StringException(int _line, string _file, string _func, string num)
		: Exception(_line, _file, _func), n(num) {}
	string what()
	{
		ostringstream os;
		os << Exception::what();
		os << "String : " << n;
		return os.str();
	}
};