#include "Store.h"

Store::Store(const std::string& name, double discount) : name(name), discount(discount) {}

std::string Store::getName() const 
{
    return name;
}

double Store::getDiscount() const 
{
    return discount;
}