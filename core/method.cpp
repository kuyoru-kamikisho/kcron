﻿// w[=100] z[=200] c[=300]
// KCRON.cpp : Defines the exported functions for the DLL.
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include "method.h"
#include <iostream>

KCronTime_C* parseTimeString(const char* timeStr, int lineNums)
{
	KCronTime_C* array = (KCronTime_C*)malloc(lineNums * sizeof(KCronTime_C));
	if (array == NULL) {
		return NULL;
	}

	int params[8] = { 0,0,0,0,0,0,0,0 };
	int param_index = -1;
	bool mark_add = false;
	bool month_mved = false;

	char* next_token = NULL;
	char* timeStrCopy = _strdup(timeStr);
	char* token = strtok_s(timeStrCopy, " ", &next_token);

	time_t T;
	struct tm newTime;
	time(&T);
	localtime_s(&newTime, &T);

	while (token != NULL) {
		param_index += 1;
		char* tmpStr = token;
		token = strtok_s(NULL, " ", &next_token);
		if (strcmp(tmpStr, "w") == 0)
		{
			param_index = 0;
			params[param_index] = 100;
			continue;
		}
		else if (strcmp(tmpStr, "z") == 0) {
			param_index = 0;
			params[param_index] = 200;
			continue;
		}
		else if (strcmp(tmpStr, "c") == 0) {
			param_index = 0;
			params[param_index] = 300;
			continue;
		}
		else if (strcmp(tmpStr, "-") == 0) {
			params[param_index] = params[0] == 200 ? -100 : 0;
			continue;
		}
		else if (strcmp(tmpStr, "+") == 0)
		{
			if (params[0] == 200 && param_index == 3)
			{
				mark_add = true;
				// + 标识符存在的情况下星期设置将被跳过
				params[param_index] = 15;
				param_index++;
				params[4] = -100;
				token = strtok_s(NULL, " ", &next_token);
			}
			else {
				fprintf(stderr, "Mark [+] can only be used in [z] flag and must be placed at [day] index.");
				return NULL;
			}
			continue;
		}
		params[param_index] = std::stoi(tmpStr);
	}

	if (param_index != 7)
	{
		std::string errorMessage = "Invalid string length, the params length your inputed is " + std::to_string(param_index + 1) + ".\n";
		fprintf(stderr, errorMessage.c_str());
		return NULL;
	}

	for (size_t i = 0; i < lineNums; i++)
	{
		tm resultSingle;
		if (params[0] == 100 || params[0] == 300)
		{
			resultSingle = timeAfter(&newTime, params[1], params[2], params[3], params[4], params[5], params[6], params[7]);
		}
		else if (params[0] == 200) {
			if (mark_add)
			{
				int a = params[1] > 0 ? params[1] : newTime.tm_year + 1900;
				int b = params[2] > 0 ? params[2] : newTime.tm_mon + 1;
				if (!month_mved && params[2] <= 0 && params[5] >= 0 && params[6] >= 0 && params[7] >= 0)
				{
					newTime.tm_mon -= 1;
					month_mved = true;
				}
				else
				{
					b++;
				}
				params[3] = getDaysInMonth(a, b);
			}
			resultSingle = timeAt(&newTime, params[1], params[2], params[3], params[4], params[5], params[6], params[7]);
		}
		array[i].Y = resultSingle.tm_year + 1900;
		array[i].M = resultSingle.tm_mon + 1;
		array[i].D = resultSingle.tm_mday;
		array[i].w = resultSingle.tm_wday;
		array[i].h = resultSingle.tm_hour;
		array[i].m = resultSingle.tm_min;
		array[i].s = resultSingle.tm_sec;
	}

	return array;
}

void freeResult(KCronTime_C* arr)
{
	free(arr);
}

tm timeAfter(struct tm* T, int Y, int M, int D, int w, int h, int m, int s)
{
	T->tm_sec += s;
	T->tm_min += m;
	T->tm_hour += h;
	T->tm_mday += D + (w * 7);
	T->tm_mon += M;
	T->tm_year += Y;

	mktime(T);

	return *T;
}

tm timeAt(tm* T, int Y, int M, int D, int w, int h, int m, int s)
{
	if (s >= 0)
	{
		T->tm_sec = s;
	}
	else {
		T->tm_sec += 1;
	}
	if (m >= 0)
	{
		T->tm_min = m;
	}
	else
	{
		if (s >= 0)
		{
			T->tm_min += 1;
		}
	}
	if (h >= 0)
	{
		T->tm_hour = h;
	}
	else
	{
		if (s >= 0 && m >= 0)
		{
			T->tm_hour += 1;
		}
	}
	if (w <= 0)
	{
		if (D > 0)
		{
			T->tm_mday = D;
		}
		else
		{
			if (s >= 0 && m >= 0 && h >= 0)
			{
				T->tm_mday += 1;
			}
		}
	}
	else
	{
		if (D > 0)
		{
			// 当星期与日两个参数同时不为空时，日将转换为星期几，星期将转换为第几个星期
			T->tm_mday = getDateByYMwd(T->tm_year + 1900, T->tm_mon + 1, w, D);
		}
		else {
			// 假如现在周三（2），要求周五 5 差2天 5-3
			// 假如现在周三（2），要求周一 1 差5天 1+7-3
			// 假如现在周三（2），要求周三 3 差0天
			auto x = T->tm_wday;
			auto a = w >= x ? w - x : w + 7 - x;
			if (a == 0 && h >= 0 && m >= 0 && s >= 0)
			{
				T->tm_mday += 7;
			}
			else
			{
				T->tm_mday += a;
			}
		}
	}
	if (M > 0)
	{
		T->tm_mon = M - 1;
	}
	else
	{
		if (s >= 0 && m >= 0 && h >= 0 && D > 0)
		{
			T->tm_mon += 1;
		}
	}
	if (Y > 0)
	{
		T->tm_year = Y - 1900;
	}
	else
	{
		if (s >= 0 && m >= 0 && h >= 0 && D > 0 && M > 0)
		{
			T->tm_year += 1;
		}
	}
	mktime(T);
	return *T;
}

int isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		return 1;
	}
	else {
		return 0;
	}
}

int getDaysInMonth(int year, int month)
{
	if (month == 2) {
		return isLeapYear(year) ? 29 : 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	else {
		return 31;
	}
}

int getDateByYMwd(int year, int month, int weekNum, int weekday)
{
	struct tm timeinfo = { 0 };
	timeinfo.tm_year = year - 1900;
	timeinfo.tm_mon = month - 1;
	timeinfo.tm_mday = 1;
	timeinfo.tm_hour = 12;

	mktime(&timeinfo);
	int dayOfFirtDate = timeinfo.tm_wday;
	int offset = (weekday - dayOfFirtDate + 7) % 7;
	if (weekNum > 1) {
		offset += (weekNum - 1) * 7;
	}
	timeinfo.tm_mday += offset;
	mktime(&timeinfo);

	return timeinfo.tm_mday;
}
