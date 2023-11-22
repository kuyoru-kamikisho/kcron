#include "parser.h"
#include "JDate.h"
# include <iomanip>

enum Step
{
	Y, M, D, w, h, m, s
};

void Parser::resolver(int* source, std::string value) {
	if (value == "-") {
		*source = _mode == "z" ? -1 : 0;
	}
	else
	{
		*source = std::stoi(value);
	}
}

void Parser::loadParams(int size, char* params[]) {
	int step = -1;
	std::string param;
	JDate date;
	for (int i = 0; i < size; i++)
	{
		param = params[i];

		if (param == "-h" || param == "--help")
		{
			AppInfo::helpInfo();
		}
		if (param == "-v" || param == "--version")
		{
			AppInfo::versionInfo();
		}
		if (param == "-l" || param == "--list") {
			if (i >= size) {
				std::cout << "Invalid tag: " << param << std::endl;
			}
			else {
				i++;
				param = params[i];
				try
				{
					_outNum = std::stoi(param);
				}
				catch (const std::exception&)
				{
					std::cout << "Invalid number of rows" << std::endl;
				}
			}
		}
		if (param == "w" || param == "c" || param == "z")
		{
			_mode = param;
			step = Step::Y;
			continue;
		}
		if (step != -1)
		{
			switch (step) {
			case Step::Y:
				resolver(&_year, param);
				step = Step::M;
				break;
			case Step::M:
				resolver(&_month, param);
				step = Step::D;
				break;
			case Step::D:
				if (_mode == "z" && param == "+")
					resolver(&_day, date.getMdayNum(_year, _month) + "");
				else
					resolver(&_day, param);
				step = Step::w;
				break;
			case Step::w:
				if (_mode == "z" && params[i - 1] == "+")
					resolver(&_week, -1 + "");
				else
					resolver(&_week, param);
				step = Step::h;
				break;
			case Step::h:
				resolver(&_hours, param);
				step = Step::m;
				break;
			case Step::m:
				resolver(&_minutes, param);
				step = Step::s;
				break;
			case Step::s:
				resolver(&_seconds, param);
				step = -1;
				break;
			}
		}
	}

	int Y = date.getYear();
	int M = date.getMonth();
	int D = date.getDate();
	int w = date.getDay();
	int h = date.getHours();
	int m = date.getMinutes();
	int s = date.getSeconds();

	std::cout << "当前时间：\n"
		<< Y
		<< "-"
		<< M + 1
		<< "-"
		<< D
		<< " 周"
		<< w
		<< " "
		<< h
		<< ":"
		<< m
		<< ":"
		<< s
		<< "\n"
		<< std::endl;

	std::cout << std::left
		<< std::setw(8) << "年"
		<< std::setw(8) << "月"
		<< std::setw(8) << "日"
		<< std::setw(8) << "周"
		<< std::setw(8) << "时"
		<< std::setw(8) << "分"
		<< std::setw(8) << "秒"
		<< std::endl;

	for (size_t i = 0; i < _outNum; i++)
	{
		if (_mode == "w" || _mode == "c")
		{
			s = date.getSeconds();
			date.setSeconds(s + _seconds);

			m = date.getMinutes();
			date.setMinutes(m + _minutes);

			h = date.getHours();
			date.setHours(h + _hours);

			D = date.getDate();
			date.setDate(D + _day + _week * 7);

			M = date.getMonth();
			date.setMonth(M + _month);

			Y = date.getYear();
			date.setYear(Y + _year);
		}
		else if (_mode == "z")
		{
			if (_year > -1)
			{
				date.setYear(_year);
			}
			if (_month > -1)
			{
				date.setMonth(_month - 1);
			}
			if (_day > -1)
			{
				if (_week > -1)
				{
					date.setDate(1);
					while (date.getNumWeek() != _week)
					{
						date.setDate(date.getDate() + 1);
					}
					while (date.getDay() != _day)
					{
						date.setDate(date.getDate() + 1);
					}
				}
				else {
					date.setDate(_day);
				}
			}
			if (_hours > -1)
			{
				date.setHours(_hours);
			}
			if (_minutes > -1)
			{
				date.setMinutes(_minutes);
			}
			if (_seconds > -1)
			{
				date.setSeconds(_seconds);
			}
			else
			{
				date.setSeconds(date.getSeconds() + 1);
			}
		}

		std::cout << std::left
			<< std::setw(8) << date.getYear()
			<< std::setw(8) << date.getMonth() + 1
			<< std::setw(8) << date.getDate()
			<< std::setw(8) << date.getDay()
			<< std::setw(8) << date.getHours()
			<< std::setw(8) << date.getMinutes()
			<< std::setw(8) << date.getSeconds()
			<< std::endl;
	}
}