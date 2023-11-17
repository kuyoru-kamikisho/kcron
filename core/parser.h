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
	std::string _mode;
	int _year;
	int _month;
	int _day;
	int _week;
	int _hours;
	int _minutes;
	int _seconds;

	void loadParams(int size, char* params[]);
};