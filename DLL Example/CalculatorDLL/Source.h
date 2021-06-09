#pragma once
#include "Calculator.h"
#include <iostream>

#ifdef UIAPI
#define UIAPI __declspec(dllexport)
#else
#define UIAPI  __declspec(dllimport)
#endif // DEBUG

typedef int (*TestFunction)(std::string);
TestFunction testfunction;

extern "C" UIAPI Calculator* CreateObject(Result res);
extern "C" UIAPI int SUM(Calculator*, int a, int b);
extern "C" UIAPI int MINE(Calculator*, int a, int b);
extern "C" UIAPI int DIVIDE(Calculator*, int a, int b);
extern "C" UIAPI void MULT(Calculator*, int a, int b, Result Func);
extern "C" UIAPI  void Start(TestFunction testFunction);
int CallBack();
void Test();
