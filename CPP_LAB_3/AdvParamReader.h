#pragma once
#include "ParamReader.h"
class AdvParamReader : public ParamReader
{
public:
	 bool CheckParams(int argc, char *argv[]);
};

