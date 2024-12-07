#include "Store.h"

namespace bakery::shop
{
	Store::Store(const std::string& name) : shop_name(name) {}

	Store::Store(int taxpayer_id, const std::string& shop_name, const std::string& shop_address) : taxpayer_id(taxpayer_id), shop_name(shop_name), shop_address(shop_address)
	{
		if (taxpayer_id <= 0)
		{
			throw std::out_of_range("ИНН должен выражаться положительным целым числом!");
		}
		if (empty(shop_name))
		{
			throw std::invalid_argument("Не указано название магазина!");
		}
		if (empty(shop_address))
		{
			throw std::invalid_argument("Не указан адрес магазина!");
		}
		this->taxpayer_id = taxpayer_id;
		this->shop_name = shop_name;
		this->shop_address = shop_address;
	}

	std::string Store::toString() const
	{
		std::stringstream buffer;
		buffer << "Магазин: " << this->shop_name << "; Адрес: " << this->shop_address << "; ИНН: " << this->taxpayer_id;
		return buffer.str();
	}

	bool operator==(const Store& lhs, const Store& rhs)
	{
		return (lhs.taxpayer_id == rhs.taxpayer_id) &&
			(lhs.shop_name == rhs.shop_name) &&
			(lhs.shop_address == rhs.shop_address);
	}

	std::ostream& bakery::shop::operator<<(std::ostream& os, const Store& shop)
	{
		return os << shop.toString();
	}

	const std::string& bakery::shop::Store::GetName() const
	{
		return shop_name;
	}

	const std::string& Store::GetAddress() const
	{
		return shop_address;
	}

	int Store::GetTaxpayerId() const
	{
		return taxpayer_id;
	}
}