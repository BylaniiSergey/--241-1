#pragma once

#include <string>
#include <vector>
#include <chrono>
#include <sstream>
#include "Store.h"
#include "Client.h"
#include "Product.h"

namespace bakery::invoice
{
    /**
     * @brief Класс Накладная.
     * Данный класс представляет накладную, которая содержит информацию о магазине, клиенте и товарах, которые были переданы клиенту.
     */
    class Invoice final
    {
    private:
        std::string invoice_id;///< Идентификатор накладной
        std::chrono::system_clock::time_point issue_date;
        std::shared_ptr<const bakery::shop::Store> store;
        std::shared_ptr<const bakery::client::Client> client;
        std::vector<std::shared_ptr<bakery::product::Product>> products; ///< Список товаров в накладной

    public:
        /**
         * @brief Конструктор класса Invoice.
         * Инициализирует новую накладную с заданными магазином, клиентом, идентификатором и датой.
         * @param store Магазин, выписавший накладную.
         * @param client Клиент, которому выписана накладная.
         * @param invoice_id Идентификатор накладной.
         * @param issue_date Дата выписки накладной.
         */
        Invoice(std::shared_ptr<const bakery::shop::Store> store,
            std::shared_ptr<const bakery::client::Client> client,
            const std::string& invoice_id,
            std::chrono::system_clock::time_point issue_date);
        
        /**
         * @brief Метод добавления продукта в накладную.
         * Добавляет указатель на продукт в список товаров накладной.
         * @param product Указатель на продукт, который необходимо добавить.
         */
        void addProduct(const std::shared_ptr<bakery::product::Product>& product);

        /**
         * @brief Метод получения строкового представления накладной.
         * @return Возвращает строку, содержащую информацию о накладной.
         */
        std::string toString() const;

        /**
         * @brief Метод расчета общей стоимости накладной с учетом скидки клиента.
         * @return Возвращает общую стоимость накладной.
         */
        double GetTotalCost() const;

        /**
         * @brief Конструктор перемещения (создан по умолчанию).
         * @param other_invoice - другая накладная.
         */
        Invoice(Invoice&& other_invoice) = default;

        /**
         * @brief Конструктор копирования (запрещён).
         * @param other_invoice - другая накладная.
         */
        Invoice(const Invoice& other_invoice) = delete;

        /**
         * @brief Переопределение оператора присваивания для конструктора перемещения (создано по умолчанию).
         * @param other_invoice - другая накладная.
         * @return Возвращает созданную накладную.
         */
        Invoice& operator=(Invoice&& other_invoice) = default;

        /**
         * @brief Переопределение оператора присваивания для конструктора копирования (запрещено).
         * @param other_invoice - другая накладная.
         */
        Invoice& operator=(const Invoice& other_invoice) = delete;

        /**
         * @brief Деструктор (создан по умолчанию).
         */
        ~Invoice() = default;

        std::string GetInvoiceId() const;

        std::chrono::system_clock::time_point GetIssueDate() const;

        std::shared_ptr<const bakery::shop::Store> GetStore() const;

        std::shared_ptr<const bakery::client::Client> GetClient() const;

        const std::vector<std::shared_ptr<bakery::product::Product>>& GetProducts() const;
    };
}