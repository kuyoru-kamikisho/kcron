#pragma once
#include <string>
#include <iostream>

class AppInfo
{
public:
	static std::string version;
	static std::string author;
	static std::string source;
	static std::string help;
	static void helpInfo();
	static void versionInfo();
};
