#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace bakery::product
{
	/**
	* @brief ����� �����.
	*/
	class Product final
	{
	private:
		/**
		* @brief ������� ������.
		*/
		string item_number;

		/**
		* @brief �������� ������.
		*/
		string product_name;

		/**
		* @brief ���� ������ (�� 1 ��.).
		*/
		double price;
	public:
		/**
			* @brief �����������.
			* @param item_number - ������� ������.
			* @param product_name - �������� ������.
			* @param price - ���� ������ (�� 1 ��.).
			*/
		Product(const string& item_number, const string& product_name, double price);

		/**
		* @brief ����������� ����������� (������ �� ���������).
		* @param other_product - ������ �����.
		*/
		Product(Product&& other_product) = default;

		/**
		* @brief ����������� ����������� (��������).
		* @param other_product - ������ �����.
		*/
		Product(const Product& other_product) = delete;

		/**
		* @brief ��������������� ��������� ������������ ��� ������������ ����������� (������� �� ���������).
		* @param other_product - ������ �����.
		* @return ���������� ��������� �����.
		*/
		Product& operator=(Product&& other_product) = default;

		/**
		* @brief ��������������� ��������� ������������ ��� ������������ ����������� (���������).
		* @param other_product - ������ �����.
		*/
		Product& operator=(const Product& other_product) = delete;

		/**
		* @brief ��������������� ��������� ��������� �� ���������.
		* @param other_product - �����, � ������� ����� ����������.
		* @return ���������� true, ���� ��� ������� �����, � ��������� ������ - false.
		*/
		bool operator==(const Product& other_product);

		/**
		* @brief ��������������� ��������� ������ �����.
		* @param os - �����.
		* @param product - �����.
		* @return ���������� ����� � �������� � ���� ����������� � ������.
		*/
		friend ostream& operator<<(ostream& os, const Product& product);

		/**
		* @brief ����� ������������ � ������ ToString().
		* @return ���������� ������, � ������� ���������� ���������� � ������.
		*/
		string ToString() const;

		/**
		* @brief ���������� (������ �� ���������).
		*/
		~Product() = default;

		double GetPrice() const;
	};
}