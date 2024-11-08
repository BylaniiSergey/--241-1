#include "Product.h"

using namespace std;

using namespace bakery::product;

Product::Product(const string& item_number, const string& product_name, double price)
{
	if (empty(item_number))
	{
		throw invalid_argument("�� ������ ������� ������!");
	}
	if (empty(product_name))
	{
		throw invalid_argument("�� ������� �������� ������!");
	}
	if (price <= 0.0)
	{
		throw out_of_range("���� ������ ������ ���������� ������������� ������!");
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
	buffer << "�������: " << this->item_number << "; ��������: " << this->product_name << "; ����: " << this->price;
	return buffer.str();
}

double Product::GetPrice() const
{
	return price;
}