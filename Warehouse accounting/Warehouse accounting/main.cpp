#include <iostream>
#include <vector>
#include "..//Solver/Item.h"7

int main() 
{
    setlocale(LC_ALL, "RU");
    std::vector<Product*> inventory;
    inventory.push_back(new Item("Apples", 85.9));
    inventory.push_back(new Item("Bananas", 112.45));

    for (const auto& product : inventory) {
        std::cout << product->getInfo() << std::endl;
    }

    for (auto& product : inventory) {
        delete product;
    }
    return 0;
}