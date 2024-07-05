// KCRON.cpp : Defines the exported functions for the DLL.
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include "method.h"
#include <iostream>

KCronTime_C* parseTimeString(const char* timeStr, int lineNums)
{
	std::cout << "输入了" << timeStr << std::endl;
	std::cout << "行数为" << lineNums << std::endl;
	return nullptr;
}
