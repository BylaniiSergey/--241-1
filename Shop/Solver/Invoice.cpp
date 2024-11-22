#include "Invoice.h"
#include <iostream>

namespace bakery::invoice
{
    Invoice::Invoice(const bakery::shop::Store& store, const bakery::client::Client& client, const std::string& invoice_id, const std::string& issue_date)
        : store(store), client(client), invoice_id(invoice_id), issue_date(issue_date) {}

    void Invoice::addProduct(const std::shared_ptr<bakery::product::Product>& product)
    {
        products.push_back(product);
    }

    std::string Invoice::toString() const
    {
        std::stringstream ss;
        ss << "Накладная #" << invoice_id << " от " << issue_date << "\n";
        ss << "Магазин: " << store.toString() << "\n";
        ss << "Клиент: " << client.toString() << "\n";
        ss << "Список товаров:\n";
        for (const auto& product : products)
        {
            ss << "- " << product->toString() << "\n";
        }
        ss << "Общая стоимость: " << getTotalCost() << " руб.\n";
        return ss.str();
    }

    double Invoice::getTotalCost() const
    {
        double total = 0.0;
        for (const auto& product : products)
        {
            total += product->GetPrice();
        }
        total -= total * client.GetDiscount() / 100.0;
        return total;
    }

}