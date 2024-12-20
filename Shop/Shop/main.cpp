﻿#include <iostream>
#include<locale>
#include "..//Solver/Client.h"
#include "..//Solver/Product.h"
#include "..//Solver/Store.h"
#include "..//Solver/Warehouse.h"
#include "..//Solver/Invoice.h"

using namespace bakery::invoice;
using namespace bakery::shop;
using namespace bakery::client;
using namespace bakery::product;

/**
* @brief Точка входа в программу
* @return 0 в случае успеха
*/
int main()
{
    setlocale(LC_ALL, "RU");
    // Create a store
    auto store = std::make_shared<Store>("StoreName");

    // Create a client
    auto client = std::make_shared<Client>("ClientName", 10.0);

    // Create a product
    auto product = std::make_shared<Product>("P001", "Product1", 10.0);

    // Define the invoice ID and issue date string
    std::string invoice_id = "INV001";
    std::string issue_date_str = "2023-10-01";

    // Convert the issue date string to a std::chrono::system_clock::time_point
    std::tm tm = {};
    std::istringstream ss(issue_date_str);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    auto issue_date = std::chrono::system_clock::from_time_t(std::mktime(&tm));

    // Create an invoice
    Invoice invoice(store, client, invoice_id, issue_date);

    // Add the product to the invoice
    invoice.addProduct(product);

    // Print the invoice
    std::cout << invoice.toString() << std::endl;

    return 0;
}


/*
using namespace bakery::warehouse;
using namespace bakery::shop;
using namespace bakery::product;
using namespace bakery::client;
using namespace bakery::invoice;

int main()
{
    setlocale(LC_ALL, "RU");
    // Создание склада
    Warehouse warehouse;

    // Создание продуктов
    auto product1 = std::make_shared<Product>("001", "Хлеб", 50.0);
    auto product2 = std::make_shared<Product>("002", "Телефон", 25000.0);
    auto product3 = std::make_shared<Product>("003", "Яйца", 130.0);

    // Создание магазина
    auto store1 = std::make_shared<const bakery::shop::Store>(123456789, "Магазин выпечки", "Улица Пекарей д.1");
    auto store2 = std::make_shared<const bakery::shop::Store>(987654321, "Магазин электронники", "Пушкинская улица д.14");
    auto store3 = std::make_shared<const bakery::shop::Store>(13580, "Магазин продуктов", "Улица Артюшина д.32");

    // Создание клиентов
    auto client1 = std::make_shared<const bakery::client::Client>("Иванов И.И.", 10.0);
    auto client2 = std::make_shared<const bakery::client::Client>("Петрова А.А.", 15.0);
    auto client3 = std::make_shared<const bakery::client::Client>("Аксютин В.В.", 5.0);

    // Создание накладной
    bakery::invoice::Invoice invoice(store2, client1, std::string("INV001"), std::string(""));

    // Добавление товаров в накладную
    invoice.addProduct(product1);
    invoice.addProduct(product3);

    // Вывод наклодной
    std::cout << invoice.toString() << std::endl;

    return 0;
}
*/