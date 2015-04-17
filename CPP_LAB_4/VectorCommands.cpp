#include "VectorCommands.h"

bool AddVector::CheckSignature(const std::vector<std::string>& str)
{
	if (str.size() <= 3) return false;

	if (str[0] != "--add") return false;

	if ((str.size() - 1) % 2 == 1) return false;

	int nums_count = (str.size() - 1) / 2;

	sum.reserve(nums_count);

	auto it = str.begin();

	for (it++; it != str.end(); it += 2)
	{
		Number a = ParseNumber(*it);
		Number b = ParseNumber(*it++);
		Number r = a + b;
		sum.push_back(r);
	}
	return true;
}

std::string AddVector::GetResult()
{
	std::ostringstream s;
	for (auto i : sum) s << ' ' << i.toString();
	return s.str();
}

//////////////////

bool SubstractVector::CheckSignature(const std::vector<std::string>& str)
{
	if (str.size() <= 3) return false;

	if (str[0] != "--sub") return false;

	if ((str.size() - 1) % 2 == 1) return false;

	int nums_count = (str.size() - 1) / 2;

	sum.reserve(nums_count);

	auto it = str.begin();

	for (it++; it != str.end(); it += 2)
	{
		Number a = ParseNumber(*it);
		Number b = ParseNumber(*it++);
		sum.push_back(a - b);
	}
	return true;
}

std::string SubstractVector::GetResult()
{
	std::ostringstream s;
	for (auto i : sum) s << ' ' << i.toString();
	return s.str();
}