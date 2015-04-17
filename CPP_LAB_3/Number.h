#pragma once
#include <string>
#include <sstream>
class Number
{
public:
	Number(int numerator = 0, int denominator = 1);
	void add(Number); /*��������*/
	void substract(Number); /*���������*/
	void multiply(Number); /*��������*/
	void divide(Number); /*�������*/

	bool setNum(int pnum);
	bool setDen(int pden);

	int getNum(); /* �������� ��������� */
	int getDen(); /*�������� �����������*/

	void reduce(); /* ��������� �����*/

	std::string toString();

	~Number();
private:
	int num, /*���������*/
		den; /*�����������*/
};
