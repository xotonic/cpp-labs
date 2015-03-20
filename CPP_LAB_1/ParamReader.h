#pragma once
#include <string>
#include <sstream>
#include "Number.h"
using std::istringstream;

class ParamReader
{
public:
	ParamReader();
	enum operationType { add, sub, mul, div, invalid }; /*��� ��������*/
	operationType operation;
	virtual void CheckParams(int argc, char *argv[]);
	Number getFirst(); /*�������� ������ ��������*/
	Number getSecond(); /*�������� ������ ��������*/
	~ParamReader();

private:
	Number first, second;
};

