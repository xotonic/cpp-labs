#include "unitTester.h"
#include <iostream>

unitTester::unitTester()
{
}

bool unitTester::test()
{
	int a = 3, b = 2;
	Number n(a, b);
	Number m(a, b);

	n.add(m);
	//n.add(m);
	//n.add(m);
	if (!((n.getNum() == 3) && (n.getDen() == 1)))
	{
		std::cout << n.getNum() << "/" << n.getDen() << std::endl;
		return 0;
	}

	n.substract(m);
	if (!((n.getNum() == 3) && (n.getDen() == 2)))
	{
		std::cout << n.getNum() << "/" << n.getDen() << std::endl;
		return 0;
	}

	n.multiply(Number(1, 1));
	if (!((n.getNum() == 3) && (n.getDen() == 2)))
	{
		std::cout << n.getNum() << "/" << n.getDen() << std::endl;
		return 0;
	}

	n.divide(Number(3, 2));
	if (!((n.getNum() == 1) && (n.getDen() == 1)))
	{
		std::cout << n.getNum() << "/" << n.getDen() << std::endl;
		return 0;
	}

	return 1;
}

unitTester::~unitTester()
{
}