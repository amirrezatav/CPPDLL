#pragma once
#include<string>

#ifdef Mode
	#define Mode __declspec(dllexport) 
#else
	#define Mode __declspec(dllimport) 
#endif 

typedef void(__stdcall *ptr)(int a);

class MyClass
{
public:
	MyClass(ptr k);
	~MyClass();
	ptr k;
	int ExcK();
};


extern "C" Mode MyClass* CreateObject(ptr k);
extern "C" Mode  int __stdcall ExcK(MyClass*);