#include <iostream>
#include "method.h"

int main()
{
    std::cout << "调用结果：\n";
    auto result = parseTimeString("w - - - - - - -",3);
    std::cout << result << std::endl;
}

