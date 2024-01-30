#pragma once
#include "lang.h"

class setLang
{
public:
	static void install() {
		Lang::add(LangUnit("colon", "\uff1a", ":"));
		Lang::add(LangUnit("now", "\u5f53\u524d\u65f6\u95f4", "Current time"));
		Lang::add(LangUnit("year", "\u5e74", "Year"));
		Lang::add(LangUnit("month", "\u6708", "Month"));
		Lang::add(LangUnit("date", "\u65e5", "Day"));
		Lang::add(LangUnit("week", "\u5468", "Week"));
		Lang::add(LangUnit("hour", "\u65f6", "Hour"));
		Lang::add(LangUnit("minute", "\u5206", "Minute"));
		Lang::add(LangUnit("second", "\u79d2", "Second"));
	}
};


