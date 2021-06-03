#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include "Test.h"
#include<string>

MyClass::MyClass(ptr k):k(k)
{

}
MyClass::~MyClass()
{

}
int MyClass::ExcK()
{
	k(10);
	return 5;
}

MyClass * CreateObject(ptr k)
{
	MyClass* me = new MyClass(k);
	return	me;
}

int __stdcall ExcK(MyClass* obj)
{
	 int a = obj->ExcK();
	return a;
}