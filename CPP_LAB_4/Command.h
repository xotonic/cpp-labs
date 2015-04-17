#pragma once
#include <sstream>
#include <string>
#include <vector>
#include "Number.h"

class Command
{
public:

	virtual bool CheckSignature(const std::vector<std::string>& str) = 0;

	virtual std::string GetResult() = 0;

	virtual std::string GetName() = 0;

protected:
	Number ParseNumber(std::string str)
	{
		std::stringstream s(str);

		int x, y;
		char slash;
		s >> x >> slash >> y;

		return Number(x, y);
	}
};
