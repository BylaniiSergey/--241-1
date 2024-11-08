#include "Invoice .h"

using namespace std;

using namespace bakery::invoice;

void Invoice::PrintInvoice() const
{
	cout << "Накладная #" << invoice_number << endl;
	cout << "Дата: " << date << endl;
	cout << "Товары:" << endl;
	for (const auto& product : products) {
		cout << product << endl;
	}
	cout << "Общая сумма: " << fixed << setprecision(2) << CalculateTotal() << " руб." << endl;
}

double Invoice::CalculateTotal() const
{
	double total = 0.0;
	for (const auto& product : products)
	{
		total += product.GetPrice();
	}
	return total;
}

void Invoice::AddProduct(const product::Product& product)
{
	products.push_back(product);
}