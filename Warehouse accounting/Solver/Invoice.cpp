#include "Invoice .h"

using namespace std;

using namespace bakery::invoice;

void Invoice::PrintInvoice() const
{
	cout << "��������� #" << invoice_number << endl;
	cout << "����: " << date << endl;
	cout << "������:" << endl;
	for (const auto& product : products) {
		cout << product << endl;
	}
	cout << "����� �����: " << fixed << setprecision(2) << CalculateTotal() << " ���." << endl;
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