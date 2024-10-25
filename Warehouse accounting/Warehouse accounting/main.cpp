#include <iostream>
#include <vector>
#include "..//Solver/Product.h"
#include "..//Solver/Store.h"
#include "..//Solver/Warehouse.h"
#include "..//Solver/Invoice .h"

int main()
{
    std::vector<Product*> inventory;
    // �������� ���������
    Product* product1 = new Product("Product A", 10.0);
    Product* product2 = new Product("Product B", 20.0);

    // �������� ��������
    Store store("Store 1", 5.0);

    // �������� ������
    Warehouse warehouse;
    warehouse.addProduct(product1);
    warehouse.addProduct(product2);

    // �������� �������� �� ������
    std::cout << "Products in Warehouse:" << std::endl;
    warehouse.showProducts();

    // �������� ��������� ���������
    Invoice invoice;
    invoice.addProduct(product1);
    invoice.addProduct(product2);

    // �������� ���������
    std::cout << "Invoice:" << std::endl;
    invoice.showInvoice();

    // ������� ������
    delete product1;
    delete product2;

    return 0;
}