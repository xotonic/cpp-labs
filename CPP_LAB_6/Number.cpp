#include "Number.h"

void Number::reduce()
{
	int x = (num < den) ? num : den;
	for (int i = 2; i <= x; i++)
		if ((num%i == 0) && (den%i) == 0)
		{
			num /= i;
			den /= i;
			i = 1;
		}
}

std::string Number::toString() const
{
	std::ostringstream s;
	s << getNum() << '/' << getDen();

	return s.str();
}

Number Number::parse(std::string str)
{
	std::istringstream s(str);
	int x, y;
	char slash;
	s >> x >> slash >> y;

	if (y == 0)
	throw StringException(__LINE__, __FILE__, __FUNCTION__, "Denominator is null");

	return Number(x, y);
}

void Number::add(Number n)
{
	int x = n.getNum();
	int y = n.getDen();
	num *= y;
	x *= den;
	den *= y;
	num += x;
	reduce();
}
void Number::substract(Number n)
{
	int x = n.getNum();
	int y = n.getDen();
	num *= y;
	x *= den;
	den *= y;
	num -= x;
	reduce();
}
void Number::multiply(Number n)
{
	num *= n.getNum();
	den *= n.getDen();
	reduce();
}
void Number::divide(Number n)
{
	num *= n.getDen();
	den *= n.getNum();
	
	if (den == 0) throw StringException(__LINE__, __FILE__, __FUNCTION__, "Division by zero");

	reduce();
}