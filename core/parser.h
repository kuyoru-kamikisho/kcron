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

	/// <summary>
	/// 解析字符串的主要函数
	/// </summary>
	/// <param name="size">字符串参数的个数</param>
	/// <param name="params">字符串参数数组</param>
	void loadParams(int size, char* params[]);

	/// <summary>
	/// 根据字符串是否是“-”修改参数source的值
	/// </summary>
	/// <param name="source">被缓存的计算值</param>
	/// <param name="value">命令行参数的值</param>
	void resolver(int* source, std::string value);
};