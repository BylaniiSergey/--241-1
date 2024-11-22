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
    auto product2 = std::make_shared<Product>("002", "Телефон", 25000.0);
    auto product3 = std::make_shared<Product>("003", "Яйца", 130.0);

    // Добавление продуктов на склад
    warehouse.AddProduct(product1);
    warehouse.AddProduct(product2);
    warehouse.AddProduct(product3);


    // Вывод информации о всех товарах на складе
    warehouse.PrintInventory();

    // Создание магазина
    bakery::shop::Store store1(123456789, "Магазин выпечки", "Улица Пекарей д.1");
    bakery::shop::Store store2(987654321, "Магазин электронники", "Пушкинская улица д.14");
    bakery::shop::Store store3(13580, "Магазин продуктов", "Улица Артюшина д.32");
    std::cout << store1.toString() << std::endl;
    std::cout << store2.toString() << std::endl;
    std::cout << store3.toString() << std::endl;

    // Создание клиентов
    bakery::client::Client client1("Иванов И.И.", 10.0);
    bakery::client::Client client2("Петрова А.А.", 15.0);
    bakery::client::Client client3("Аксютин В.В.", 5.0);
    std::cout << client1.toString() << std::endl;
    std::cout << client2.toString() << std::endl;
    std::cout << client3.toString() << std::endl;

    // Создание накладной
    bakery::invoice::Invoice invoice(store1, client1, "INV001", "2024-11-22");

    // Добавление товаров в накладную
    invoice.addProduct(product1);
    invoice.addProduct(product3);

    // Вывод наклодной
    std::cout << invoice.toString() << std::endl;

    return 0;
}