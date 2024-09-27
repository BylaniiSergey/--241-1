#include "Item.h"

Item::Item(std::string name, double price) : name(name), price(price) {}

std::string Item::getInfo() const 
{
    return "Предмет: " + name + ", Цена: " + std::to_string(price);
}