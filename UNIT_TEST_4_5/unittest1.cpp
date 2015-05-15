#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\CPP_LAB_4\Number.h"
#include "..\CPP_LAB_4\Number.cpp"
#include "..\CPP_LAB_4\VectorCommands.h"
#include "..\CPP_LAB_4\VectorCommands.cpp"
#include "..\CPP_LAB_4\App.h"
#include "..\CPP_LAB_4\App.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UNIT_TEST_4_5
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(Number_methods)
		{
			Number c(1, 1);

			Assert::AreEqual<int>(1, c.getNum(), L"numerator in constructor");
			Assert::AreEqual<int>(1, c.getDen(), L"denominator in constructor");
			Assert::AreEqual<std::string>("1/1", c.toString(), L"converting to string");

			int a = 3, b = 2;
			Number n(a, b);
			Number m(a, b);

			n.add(m);
			Assert::AreEqual<std::string>("3/1", n.toString(), L"add operation");

			n.substract(m);
			Assert::AreEqual<std::string>("3/2", n.toString(), L"sub operation");

			n.multiply(m);
			Assert::AreEqual<std::string>("9/4", n.toString(), L"mul operation");

			n.divide(m);
			Assert::AreEqual<std::string>("3/2", n.toString(), L"div operation");

			n = Number(100, 10);
			n.reduce();
			Assert::AreEqual<std::string>("10/1", n.toString(), L"reduce");
		}

		TEST_METHOD(Number_reloaded_operators)
		{
			Number a = Number(1, 1) + Number(1, 1);
			Assert::AreEqual<std::string>("2/1", a.toString(), L"add operator");

			Number b = Number(10, 3) - Number(6, 3);
			Assert::AreEqual<std::string>("4/3", b.toString(), L"sub operator");

			std::stringstream os;
			os << a << " " << b;
			Assert::AreEqual<std::string>("2/1 4/3", os.str(), L"stream output");

			Number a1, b1;
			os >> a1 >> b1;
			Assert::AreEqual<std::string>("2/1", a1.toString(), L"stream input");
			Assert::AreEqual<std::string>("4/3", b1.toString(), L"stream input");
		}

		TEST_METHOD(Vector_commands)
		{
			
				App app;
				AddVector av;

				app.addCommand(&av);
				char *argv[] = { "azaza.exe", "--add",
					"[", "1/1", "1/2", "1/1", "]",
					"[", "1/2", "1/1", "1/2", "]" };
				app.LoadParams(12, argv);

				Assert::AreEqual<std::string>("[ 3/2 3/2 3/2 ]", app.Compute(), L"add vector");

				SubstractVector sv;
				app.addCommand(&sv);
				argv[1] = "--sub";
				app.LoadParams(12, argv);

				Assert::AreEqual<std::string>("[ 1/2 -1/2 1/2 ]", app.Compute(), L"sub vector");
			
		}
	};
}