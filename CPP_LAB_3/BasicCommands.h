#pragma once
#include "Command.h"
#include "Number.h"
#include <fstream>

class Add :
	public Command
{
private:
	Number a, b;
public:
	 bool CheckSignature(const std::vector<std::string>& str);
	 std::string GetResult();
	 std::string GetName() { return "Add"; }
};

class Substract :
	public Command
{
private:
	Number a, b;
public:
	 bool CheckSignature(const std::vector<std::string>& str);
	 std::string GetResult();
	 std::string GetName() { return "Substract"; }
};

class Multiply :
	public Command
{
private:
	Number a, b;
public:
	 bool CheckSignature(const std::vector<std::string>& str);
	 std::string GetResult();
	 std::string GetName() { return "Multiply"; }
};

class Divide :
	public Command
{
private:
	Number a, b;
public:
	 bool CheckSignature(const std::vector<std::string>& str);
	 std::string GetResult();
	 std::string GetName() { return "Divide"; }
};

class History :
	public Command
{
public:
	 bool CheckSignature(const std::vector<std::string>& str);
	 std::string GetResult();
	 std::string GetName() { return "History"; }
};