#include <iostream>
#include <string>
#include "..//Solver/Warehouse.h"
#include "..//Solver/Product.h"
#include "..//Solver/Store.h"
#include "..//Solver/Invoice .h"

using namespace std;

int main() 
{
    // Создание склада
    bakery::warehouse::Warehouse warehouse;
    // Создание продуктов
    bakery::product::Product product1("001", "Хлеб", 50.2);
    bakery::product::Product product2("002", "Булочка", 25.3);
    bakery::product::Product product3("003", "Круассан", 30.9);
    // Добавление продуктов на склад
    warehouse.AddProduct(product1);
    warehouse.AddProduct(product2);
    warehouse.AddProduct(product3);
    // Вывод информации о всех товарах на складе
    cout << "Инвентарь склада:" << endl;
    warehouse.PrintInventory();
    // Поиск продукта по артикулу
    string search_item = "002";
    const bakery::product::Product* found_product = warehouse.FindProduct(search_item);
    if (found_product) {
        cout << "Найденный продукт: " << found_product->ToString() << endl;
    }
    else {
        cout << "Продукт с артикулом " << search_item << " не найден." << endl;
    }
    // Удаление продукта со склада
    if (warehouse.RemoveProduct("001")) {
        cout << "Продукт с артикулом 001 успешно удалён." << endl;
    }
    else {
        cout << "Не удалось удалить продукт с артикулом 001." << endl;
    }
    // Вывод информации о всех товарах на складе после удаления
    cout << "Инвентарь склада после удаления:" << endl;
    warehouse.PrintInventory();
    // Создание магазина
    bakery::shop::Store store(123456789, "Магазин выпечки", "Улица Пекарей, 1");
    // Создание накладной
    bakery::invoice::Invoice invoice("INV-001", "2023-10-01");
    invoice.AddProduct(product2);
    invoice.AddProduct(product3);
    // Вывод информации о накладной
    cout << "Накладная:" << endl;
    invoice.PrintInvoice();
    cout << "Общая сумма накладной: " << invoice.CalculateTotal() << " руб." << endl;
    return 0;
}