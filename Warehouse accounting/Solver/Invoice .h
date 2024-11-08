#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Product.h" 

using namespace std;

namespace bakery::invoice
{
    /**
    * @brief Класс Накладная.
    */
    class Invoice final
    {
    private:
        /**
        * @brief Номер накладной.
        */
        string invoice_number;
        /**
        * @brief Дата накладной.
        */
        string date;
        /**
        * @brief Список товаров в накладной.
        */
        vector<product::Product> products;
    public:
        /**
        * @brief Конструктор.
        * @param invoice_number - номер накладной.
        * @param date - дата накладной.
        */
        Invoice(const string& invoice_number, const string& date) : invoice_number(invoice_number), date(date) {};

        /**
        * @brief Метод для добавления товара в накладную.
        * @param product - товар, который нужно добавить.
        */
        void AddProduct(const product::Product& product);

        /**
        * @brief Метод для расчета общей суммы накладной.
        * @return Возвращает общую сумму накладной.
        */
        double CalculateTotal() const;

        /**
        * @brief Метод для вывода информации о накладной.
        */
        void PrintInvoice() const;

        /**
        * @brief Деструктор (создан по умолчанию).
        */
        ~Invoice() = default;
    };
}