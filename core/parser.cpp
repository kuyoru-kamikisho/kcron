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
	bool canlog = true;

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
					resolver(&_day, "-300");
				else
					resolver(&_day, param);
				step = Step::w;
				break;
			case Step::w:
				if (_mode == "z" && params[i - 1] == "+")
					resolver(&_week, "-1");
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

	int initStep = _seconds < 0 ? 7 :
		_minutes < 0 ? 6 :
		_hours < 0 ? 5 :
		_day < 0 ? 3 :
		_month < 0 ? 2 :
		_year < 0 ? 1 : 0;
	int addStep = initStep;

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
				if (addStep == 1)
				{
					addStep = initStep;
				}
			}
			else
			{
				if (addStep == 1) {
					int n = date.getYear() + 1;
					date.setYear(n);
					canlog = true;
					addStep = initStep;
					if (addStep > 1 && _day > -300)
					{
						addStep = 7;
					}
				}
			}
			if (_month > -1)
			{
				date.setMonth(_month - 1);
				if (addStep == 2)
				{
					addStep = 1;
				}
			}
			else {
				if (addStep == 2)
				{
					int n = date.getMonth() + 1;
					bool b = n > 11;
					canlog = !b;
					date.setMonth(b ? 0 : n);
					addStep = b ? 1 : initStep; // 1代表向年累加
					if (addStep > 2)
					{
						addStep = 7;
						if (initStep == 3 && _day == -300)
						{
							addStep = 3;
						}
					}
				}
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
				if (addStep == 3)
				{
					addStep = 2;
				}
			}
			else
			{
				if (addStep == 3)
				{
					if (_day == -300) {
						date.setDate(date.getMdayNum(-1, -1));
						addStep = 2;
					}
					else
					{
						int n;bool b;

						if (_week > -1) {
							if (date.getDay() == _week)
							{
								n = date.getDate() + 1;
								b = n > date.getMdayNum(date.getYear(), date.getMonth());
								addStep = b ? 2 : initStep;
								date.setDate(b ? 1 : n);
								canlog = !b;
							}
							while (date.getDay() != _week)
							{
								n = date.getDate() + 1;
								b = n > date.getMdayNum(date.getYear(), date.getMonth());
								canlog = !b;
								if (b) {
									addStep = 2;
									date.setDate(1);
									break;
								}
								date.setDate(n);
							}
						}
						else
						{
							n = date.getDate() + 1;
							b = n > date.getMdayNum(date.getYear(), date.getMonth());
							addStep = b ? 2 : initStep; // 2代表向月累加
							date.setDate(b ? 1 : n);
							canlog = !b;
						}
					}
					if (addStep > 3)
					{
						addStep = 7;
					}
				}
			}
			if (_hours > -1)
			{
				date.setHours(_hours);
				if (addStep == 5)
				{
					addStep = 3;
				}
			}
			else
			{
				if (addStep == 5) {
					int n = date.getHours() + 1;
					bool b = n > 23;
					canlog = !b;
					date.setHours(b ? 0 : n);
					addStep = b ? 3 : initStep; // 3代表向日累加
					if (addStep > 5)
					{
						addStep = 7;
					}
				}
			}
			if (_minutes > -1)
			{
				date.setMinutes(_minutes);
				if (addStep == 6)
				{
					addStep = 5;
				}
			}
			else
			{
				if (addStep == 6)
				{
					int n = date.getMinutes() + 1;
					bool b = n > 59;
					canlog = !b;
					date.setMinutes(b ? 0 : n);
					addStep = b ? 5 : initStep; // 5代表向小时累加
					if (addStep > 6)
					{
						addStep = 7;
					}
				}
			}
			if (_seconds > -1)
			{
				date.setSeconds(_seconds);
				if (addStep == 7) {
					addStep = initStep;
				}
			}
			else
			{
				if (addStep == 7)
				{
					int n = date.getSeconds() + 1;
					bool b = n > 59;
					canlog = !b;
					date.setSeconds(b ? 0 : n);
					addStep = b ? 6 : initStep; // 6代表向分钟累加
				}
			}
		}

		bool check2 = true;
		if (_mode == "z")
		{
			if (_day > -1 && _week > -1)
			{
				check2 = date.getDay() == _day && date.getNumWeek() == _week;
			}
			if (_day<0 && _week>-1 && _day > -300)
			{
				check2 = date.getDay() == _week;
			}
			if (_day == -300)
			{
				date.setDate(date.getMdayNum(-1, -1));
			}
		}
		if (canlog && check2) {
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
		else
		{
			i--;
		}
	}
}