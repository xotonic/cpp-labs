#pragma once
#include <string>
#include <sstream>
class Number
{
public:
	Number(int numerator = 0, int denominator = 1);
	void add(Number); /*сложение*/
	void substract(Number); /*вычитание*/
	void multiply(Number); /*умнжение*/
	void divide(Number); /*деление*/

	bool setNum(int pnum);
	bool setDen(int pden);

	int getNum(); /* получить числитель */
	int getDen(); /*получить знаменатель*/

	void reduce(); /* упрощение дроби*/

	std::string toString();

	~Number();
private:
	int num, /*числитель*/
		den; /*знаменатель*/
};
