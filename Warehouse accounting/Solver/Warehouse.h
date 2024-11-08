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
    * @brief  ласс —клад.
    */
    class Warehouse final
    {
    private:
        /**
        * @brief —писок товаров на складе.
        */
        vector<product::Product> products;
    public:
        /**
        * @brief ћетод дл€ добавлени€ товара на склад.
        * @param product - товар, который нужно добавить.
        */
        void AddProduct(const product::Product& product);

        /**
        * @brief ћетод дл€ удалени€ товара со склада по артикулу.
        * @param item_number - артикул товара, который нужно удалить.
        * @return ¬озвращает true, если товар был успешно удален, в противном случае - false.
        */
        bool RemoveProduct(const string& item_number);

        /**
        * @brief ћетод дл€ поиска товара по артикулу.
        * @param item_number - артикул товара, который нужно найти.
        * @return ¬озвращает указатель на найденный товар или nullptr, если товар не найден.
        */
        const bakery::product::Product* FindProduct(const string& item_number) const;
        /**
        * @brief ћетод дл€ вывода информации о всех товарах на складе.
        */
        void PrintInventory() const;

        /**
        * @brief ƒеструктор (создан по умолчанию).
        */
        ~Warehouse() = default;
    };
}