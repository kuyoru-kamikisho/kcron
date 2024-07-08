// KCRON.h - Contains declarations of math functions
#pragma once
#include <string>
#include <vector>

#ifdef KCRON_EXPORTS
#define KCRON_API __declspec(dllexport)
#else
#define KCRON_API __declspec(dllimport)
#endif

/// <summary>
/// 年
/// 月[1-12]
/// 日[1-31]
/// 周[0-6]
/// 时[0-23]
/// 分[0,59]
/// 秒[0,59]
/// </summary>
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
/// <returns>返回一个集合，形式为[ 年 月 日 周 时 分 秒 ]的对象集合，JSON格式</returns>
extern "C" KCRON_API KCronTime_C * parseTimeString(const char* timeStr, int lineNums);

/// <summary>
/// 标识符转换为数字
/// 比如将“-”转换为 0 或其它情况
/// </summary>
int identifierResolver(std::string);

/// <summary>
/// 将“parseTimeString”的结果产生的内存释放掉
/// </summary>
/// <param name="arr">parseTimeString的结果</param>
extern "C" KCRON_API void freeResult(KCronTime_C * arr);

/// <summary>
/// 以输入的时间为基准，返回
/// Y年M月D日w周h时m分s秒
/// [之后]的时间
/// </summary>
extern "C" KCRON_API struct tm timeAfter(struct tm* T, int Y, int M, int D, int w, int h, int m, int s);

/// <summary>
/// 以输入的时间为基准，返回
/// Y年M月D日w周h时m分s秒
/// [正点]的时间
/// </summary>
extern "C" KCRON_API struct tm timeAt(struct tm* T, int Y, int M, int D, int w, int h, int m, int s);

/// <summary>
/// 判断是否闰年
/// </summary>
/// <param name="year">年份</param>
/// <returns>1代表闰年，0代表平年</returns>
extern "C" KCRON_API int isLeapYear(int year);

/// <summary>
/// 获取某年某月的天数
/// </summary>
extern "C" KCRON_API int getDaysInMonth(int year, int month);

/// <summary>
/// 根据星期和年月份计算指定月份第N个星期几的日期
/// </summary>
/// <param name="year">年份</param>
/// <param name="month">月份[1-31]</param>
/// <param name="week">星期，月份的第几周[1-5]</param>
/// <param name="weekday">星期几[1-7]</param>
/// <returns>[1-31]</returns>
extern "C" KCRON_API int getDateByYMwd(int year, int month,int weekNum,int weekday);
