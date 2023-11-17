#include "array.h"

void Array::removeChar(char* p[], int size, int x) {
	if (x < 0 || x >= size) {
		std::cout << "Invalid index!" << std::endl;
		return;
	}

	for (int i = x; i < size - 1; i++) {
		p[i] = p[i + 1];
	}

	p[size - 1] = nullptr;
}