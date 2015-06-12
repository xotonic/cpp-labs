#include "App.h"

void App::LoadParams(int argc, char *argv[])
{
	/*Заполнение вектора аргументами командной строки*/
	args.clear();
	args.reserve(argc);

	for (int i = 1; i < argc; i++)
	{
		string s(argv[i]);
		args.push_back(s);
	}

	/* Поиск подходящей команды*/
	int succesed = 0;

	for (auto i : commands)
	{
		if (i->CheckSignature(args))
		{
			/*первая найденная команда становится активной*/
			active = i;
			succesed++;
			break;
		}
	}

	if (!succesed) return throw StringException(__LINE__, __FILE__, __FUNCTION__, 
		"Operations for such args not found"); /*Команды не найдено*/
	
}

std::string App::Compute()
{
	if (active->GetName() != "History")
	{
		ofstream os("recent.txt", ios::app);

		for (auto i : args)
			os << i << ' ';

		os << active->GetResult() << endl;
	}

	return active->GetResult();
}

void App::addCommand(Command* c)
{
	commands.push_back(c);
}