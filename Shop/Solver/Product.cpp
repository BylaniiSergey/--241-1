#include "Product.h"

namespace bakery::product
{

    Product::Product(const std::string& item_number, const std::string& product_name, double price) : item_number(item_number), product_name(product_name), price(price)
    {
        if (empty(item_number))
        {
            throw std::invalid_argument("Не указан артикул товара!");
        }
        if (empty(product_name))
        {
            throw std::invalid_argument("Не указано название товара!");
        }
        if (price <= 0.0)
        {
            throw std::out_of_range("Цена товара должна выражаться положительным числом!");
        }
        this->item_number = item_number;
        this->product_name = product_name;
        this->price = price;
    }

    std::shared_ptr<Product> Product::GetProduct(const std::string& item_number, const std::string& product_name, double price)
    {
        return std::make_shared<Product>(item_number, product_name, price);
    }

    std::string Product::toString() const
    {
        std::stringstream buffer;
        buffer << "Артикул: " << this->item_number << "; название: " << this->product_name << "; цена: " << this->price << " руб.";
        return buffer.str();
    }

    double Product::GetPrice() const
    {
        return price;
    }

    bool Product::operator==(const Product& other_product)
    {
        return this->item_number == other_product.item_number;
    }

    std::ostream& operator<<(std::ostream& os, const Product& product)
    {
        return os << product.toString();
    }
}