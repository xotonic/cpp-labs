#pragma once

#include "Command.h"
#include "Number.h"
#include <fstream>
#include <vector>



class AddVector :
	public Command
{
private:
	std::vector<Number> sum;

public:
	bool CheckSignature(const std::vector<std::string>& str);
	std::string GetResult();
	std::string GetName() { return "Add Vector"; }
};

class SubstractVector :
	public Command
{
private:
	std::vector<Number> sum;

public:
	bool CheckSignature(const std::vector<std::string>& str);
	std::string GetResult();
	std::string GetName() { return "Substract Vector"; }
};