#include "App.h"

bool App::LoadParams(int argc, char *argv[])
{
	/*���������� ������� ����������� ��������� ������*/
	args.reserve(argc);

	for (int i = 1; i < argc; i++)
	{
		string s(argv[i]);
		args.push_back(s);
	}

	/* ����� ���������� �������*/
	int succesed = 0;

	for (auto i : commands)
	{
		if (i->CheckSignature(args))
		{
			/*������ ��������� ������� ���������� ��������*/
			active = i;
			succesed++;
			break;
		}
	}

	if (!succesed) return false; /*������� �� �������*/
	else return true;
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