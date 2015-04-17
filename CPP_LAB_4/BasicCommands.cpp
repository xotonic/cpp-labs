#include "BasicCommands.h"

bool Add::CheckSignature(const std::vector<std::string>& str)
{
	if (str.size() != 3) return false;

	if (str[0] != "--add") return false;

	a = ParseNumber(str[1]);
	b = ParseNumber(str[2]);

	return true;
}

std::string Add::GetResult()
{
	Number c = a;
	c.add(b);

	return c.toString();
}

bool Substract::CheckSignature(const std::vector<std::string>& str)
{
	if (str.size() != 3) return false;

	if (str[0] != "--sub") return false;

	a = ParseNumber(str[1]);
	b = ParseNumber(str[2]);

	return true;
}

std::string Substract::GetResult()
{
	Number c = a;
	c.substract(b);

	return c.toString();
}

bool Multiply::CheckSignature(const std::vector<std::string>& str)
{
	if (str.size() != 3) return false;

	if (str[0] != "--mul") return false;

	a = ParseNumber(str[1]);
	b = ParseNumber(str[2]);

	return true;
}

std::string Multiply::GetResult()
{
	Number c = a;
	c.multiply(b);

	return c.toString();
}

bool Divide::CheckSignature(const std::vector<std::string>& str)
{
	if (str.size() != 3) return false;

	if (str[0] != "--div") return false;

	a = ParseNumber(str[1]);
	b = ParseNumber(str[2]);

	return true;
}

std::string Divide::GetResult()
{
	Number c = a;
	c.divide(b);

	return c.toString();
}

bool History::CheckSignature(const std::vector<std::string>& str)
{
	if (str.size() != 1) return false;

	if (str[0] != "--recent") return false;

	return true;
}

std::string History::GetResult()
{
	std::ifstream is("recent.txt");

	if (is)
	{
		std::stringstream buffer;
		buffer << is.rdbuf();
		return buffer.str();
	}
	else
		return "error loading recent.txt";
}