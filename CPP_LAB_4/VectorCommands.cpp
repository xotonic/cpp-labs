#include "VectorCommands.h"

bool AddVector::CheckSignature(const std::vector<std::string>& str)
{
	if (str.size() <= 3) return false;

	if (str[0] != "--add") return false;

	if ((str.size() - 1) % 2 == 1) return false;

	int nums_count = (str.size() - 5) / 2;

	sum.reserve(nums_count);

	std::vector<Number> v1, v2;
	v1.reserve(nums_count);
	v2.reserve(nums_count);

	auto it = str.begin();
	it++;

	if (*it != "[") return false;
	it++;
	while (*it != "]")
	{
		v1.push_back(Number::parse(*it));
		it++;
	}
	it++;

	if (*it != "[") return false;
	it++;
	while (*it != "]")
	{
		v2.push_back(Number::parse(*it));
		it++;
	}

	for (int i = 0; i < nums_count; i++)
	{
		Number s = v1[i] + v2[i];
		sum.push_back(s);
	}

	return true;
}

std::string AddVector::GetResult()
{
	std::ostringstream s;
	s << "[";
	for (auto i : sum) s << ' ' << i;
	s << " ]";
	return s.str();
}

//////////////////

bool SubstractVector::CheckSignature(const std::vector<std::string>& str)
{
	if (str.size() <= 3) return false;

	if (str[0] != "--sub") return false;

	if ((str.size() - 1) % 2 == 1) return false;

	int nums_count = (str.size() - 5) / 2;

	sum.reserve(nums_count);

	std::vector<Number> v1, v2;
	v1.reserve(nums_count);
	v2.reserve(nums_count);

	auto it = str.begin();
	it++;

	if (*it != "[") return false;
	it++;
	while (*it != "]")
	{
		v1.push_back(Number::parse(*it));
		it++;
	}
	it++;

	if (*it != "[") return false;
	it++;
	while (*it != "]")
	{
		v2.push_back(Number::parse(*it));
		it++;
	}

	for (int i = 0; i < nums_count; i++)
	{
		Number s = v1[i] - v2[i];
		sum.push_back(s);
	}

	return true;
}

std::string SubstractVector::GetResult()
{
	std::ostringstream s;
	s << "[";
	for (auto i : sum) s << ' ' << i;
	s << " ]";
	return s.str();
}