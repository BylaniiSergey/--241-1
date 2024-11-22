#include "Store.h"

namespace bakery::shop
{
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

	bool Store::operator==(const Store& other_shop)
	{
		return (this->taxpayer_id == other_shop.taxpayer_id) and (this->shop_name == other_shop.shop_name) and (this->shop_address == other_shop.shop_address);
	}

	std::ostream& bakery::shop::operator<<(std::ostream& os, const Store& shop)
	{
		return os << shop.toString();
	}

	const std::string& bakery::shop::Store::GetName() const
	{
		return shop_name;
	}
}