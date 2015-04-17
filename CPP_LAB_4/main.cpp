#include <iostream>
#include "Number.h"
#include "unitTester.h"
#include "App.h"
#include "BasicCommands.h"
#include "VectorCommands.h"
using namespace std;

int main(int argc, char *argv[])
{
	/* unit тестирование*/
	unitTester ut;
	if (!ut.test()) cout << "Unit test: wrong numbers computing" << endl;

	/* чтение аргументов командной строки*/

	App app;

	Add add;
	Substract sub;
	Multiply mul;
	Divide div;
	History his;

	AddVector addv;
	SubstractVector subv;

	app.addCommand(&add);
	app.addCommand(&sub);
	app.addCommand(&mul);
	app.addCommand(&div);
	app.addCommand(&his);

	app.addCommand(&addv);
	app.addCommand(&subv);

	if (!app.LoadParams(argc, argv))
	{
		cout << "Operations for such args not found" << endl;
		system("PAUSE");
		return 0;
	}

	cout << app.Compute() << endl;

	system("PAUSE");
	return 0;
}