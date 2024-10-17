#include <iostream>
#include "..//Solver/MyLinkedList.h"

using namespace mynamespace;

int main()
{
    std::setlocale(NULL, "ru_RU.UTF-8");

    MyLinkedList list = { 1, 2, 3, 4 };
    std::cout << "Первоначальный список: " << list.toString() << std::endl;

    list.push_front(3);
    std::cout << "Список после push_front(3): " << list << std::endl;

    list.push_back(5);
    std::cout << "Список после push_back(5): " << list << std::endl;
    
    list.pop_front();
    std::cout << "Список после pop_front(): " << list << std::endl;

    list.pop_back();
    std::cout << "Список после pop_back(): " << list << std::endl;

    list.insert(0, 4);
    std::cout << "Список после insert(0, 3): " << list << std::endl;

    list.remove(2);
    std::cout << "Список после remove(1): " << list << std::endl;

    return 0;
}