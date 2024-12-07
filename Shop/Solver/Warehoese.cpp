#include "Warehouse.h"
#include <iostream>

namespace bakery::warehouse
{

    void Warehouse::AddProduct(const std::shared_ptr<bakery::product::Product>& product)
    {
        products.push_back(product);
    }

    void Warehouse::PrintInventory() const
    {
        std::cout << "Инвентарь склада:" << std::endl;
        for (const auto& product : products)
        {
            std::cout << product->toString() << std::endl;
        }
    }
    const std::vector<std::shared_ptr<bakery::product::Product>>& Warehouse::GetProducts()
    {
        return products;
    }
}