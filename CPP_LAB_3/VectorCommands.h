#pragma once

#include "Command.h"
#include "Number.h"
#include <fstream>
#include <vector>

// ����������
const Number& operator+(Number& n, Number& m)
{
	Number k = n;
	k.add(m);
	return k;
}

const Number& operator-(Number& n, Number& m)
{
	Number k = n;
	k.substract(m);
	return k;
}

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