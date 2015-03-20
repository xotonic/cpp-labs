#include <iostream>
#include "Number.h"
#include "unitTester.h"
#include "AdvParamReader.h"


int main(int argc, char *argv[]) 
{
	
	/* unit тестирование*/
	unitTester ut;

	if (!ut.test()) std::cout << "unit test: WRONG NUMBERS COMPUTING" << std::endl;

	/* чтение аргументов командной строки*/
	AdvParamReader pr;
	pr.CheckParams(argc, argv);
	
	Number a = pr.getFirst(), b = pr.getSecond();

	switch (pr.operation)
	{
	case pr.add: a.add(b); break;
	case pr.sub: a.substract(b); break;
	case pr.mul: a.multiply(b); break;
	case pr.div: a.divide(b); break;
	case pr.invalid: std::cout << "wrong command" << std::endl; break;
	}

	/*вывод*/
	std::cout << a.getNum() << "/" << a.getDen() << std::endl;

	system("PAUSE");
	return 0;
}