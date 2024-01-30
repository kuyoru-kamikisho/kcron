#pragma once
#include <string>
#include <vector>

class LangUnit {
public:
	std::string key;
	std::string zh;
	std::string en;
	LangUnit(std::string key, std::string zh, std::string en)
	{
		this->key = key;
		this->zh = zh;
		this->en = en;
	};
};

class Lang
{
public:
	static std::vector<LangUnit> list;
	static LangUnit get(std::string key)
	{
		auto it = std::find_if(list.begin(), list.end(), [key](const LangUnit& unit) {
			return unit.key == key;
			});
		if (it != list.end()) {
			return *it;
		}
		return LangUnit("", "", "");
	};
	static bool add(LangUnit unit)
	{
		list.push_back(unit);
		return true;
	};
	static bool remove(std::string key)
	{
		auto newEnd = std::remove_if(list.begin(), list.end(), [key](const LangUnit& unit) {
			return unit.key == key;
			});
		list.erase(newEnd, list.end());
		return true;
	};
};