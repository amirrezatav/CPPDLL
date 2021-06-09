#include <string>
#ifndef CALCULATOR_H
#define CALCULATOR_H

typedef void (*Result)(std::string res);

class Calculator
{
public:
	Result func;
	Calculator(Result);
	~Calculator();
	int SUM(int a, int b);
	int MINE(int a, int b);
	int DIVIDE(int a, int b);
	// std::string MULT(int a, int b);
	void MULT(int a, int b , Result);
};
#endif // !CALCULATOR_H
