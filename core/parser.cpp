#include "parser.h"
#include "JDate.h"

enum Step
{
	Y, M, D, w, h, m, s
};

void resolver(int* source, std::string value) {
	if (value == "-") {
		*source = 0;
	}
	else
	{
		*source = std::stoi(value);
	}
}

void Parser::loadParams(int size, char* params[]) {
	int step = -1;
	std::string param;
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
			std::cout << i << std::endl;
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
				resolver(&_day, param);
				step = Step::w;
				break;
			case Step::w:
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

	time_t currentTime = time(nullptr);

	if (_mode == "w")
	{
		// 等待模式只执行一次，会忽略掉 --list 参数
		JDate date;
		auto a = date.getDate();
		std::cout << a << std::endl;
		date.setMinutes(15840);
		auto b = date.getMilliseconds();
		std::cout << a << std::endl;
	}
	else if (_mode == "c") {

	}
	else if (_mode == "z")
	{

	}
}