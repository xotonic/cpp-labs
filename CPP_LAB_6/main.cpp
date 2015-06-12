#include <iostream>
#include "Number.h"
#include "App.h"
#include "BasicCommands.h"
#include "VectorCommands.h"
#include "Exceptions.h"
using namespace std;

int main(int argc, char *argv[])
{
	try {
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

		app.LoadParams(argc, argv);
		
		cout << app.Compute() << endl;
	}
	catch (StringException& se) { cout << "Exception : \n" << se.what() << endl; }
	catch (Exception& e) { cout << "Exception : \n" << e.what() << endl; }
	system("PAUSE");
	return 0;
}