#include "Store.h"

using namespace std;

using namespace bakery::shop;

Store::Store(const int taxpayer_id, const string& shop_name, const string& shop_address)
{
	if (taxpayer_id <= 0)
	{
		throw out_of_range("��� ������ ���������� ������������� ����� ������!");
	}
	if (empty(shop_name))
	{
		throw invalid_argument("�� ������� �������� ��������!");
	}
	if (empty(shop_address))
	{
		throw invalid_argument("�� ������ ����� ��������!");
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
	buffer << "���: " << this->taxpayer_id << "; �������� ��������: " << this->shop_name << "; �����: " << this->shop_address;
	return buffer.str();
}