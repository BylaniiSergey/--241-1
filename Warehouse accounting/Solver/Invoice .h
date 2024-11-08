#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Product.h" 

using namespace std;

namespace bakery::invoice
{
    /**
    * @brief ����� ���������.
    */
    class Invoice final
    {
    private:
        /**
        * @brief ����� ���������.
        */
        string invoice_number;
        /**
        * @brief ���� ���������.
        */
        string date;
        /**
        * @brief ������ ������� � ���������.
        */
        vector<product::Product> products;
    public:
        /**
        * @brief �����������.
        * @param invoice_number - ����� ���������.
        * @param date - ���� ���������.
        */
        Invoice(const string& invoice_number, const string& date) : invoice_number(invoice_number), date(date) {};

        /**
        * @brief ����� ��� ���������� ������ � ���������.
        * @param product - �����, ������� ����� ��������.
        */
        void AddProduct(const product::Product& product);

        /**
        * @brief ����� ��� ������� ����� ����� ���������.
        * @return ���������� ����� ����� ���������.
        */
        double CalculateTotal() const;

        /**
        * @brief ����� ��� ������ ���������� � ���������.
        */
        void PrintInvoice() const;

        /**
        * @brief ���������� (������ �� ���������).
        */
        ~Invoice() = default;
    };
}