#include "parser.h"

void Parser::loadParams(int size, char* params[]) {
	std::string param;
	for (int i = 0; i < size; i++)
	{
		param = params[i];
		std::cout << param << std::endl;

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
		}
	}
}