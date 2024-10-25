#include "Warehouse.h"
#include <iostream>

void Warehouse::addProduct(Product* product) 
{
    products.push_back(product);
}

void Warehouse::showProducts() const 
{
    for (const auto& product : products) 
    {
        std::cout << "Product: " << product->getName() << ", Price: " << product->getPrice() << std::endl;
    }
}