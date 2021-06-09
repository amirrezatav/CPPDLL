#include "Calculator.h"
#include <iostream>
typedef int (*TestFunction)(std::string);
TestFunction testfunction;

void Res(std::string str)
{
	std::cout << str << std::endl;
}
int CallBack()
{
	testfunction("Hello In DLL");
	return 0;
}
int main()
{
	Calculator cal(Res);
	std::cout <<  cal.SUM(4, 5) << std::endl; 
	cal.MULT(4,5,Res);
}