#pragma once
#include <string>

class Store 
{
public:
    Store(const std::string& name, double discount);
    std::string getName() const;
    double getDiscount() const;

private:
    std::string name;
    double discount;
};