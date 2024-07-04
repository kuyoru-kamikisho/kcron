// KCRON.h - Contains declarations of math functions
#pragma once
#include <string>
#include <vector>

#ifdef KCRON_EXPORTS
#define KCRON_API __declspec(dllexport)
#else
#define KCRON_API __declspec(dllimport)
#endif

extern "C" KCRON_API class KCronTime
{
public:
	/// 年份
	int Y;
	/// 月份
	int M;
	/// 日期
	int D;
	/// 星期，0为周日
	int w;
	/// 小时
	int h;
	/// 分钟
	int m;
	/// 秒
	int s;
};

/// <summary>
/// 解析日期字符串
/// </summary>
/// <param name="timeStr">符合kcron规范的时间字符串</param>
/// <param name="lineNums">需要的结果数量，默认为一条</param>
/// <returns>返回一集合，形式为[ 年 月 日 周 时 分 秒 ]的对象集合，JSON格式</returns>
extern "C" KCRON_API std::vector<KCronTime> parseTimeString(std::string timeStr,int lineNums);
