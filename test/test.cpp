#include <iostream>
#include "method.h"

int main()
{

	std::cout << "\n=====================test:w、c======================\n" << std::endl;
	std::cout << "调用结果：\n";
	auto result1 = parseTimeString("", 3);
	auto result2 = parseTimeString("w", 3);
	auto result3 = parseTimeString("w - -", 3);
	auto result4 = parseTimeString("w - - - - - - -", 3);
	auto result5 = parseTimeString("w 1 - - - - - -", 3);
	auto result6 = parseTimeString("w - - - - - - 120", 3);

	for (size_t i = 0; i < 3; i++)
	{
		std::cout << result6[i].m << std::endl;
	}

	std::cout << "\n=====================results:w、c======================\n" << std::endl;
	std::cout << result1 << std::endl;
	std::cout << result2 << std::endl;
	std::cout << result3 << std::endl;
	std::cout << result4 << std::endl;
	std::cout << result5 << std::endl;
	std::cout << result6 << std::endl;

	freeResult(result1);
	freeResult(result2);
	freeResult(result3);
	freeResult(result4);
	freeResult(result5);
	freeResult(result6);

	std::cout << "\n=====================methods======================\n" << std::endl;
	std::cout << getDateByYMwd(2024, 7, 2, 1) << std::endl;	// 8
	std::cout << getDateByYMwd(2005, 7, 2, 1) << std::endl;	// 11
	std::cout << getDateByYMwd(2011, 3, 2, 4) << std::endl;	// 10
}

