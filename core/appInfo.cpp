#include "appInfo.h"

std::string AppInfo::version = "kcron version 0.0.1";
std::string AppInfo::author = "Copyright (c) 2023 kuyoru";
std::string AppInfo::source = "https://github.com/kuyoru-kamikisho/kcron";
std::string AppInfo::help = R"(
[w] or [z] or [c] 
	Flags£¬represents the delay time, period interval,
	and clock scale respectively.
	After this parameter, 
	the year, month, day, week, hour, minute, 
	and second must be written in order, 
	these parameters must all be numbers.

[-h] or [--help] 
	Show the help info.

[-v] or [--version] 
	Show the version info.

[-l] [num] or [--list] [num] 
	Display the time after n times. 
	The default is 1. 
	The range of n is a number greater than 1.
)";

void AppInfo::helpInfo() {
	std::cout << help << std::endl;
}
void AppInfo::versionInfo() {
	std::cout << version << std::endl;
	std::cout << author << std::endl;
	std::cout << source << std::endl;
}
