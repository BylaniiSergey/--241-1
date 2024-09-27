#include <iostream>
#include "..//Solver/MyLinkedList.h"

int main()
{
    std::setlocale(NULL, "ru_RU.UTF-8");

    MyLinkedList list = { 1, 2, 3, 4 };
    std::cout << "Первоначальный список: " << list << std::endl;

    list.push_back(5);
    std::cout << "Список после push_back(5): " << list << std::endl;

    list.pop_front();
    std::cout << "Список после pop_front(): " << list << std::endl;

    list.pop_back();
    std::cout << "Список после pop_back(): " << list << std::endl;

    list.insert(0, 8);
    std::cout << "Список после insert(0, 8): " << list << std::endl;

    list.remove(3);
    std::cout << "Список после remove(3): " << list << std::endl;

    return 0;
}