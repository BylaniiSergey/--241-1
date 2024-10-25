#pragma once
#include <vector>
#include "Product.h"

class Warehouse 
{
public:
    void addProduct(Product* product);
    void showProducts() const;

private:
    std::vector<Product*> products;
};