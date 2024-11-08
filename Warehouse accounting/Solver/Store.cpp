#include "Store.h"

using namespace std;

using namespace bakery::shop;

Store::Store(const int taxpayer_id, const string& shop_name, const string& shop_address)
{
	if (taxpayer_id <= 0)
	{
		throw out_of_range("ИНН должен выражаться положительным целым числом!");
	}
	if (empty(shop_name))
	{
		throw invalid_argument("Не указано название магазина!");
	}
	if (empty(shop_address))
	{
		throw invalid_argument("Не указан адрес магазина!");
	}
	this->taxpayer_id = taxpayer_id;
	this->shop_name = shop_name;
	this->shop_address = shop_address;
}

bool Store::operator==(const Store& other_shop)
{
	return (this->taxpayer_id == other_shop.taxpayer_id) and (this->shop_name == other_shop.shop_name) and (this->shop_address == other_shop.shop_address);
}

ostream& bakery::shop::operator<<(ostream& os, const Store& shop)
{
	return os << shop.ToString();
}

string Store::ToString() const
{
	stringstream buffer{};
	buffer << "ИНН: " << this->taxpayer_id << "; название магазина: " << this->shop_name << "; адрес: " << this->shop_address;
	return buffer.str();
}