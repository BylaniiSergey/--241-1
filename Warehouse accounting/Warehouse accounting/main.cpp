#include <iostream>
#include <string>
#include "..//Solver/Warehouse.h"
#include "..//Solver/Product.h"
#include "..//Solver/Store.h"
#include "..//Solver/Invoice .h"

using namespace std;

int main() 
{
    // �������� ������
    bakery::warehouse::Warehouse warehouse;
    // �������� ���������
    bakery::product::Product product1("001", "����", 50.2);
    bakery::product::Product product2("002", "�������", 25.3);
    bakery::product::Product product3("003", "��������", 30.9);
    // ���������� ��������� �� �����
    warehouse.AddProduct(product1);
    warehouse.AddProduct(product2);
    warehouse.AddProduct(product3);
    // ����� ���������� � ���� ������� �� ������
    cout << "��������� ������:" << endl;
    warehouse.PrintInventory();
    // ����� �������� �� ��������
    string search_item = "002";
    const bakery::product::Product* found_product = warehouse.FindProduct(search_item);
    if (found_product) {
        cout << "��������� �������: " << found_product->ToString() << endl;
    }
    else {
        cout << "������� � ��������� " << search_item << " �� ������." << endl;
    }
    // �������� �������� �� ������
    if (warehouse.RemoveProduct("001")) {
        cout << "������� � ��������� 001 ������� �����." << endl;
    }
    else {
        cout << "�� ������� ������� ������� � ��������� 001." << endl;
    }
    // ����� ���������� � ���� ������� �� ������ ����� ��������
    cout << "��������� ������ ����� ��������:" << endl;
    warehouse.PrintInventory();
    // �������� ��������
    bakery::shop::Store store(123456789, "������� �������", "����� �������, 1");
    // �������� ���������
    bakery::invoice::Invoice invoice("INV-001", "2023-10-01");
    invoice.AddProduct(product2);
    invoice.AddProduct(product3);
    // ����� ���������� � ���������
    cout << "���������:" << endl;
    invoice.PrintInvoice();
    cout << "����� ����� ���������: " << invoice.CalculateTotal() << " ���." << endl;
    return 0;
}