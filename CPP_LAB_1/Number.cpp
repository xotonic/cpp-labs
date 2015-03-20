#include "Number.h"


Number::Number(int numerator, int denominator) : num(numerator), den(denominator)
{
}

int Number::getNum()
{
	return num;
}

int Number::getDen()
{
	return den;
}

void Number::reduce()
{
		int x = (num<den) ? num : den;
		for (int i = 2; i <= x; i++)
			if ((num%i == 0) && (den%i) == 0)
			{
				num /= i;
				den /= i;
				i = 1;
			}
			
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
	//reduce();
	

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
	//reduce();
}
void Number::multiply(Number n)
{
	num *= n.getNum();
	den *= n.getDen();
	reduce();
	reduce();
}
void Number::divide(Number n)
{
	num *= n.getDen();
	den *= n.getNum();
	reduce();
	//reduce();
}

bool Number::setNum(int pnum)
{
	num = pnum;
	return true;
}
bool Number::setDen(int pden)
{
	den = pden;
	return true;
}

Number::~Number(){}
