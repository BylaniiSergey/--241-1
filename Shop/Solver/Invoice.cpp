#include "Invoice.h"
#include <iostream>

namespace bakery::invoice
{
    Invoice::Invoice(std::shared_ptr<const bakery::shop::Store> store,
        std::shared_ptr<const bakery::client::Client> client,
        const std::string& invoice_id,
        const std::string& issue_date_str)
        : store(store), client(client), invoice_id(invoice_id), issue_date((issue_date)) 
    {
        if (!store || !client)
        {
            throw std::invalid_argument("Значение указателя хранилища или клиента равно нулю.");
        }
    }

    void Invoice::addProduct(const std::shared_ptr<bakery::product::Product>& product)
    {
        products.push_back(product);
    }

    std::string Invoice::toString() const
    {
        std::ostringstream ss;
        ss << "Накладная ID: " << invoice_id << " от " << issue_date << "\n";
        std::time_t now_time = std::chrono::system_clock::to_time_t(issue_date);
        ss << "Магазин: " << (*store).GetName() << "\n";
        ss << "Клиент: " << (*client).GetName() << "\n";
        ss << "Список товаров:\n";
        for (const auto& product : products)
        {
            ss << "- " << product->toString() << "\n";
        }
        ss << "Общая стоимость: " << GetTotalCost() << " руб.\n";
        return ss.str();
    }

    double Invoice::GetTotalCost() const
    {
        double total = 0.0;
        for (const auto& product : products)
        {
            total += product->GetPrice();
        }
        total -= total * (*client).GetDiscount() /100;
        return total;
    }
}