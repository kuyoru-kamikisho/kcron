// KCRON.h - Contains declarations of math functions
#pragma once
#include <string>
#include <vector>

#ifdef KCRON_EXPORTS
#define KCRON_API __declspec(dllexport)
#else
#define KCRON_API __declspec(dllimport)
#endif

typedef struct KCronTime_C
{
	int Y;
	int M;
	int D;
	int w;
	int h;
	int m;
	int s;
} KCronTime_C;

/// <summary>
/// 解析日期字符串
/// </summary>
/// <param name="timeStr">符合kcron规范的时间字符串</param>
/// <param name="lineNums">需要的结果数量，默认为一条</param>
/// <returns>返回一集合，形式为[ 年 月 日 周 时 分 秒 ]的对象集合，JSON格式</returns>
extern "C" KCRON_API KCronTime_C* parseTimeString(const char* timeStr, int lineNums);
