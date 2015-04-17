#pragma once
#include "ParamReader.h"
class AdvParamReader : public ParamReader
{
public:
	void  CheckParams(int argc, char *argv[]);
};
