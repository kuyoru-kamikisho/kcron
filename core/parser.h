#pragma once
#include <string>
#include <iterator>
#include <iostream>
#include "appInfo.h"

class Parser
{
public:
	const int _requireMin = 8;
	int _outNum = 1;
	char _mode;
	char _year;
	char _month;
	char _day;
	char _week;
	char _hours;
	char _minutes;
	char _seconds;

	void loadParams(int size, char* params[]);
};