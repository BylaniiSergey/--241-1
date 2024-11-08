#include "Warehouse.h"

using namespace std;

using namespace bakery::warehouse;

void Warehouse::AddProduct(const product::Product& product)
{
	products.push_back(product);
}

bool Warehouse::RemoveProduct(const string& item_number)
{
	auto it = std::remove_if(products.begin(), products.end(), [&item_number](const product::Product& product)
		{
			return product.ToString().find(item_number) != string::npos;
		});
	if (it != products.end())
	{
		products.erase(it, products.end());
		return true;
	}
	return false;
}

const bakery::product::Product* bakery::warehouse::Warehouse::FindProduct(const string& item_number) const
{
	for (const auto& product : products)
	{
		if (product.ToString().find(item_number) != string::npos)
		{
			return &product;
		}
	}
	return nullptr;
}

void Warehouse::PrintInventory() const
{
	cout << "Товары на складе:" << endl;
	for (const auto& product : products)
	{
		cout << product << endl;
	}
}