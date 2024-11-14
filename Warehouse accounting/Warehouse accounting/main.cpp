#include <iostream>
#include<locale>
#include "..//Solver/Client.h"
#include "..//Solver/Product.h"
#include "..//Solver/Store.h"
#include "..//Solver/Warehouse.h"

using namespace bakery::warehouse;
using namespace bakery::product;
using namespace bakery::shop;
using namespace bakery::client;

/**
* @brief Точка входа в программу
* @return 0 в случае успеха
*/
int main() 
{
    setlocale(LC_ALL, "RU");
    // Создание склада
    Warehouse warehouse;
    
    // Создание продуктов
    auto product1 = std::make_shared<Product>("001", "Хлеб", 50.0);
    auto product2 = std::make_shared<Product>("002", "Булочка", 25.0);
    auto product3 = std::make_shared<Product>("003", "Круассан", 30.0);
    std::cout << "Продукты созданы!" << std::endl;

    // Добавление продуктов на склад
    warehouse.AddProduct(product1);
    warehouse.AddProduct(product2);
    warehouse.AddProduct(product3);

    // Вывод информации о всех товарах на складе
    warehouse.PrintInventory();

    // Создание магазина
    Store store(123456789, "Магазин выпечки", "Улица Пекарей, 1");
    std::cout << store.toString() << std::endl;

    // Создание клиентов
    Client client1("Иванов И.И.", 10.0);
    Client client2("Петрова А.А.", 15.0);
    std::cout << client1.toString() << std::endl;
    std::cout << client2.toString() << std::endl;

    return 0;
}