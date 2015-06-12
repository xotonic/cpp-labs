#pragma once
#include <string>
#include <sstream>
#include "Exceptions.h"
class Number
{
public:
	Number(int numerator = 0, int denominator = 1) : num(numerator), den(denominator) {}

	int getNum() const { return num; }
	int getDen() const { return den; }
	void setNum(int pnum)	{ num = pnum; }
	void setDen(int pden)	{ den = pden; }
	void add(Number); /*сложение*/
	void substract(Number); /*вычитание*/
	void multiply(Number); /*умнжение*/
	void divide(Number); /*деление*/
	void reduce(); /* упрощение дроби*/

	std::string toString() const;

	static Number parse(std::string str);
	
	friend	std::ostream& operator<<(std::ostream &output, const Number &p) {
		output << p.toString();
		return output;
		}
	friend	std::istream& operator>>(std::istream &input, Number &p) {
		int n, d; char slash;
		input >> n >> slash >> d;
		p.setNum(n); p.setDen(d);
		return input;
		}
		
	Number& operator+(Number& n)
	{
		this->add(n);
		return *this;
	}

	Number& operator-(Number& n)
	{
		this->substract(n);
		return *this;
	}

private:
	int num, /*числитель*/
		den; /*знаменатель*/
};
