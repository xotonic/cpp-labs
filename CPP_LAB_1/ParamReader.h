#pragma once
#include <string>
#include <sstream>
#include "Number.h"
using std::istringstream;

class ParamReader
{
public:
	ParamReader();
	enum operationType { add, sub, mul, div, invalid }; /*тип операции*/
	operationType operation;
	virtual void CheckParams(int argc, char *argv[]);
	Number getFirst(); /*получить первый параметр*/
	Number getSecond(); /*получить второй параметр*/
	~ParamReader();

private:
	Number first, second;
};

