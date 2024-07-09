#include <iostream>
#include "method.h"

int main()
{

	std::cout << "\n=====================test:w、c======================\n" << std::endl;
	std::cout << "调用结果：\n";

	auto result1 = parseTimeString("", 13);
	auto result2 = parseTimeString("w", 13);
	auto result3 = parseTimeString("w - -", 13);
	auto result4 = parseTimeString("w - - - - - - -", 13);
	auto result5 = parseTimeString("w 1 - - - - - -", 13);
	auto result6 = parseTimeString("w - - - - - - 120", 13);
	auto result7 = parseTimeString("c 1 3 - - - 12 -", 13);
	auto result8 = parseTimeString("c - - - - 2 - 70", 13);
	auto result9 = parseTimeString("c - - 45 - - - -", 13);

	auto result10 = parseTimeString("z - 1 1 - 0 0 0", 13);
	auto result11 = parseTimeString("z - - - - 1 0 0", 13);
	auto result12 = parseTimeString("z - - 4 3 - 0 0", 13);
	auto result13 = parseTimeString("z - - + - 0 0 0", 13);
	auto result14 = parseTimeString("z - - - 4 14 32 0", 13);
	auto result15 = parseTimeString("z - - - - - - 1", 13);
	auto result16 = parseTimeString("z - - - 1 0 0 0", 13);
	auto result17 = parseTimeString("z - - 1 - 0 0 0", 13);
	auto result18 = parseTimeString("z 2024 1 1 - 0 0 0", 13);

	std::cout << "\n=====================results:w、c======================\n" << std::endl;

	for (size_t i = 0; i < 13; i++)
	{
		printf("%d  %d  %d  %d  %d  %d  %d\n", result4[i].Y, result4[i].M, result4[i].D, result4[i].w, result4[i].h, result4[i].m, result4[i].s);
	}
	for (size_t i = 0; i < 13; i++)
	{
		printf("%d  %d  %d  %d  %d  %d  %d\n", result5[i].Y, result5[i].M, result5[i].D, result5[i].w, result5[i].h, result5[i].m, result5[i].s);
	}
	for (size_t i = 0; i < 13; i++)
	{
		printf("%d  %d  %d  %d  %d  %d  %d\n", result6[i].Y, result6[i].M, result6[i].D, result6[i].w, result6[i].h, result6[i].m, result6[i].s);
	}
	for (size_t i = 0; i < 13; i++)
	{
		printf("%d  %d  %d  %d  %d  %d  %d\n", result7[i].Y, result7[i].M, result7[i].D, result7[i].w, result7[i].h, result7[i].m, result7[i].s);
	}
	for (size_t i = 0; i < 13; i++)
	{
		printf("%d  %d  %d  %d  %d  %d  %d\n", result8[i].Y, result8[i].M, result8[i].D, result8[i].w, result8[i].h, result8[i].m, result8[i].s);
	}
	for (size_t i = 0; i < 13; i++)
	{
		printf("%d  %d  %d  %d  %d  %d  %d\n", result9[i].Y, result9[i].M, result9[i].D, result9[i].w, result9[i].h, result9[i].m, result9[i].s);
	}
	for (size_t i = 0; i < 13; i++)
	{
		printf("%d  %d  %d  %d  %d  %d  %d\n", result10[i].Y, result10[i].M, result10[i].D, result10[i].w, result10[i].h, result10[i].m, result10[i].s);
	}
	for (size_t i = 0; i < 13; i++)
	{
		printf("%d  %d  %d  %d  %d  %d  %d\n", result11[i].Y, result11[i].M, result11[i].D, result11[i].w, result11[i].h, result11[i].m, result11[i].s);
	}
	for (size_t i = 0; i < 13; i++)
	{
		printf("%d  %d  %d  %d  %d  %d  %d\n", result12[i].Y, result12[i].M, result12[i].D, result12[i].w, result12[i].h, result12[i].m, result12[i].s);
	}
	for (size_t i = 0; i < 13; i++)
	{
		printf("%d  %d  %d  %d  %d  %d  %d\n", result13[i].Y, result13[i].M, result13[i].D, result13[i].w, result13[i].h, result13[i].m, result13[i].s);
	}
	for (size_t i = 0; i < 13; i++)
	{
		printf("%d  %d  %d  %d  %d  %d  %d\n", result14[i].Y, result14[i].M, result14[i].D, result14[i].w, result14[i].h, result14[i].m, result14[i].s);
	}
	for (size_t i = 0; i < 13; i++)
	{
		printf("%d  %d  %d  %d  %d  %d  %d\n", result15[i].Y, result15[i].M, result15[i].D, result15[i].w, result15[i].h, result15[i].m, result15[i].s);
	}
	for (size_t i = 0; i < 13; i++)
	{
		printf("%d  %d  %d  %d  %d  %d  %d\n", result16[i].Y, result16[i].M, result16[i].D, result16[i].w, result16[i].h, result16[i].m, result16[i].s);
	}
	for (size_t i = 0; i < 13; i++)
	{
		printf("%d  %d  %d  %d  %d  %d  %d\n", result17[i].Y, result17[i].M, result17[i].D, result17[i].w, result17[i].h, result17[i].m, result17[i].s);
	}
	for (size_t i = 0; i < 13; i++)
	{
		printf("%d  %d  %d  %d  %d  %d  %d\n", result18[i].Y, result18[i].M, result18[i].D, result18[i].w, result18[i].h, result18[i].m, result18[i].s);
	}

	freeResult(result1);
	freeResult(result2);
	freeResult(result3);
	freeResult(result4);
	freeResult(result5);
	freeResult(result6);
	freeResult(result7);
	freeResult(result8);
	freeResult(result9);
	freeResult(result10);
	freeResult(result11);
	freeResult(result12);
	freeResult(result13);
	freeResult(result14);
	freeResult(result15);
	freeResult(result16);
	freeResult(result17);
	freeResult(result18);

	std::cout << "\n=====================methods======================\n" << std::endl;
	std::cout << getDateByYMwd(2024, 7, 2, 1) << std::endl;	// 8
	std::cout << getDateByYMwd(2005, 7, 2, 1) << std::endl;	// 11
	std::cout << getDateByYMwd(2011, 3, 2, 4) << std::endl;	// 10
	std::cout << getDateByYMwd(2024, 3, 3, 4) << std::endl;	// 21
	std::cout << getDateByYMwd(2024, 7, 3, 4) << std::endl;	// 18
}

