#include "Calculator.h"
Calculator::Calculator(Result func) :func(func)
{

}
Calculator::~Calculator()
{
}
int Calculator::SUM(int a, int b)
{
	func("Hello In Sum");
	return a + b;
}
int Calculator::MINE(int a, int b)
{
	return a - b;
}
int Calculator::DIVIDE(int a, int b)
{
	return a / b;
}
void Calculator::MULT(int a, int b, Result Func)
{
	Func(std::to_string(a / b).c_str());
}