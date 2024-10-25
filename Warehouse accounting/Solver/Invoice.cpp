#include "Invoice .h"
#include <iostream>

void Invoice::addProduct(Product* product) 
{
    products.push_back(product);
}

void Invoice::showInvoice() const 
{
    for (const auto& product : products) 
    {
        std::cout << "Invoice Product: " << product->getName() << ", Price: " << product->getPrice() << std::endl;
    }
}
