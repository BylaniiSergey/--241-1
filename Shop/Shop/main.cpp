#include <iostream>
#include<locale>
#include "..//Solver/Client.h"
#include "..//Solver/Product.h"
#include "..//Solver/Store.h"
#include "..//Solver/Warehouse.h"
#include "..//Solver/Invoice.h"

using namespace bakery::warehouse;
using namespace bakery::product;
using namespace bakery::shop;
using namespace bakery::client;
using namespace bakery::invoice;

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
    bakery::shop::Store store(123456789, "Магазин выпечки", "Улица Пекарей, 1");
    std::cout << store.toString() << std::endl;

    // Создание клиентов
    bakery::client::Client client1("Иванов И.И.", 10.0);
    bakery::client::Client client2("Петрова А.А.", 15.0);
    std::cout << client1.toString() << std::endl;
    std::cout << client2.toString() << std::endl;
    

    // Создание накладной
    bakery::invoice::Invoice invoice(store, client1, "INV001", "2023-10-01");

    // Добавление товаров в накладную
    invoice.addProduct(product1);
    invoice.addProduct(product2);

    // Вывод наклодной
    std::cout << invoice.toString() << std::endl;

    return 0;
}