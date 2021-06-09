#include "pch.h"
#include "Source.h"
int CallBack()
{
	testfunction("Hello In DLL");
	return 0;
}
void Test()
{
	CallBack();
}
void Start(TestFunction testFunction)
{
	testfunction = testFunction;
	Test();
}
Calculator* CreateObject(Result res)
{
	Calculator* cal = new Calculator(res);
	return cal;
}
int SUM(Calculator* cal, int a, int b)
{
	return cal->SUM(a, b);
}
int MINE(Calculator* cal, int a, int b)
{
	return cal->MINE(a, b);
}
int DIVIDE(Calculator* cal, int a, int b)
{
	return cal->DIVIDE(a, b);
}
void MULT(Calculator* cal, int a, int b, Result Func)
{
	cal->MULT(a, b, Func);
}