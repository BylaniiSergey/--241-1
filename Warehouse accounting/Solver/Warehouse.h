#include <vector>
#include <memory>
#include "Product.h"

namespace bakery::warehouse 
{
    /**
    * @brief Класс Склад.
    * Данный класс представляет склад, который хранит список продуктов.
    * Он предоставляет методы для добавления продуктов и вывода инвентаря.
    */
    class Warehouse final 
    {
    private:
        /**
        * @brief Вектор продуктов.
        * Хранит указатели на продукты, находящиеся на складе.
        */
        std::vector<std::shared_ptr<bakery::product::Product>> products;

    public:
        /**
        * @brief Метод добавления продукта.
        * Добавляет указатель на продукт в инвентарь склада.
        * @param product Указатель на продукт, который необходимо добавить.
        */
        void AddProduct(const std::shared_ptr<bakery::product::Product>& product);

        /**
        * @brief Метод вывода инвентаря.
        * Печатает список всех продуктов, находящихся на складе.
        */
        void PrintInventory() const;
    };
}