#pragma once
#include <ctime>
#include <chrono>

/// <summary>
/// 日期工具类
/// 所有方法它的参数不应该传递负值
/// </summary>
class JDate
{
private:
	time_t _time;
	tm _ctm;
public:
	JDate() {
		_time = time(0);
		localtime_s(&_ctm, &_time);
	};
	int getYear() {
		return _ctm.tm_year + 1900;
	};
	int getMonth() {
		return _ctm.tm_mon;
	};
	int getDate() {
		return _ctm.tm_mday;
	};
	int getDay() {
		return _ctm.tm_wday;
	};
	int getHours() {
		return _ctm.tm_hour;
	};
	int getMinutes() {
		return _ctm.tm_min;
	};
	int getSeconds() {
		return _ctm.tm_sec;
	};
	long long getInitTime() {
		return _time;
	};
	auto getMilliseconds() {
		// 构建时间点
		std::chrono::system_clock::time_point tp = std::chrono::system_clock::time_point(std::chrono::seconds(0));

		// 设置日期和时间
		tp += std::chrono::hours(getHours());
		tp += std::chrono::minutes(getMinutes());
		tp += std::chrono::seconds(getSeconds());

		// 构建日期
		std::tm tm = {};
		tm.tm_year = getYear() - 1900;
		tm.tm_mon = getMonth();
		tm.tm_mday = getDate();

		// 将日期转换为时间点
		std::time_t time = std::mktime(&tm);
		tp += std::chrono::system_clock::from_time_t(time).time_since_epoch();

		// 转换为毫秒数
		auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch());

		return milliseconds;
	}

	/// <summary>
	/// 获得当前日期处于该月的第几周
	/// </summary>
	int getNumWeek() {
		return (_ctm.tm_mday + getDayOfFirst() - 1) / 7 + 1;
	}

	/// <summary>
	/// 获取当月第一天的星期
	/// </summary>
	int getDayOfFirst() {
		tm t = makeT(_ctm.tm_year, _ctm.tm_mon, 1);
		return t.tm_wday;
	}

	/// <summary>
	/// 获取某年某月的总天数
	/// </summary>
	/// <param name="y">年份</param>
	/// <param name="m">月份</param>
	/// <returns>该月的总天数</returns>
	int getMdayNum(int y, int m) {
		bool leap = isLeapYear(y);
		int mday = 30;
		if (m == 0 || m == 2 || m == 4 || m == 6 || m == 7 || m == 9 || m == 11)
		{
			mday = 31;
		}
		if (m == 1)
		{
			if (leap)
			{
				mday = 29;
			}
			else {
				mday = 28;
			}
		}
		return mday;
	}

	/// <summary>
	/// 设置年份
	/// </summary>
	/// <param name="v">只接受大于等于0的整数</param>
	void setYear(int v) {
		_ctm.tm_year = v - 1900;
		setDate(getDate());
	};
	/// <summary>
	/// 设置月份
	/// </summary>
	/// <param name="v">只接受大于等于0的整数</param>
	void setMonth(int v) {
		if (v > 11)
		{
			_ctm.tm_mon = v / 11 - 1;
			setYear(v % 11 + getYear());
		}
		else {
			_ctm.tm_mon = v;
		}
	};
	/// <summary>
	/// 设置日期
	/// </summary>
	/// <param name="v">只接受大于等于0的整数</param>
	void setDate(int v) {
		int mday = getMdayNum(getYear(), getMonth());
		if (v > mday)
		{
			setMonth(getMonth() + 1);
			setDate(v - mday);
		}
		else {
			tm t = makeT(_ctm.tm_year, _ctm.tm_mon, v);
			_ctm.tm_mday = v;
			_ctm.tm_wday = t.tm_wday;
		}
	};

	/// <summary>
	/// 设置小时
	/// </summary>
	/// <param name="v">只接受大于等于0的整数</param>
	void setHours(int v) {
		if (v > 23)
		{
			setDate(getDate() + v / 24);
			_ctm.tm_hour = v % 24;
		}
		else {
			_ctm.tm_hour = v;
		}
	};

	/// <summary>
	/// 设置分钟
	/// </summary>
	/// <param name="v">只接受大于等于0的整数</param>
	void setMinutes(int v) {
		if (v > 59)
		{
			setHours(getHours() + v / 60);
			_ctm.tm_min = v % 60;
		}
		else {
			_ctm.tm_min = v;
		}
	};

	/// <summary>
	/// 设置秒数
	/// </summary>
	/// <param name="v">只接受大于等于0的整数</param>
	void setSeconds(int v) {
		if (v > 59)
		{
			setMinutes(getMinutes() + v / 60);
			_ctm.tm_sec = v % 60;
		}
		else {
			_ctm.tm_sec = v;
		}
	};

	/// <summary>
	/// 是否是闰年
	/// </summary>
	/// <param name="year">年份</param>
	/// <returns>布尔值</returns>
	bool isLeapYear(int year) {
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}

	/// <summary>
	/// 创建标准日期
	/// </summary>
	/// <param name="y">年</param>
	/// <param name="m">月</param>
	/// <param name="d">日</param>
	tm makeT(int y, int m, int d) {
		tm timeStruct = { 0 };
		timeStruct.tm_year = y;
		timeStruct.tm_mon = m;
		timeStruct.tm_mday = d;
		mktime(&timeStruct);
		return timeStruct;
	}
};

