#include "Product.h"

using namespace std;

using namespace bakery::product;

Product::Product(const string& item_number, const string& product_name, double price)
{
	if (empty(item_number))
	{
		throw invalid_argument("Не указан артикул товара!");
	}
	if (empty(product_name))
	{
		throw invalid_argument("Не указано название товара!");
	}
	if (price <= 0.0)
	{
		throw out_of_range("Цена товара должна выражаться положительным числом!");
	}
	this->item_number = item_number;
	this->product_name = product_name;
	this->price = price;
}

bool Product::operator==(const Product& other_product)
{
	return this->item_number == other_product.item_number;
}

ostream& bakery::product::operator<<(ostream& os, const Product& product)
{
	return os << product.ToString();
}

string Product::ToString() const
{
	stringstream buffer{};
	buffer << "Артикул: " << this->item_number << "; название: " << this->product_name << "; цена: " << this->price;
	return buffer.str();
}

double Product::GetPrice() const
{
	return price;
}