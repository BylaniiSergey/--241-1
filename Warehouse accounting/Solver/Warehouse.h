#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> 
#include "Product.h"

using namespace std;

namespace bakery::warehouse
{
    /**
    * @brief ����� �����.
    */
    class Warehouse final
    {
    private:
        /**
        * @brief ������ ������� �� ������.
        */
        vector<product::Product> products;
    public:
        /**
        * @brief ����� ��� ���������� ������ �� �����.
        * @param product - �����, ������� ����� ��������.
        */
        void AddProduct(const product::Product& product);

        /**
        * @brief ����� ��� �������� ������ �� ������ �� ��������.
        * @param item_number - ������� ������, ������� ����� �������.
        * @return ���������� true, ���� ����� ��� ������� ������, � ��������� ������ - false.
        */
        bool RemoveProduct(const string& item_number);

        /**
        * @brief ����� ��� ������ ������ �� ��������.
        * @param item_number - ������� ������, ������� ����� �����.
        * @return ���������� ��������� �� ��������� ����� ��� nullptr, ���� ����� �� ������.
        */
        const bakery::product::Product* FindProduct(const string& item_number) const;
        /**
        * @brief ����� ��� ������ ���������� � ���� ������� �� ������.
        */
        void PrintInventory() const;

        /**
        * @brief ���������� (������ �� ���������).
        */
        ~Warehouse() = default;
    };
}