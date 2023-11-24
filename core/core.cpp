#include <iostream>
#include "parser.h"
#include "array.h"

int main(int argc, char* argv[])
{
	if (argc > 1) {
		int size = argc - 1;
		Parser parser;
		Array::removeChar(argv, argc, 0);
		parser.loadParams(size, argv);
	}
	else
	{
		std::cout << "No parameters passed." << std::endl;
	}
}
