#include <iostream>
#include "MyData.h"

int main()
{
    system("chcp 1251>nul");

    
        MY::Data date1(2024, 10, 3);
        MY::Data date2(2023, 10, 3);

        std::cout << date1 << std::endl;
        std::cout << date2 << std::endl;

        int difference = date1 - date2;
        std::cout << "Різниця між датами: " << difference << " днів" << std::endl;

        MY::Data newDate = date2 + 29;
        std::cout << newDate << std::endl;
        newDate - 2;
        std::cout << newDate << std::endl;


    return 0;
}