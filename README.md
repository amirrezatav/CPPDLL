# Create and use your own Dynamic Link Library (C++)
## Prerequisites
+ A computer that runs Microsoft Windows 7 or later versions. We recommend Windows 10 for the best development experience.
+ A copy of Visual Studio. For information on how to download and install Visual Studio, see Install Visual Studio. When you run the installer, make sure that the Desktop development with C++ workload is checked. Don't worry if you didn't install this workload when you installed Visual Studio. You can run the installer again and install it now.

![](https://docs.microsoft.com/en-us/cpp/build/media/desktop-development-with-cpp.png?view=msvc-160)

+ An understanding of the basics of using the Visual Studio IDE. If you've used Windows desktop apps before, you can probably keep up. For an introduction, see Visual Studio IDE feature tour.
+ An understanding of enough of the fundamentals of the C++ language to follow along. Don't worry, we don't do anything too complicated.
## Create the DLL project
In this set of tasks, you create a project for your DLL, add code, and build it. To begin, start the Visual Studio IDE, and sign in if you need to. The instructions vary slightly depending on which version of Visual Studio you're using. Make sure you have the correct version selected in the control in the upper left of this page.
### To create a DLL project in Visual Studio 2019
1. On the menu bar, choose File > New > Project to open the Create a New Project dialog box.

![](https://docs.microsoft.com/en-us/cpp/build/media/create-new-dll-project-2019.png?view=msvc-160)

2. At the top of the dialog, set Language to C++, set Platform to Windows, and set Project type to Library.
3. From the filtered list of project types, select Dynamic-link Library (DLL), and then choose Next.
4. In the Configure your new project page, enter MathLibrary in the Project name box to specify a name for the project. Leave the default Location and Solution name values. Set Solution to Create new solution. Uncheck Place solution and project in the same directory if it's checked.
5. Choose the Create button to create the project.

```hpp
// test.h
#pragma once

#ifdef Mode
#define Mode __declspec(dllexport)
#else
#define Mode __declspec(dllimport)
#endif

extern "C" Mode Your_Function_Definition();
```
and 
```cpp
// test.cpp
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include "test.h" 

Your_Function_Implementation();
```
