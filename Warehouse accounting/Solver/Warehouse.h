#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> 
#include "Product.h"

using namespace std;

namespace bakery::warehouse
{
    /**
    * @brief Класс Склад.
    */
    class Warehouse final
    {
    private:
        /**
        * @brief Список товаров на складе.
        */
        vector<product::Product> products;
    public:
        /**
        * @brief Метод для добавления товара на склад.
        * @param product - товар, который нужно добавить.
        */
        void AddProduct(const product::Product& product);

        /**
        * @brief Метод для удаления товара со склада по артикулу.
        * @param item_number - артикул товара, который нужно удалить.
        * @return Возвращает true, если товар был успешно удален, в противном случае - false.
        */
        bool RemoveProduct(const string& item_number);

        /**
        * @brief Метод для поиска товара по артикулу.
        * @param item_number - артикул товара, который нужно найти.
        * @return Возвращает указатель на найденный товар или nullptr, если товар не найден.
        */
        const bakery::product::Product* FindProduct(const string& item_number) const;
        /**
        * @brief Метод для вывода информации о всех товарах на складе.
        */
        void PrintInventory() const;

        /**
        * @brief Деструктор (создан по умолчанию).
        */
        ~Warehouse() = default;
    };
}