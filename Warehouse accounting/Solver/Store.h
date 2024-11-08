#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace bakery::shop
{
    /**
    * @brief ����� �������.
    */
    class Store final
    {
    private:
        /**
        * @brief ���.
        */
        int taxpayer_id;

        /**
        * @brief �������� ��������.
        */
        string shop_name;

        /**
        * @brief ����� ��������.
        */
        string shop_address;
	public:
		/**
		* @brief �����������.
		* @param taxpayer_id - ���.
		* @param shop_name - �������� ��������.
		* @param shop_address - ����� ��������.
		*/
		Store(const int taxpayer_id, const string& shop_name, const string& shop_address);

		/**
		* @brief ����������� ����������� (������ �� ���������).
		* @param other_shop - ������ �������.
		*/
		Store(Store&& other_shop) = default;

		/**
		* @brief ����������� ����������� (��������).
		* @param other_shop - ������ �������.
		*/
		Store(const Store& other_shop) = delete;

		/**
		* @brief ��������������� ��������� ������������ ��� ������������ ����������� (������� �� ���������).
		* @param other_shop - ������ �������.
		* @return ���������� ��������� �������.
		*/
		Store& operator=(Store&& other_shop) = default;

		/**
		* @brief ��������������� ��������� ������������ ��� ������������ ����������� (���������).
		* @param other_shop - ������ �������.
		*/
		Store& operator=(const Store& other_shop) = delete;

		/**
		* @brief ��������������� ��������� ��������� �� ���������.
		* @param other_shop - �������, � ������� ����� ����������.
		* @return ���������� true, ���� ��� ������� �����, � ��������� ������ - false.
		*/
		bool operator==(const Store& other_shop);

		/**
		* @brief ��������������� ��������� ������ �����.
		* @param os - �����.
		* @param shop - �������.
		* @return ���������� ����� � �������� � ���� ����������� � ��������.
		*/
		friend ostream& operator<<(ostream& os, const Store& shop);

		/**
		* @brief ����� ������������ � ������ ToString().
		* @return ���������� ������, � ������� ���������� ���������� � ��������.
		*/
		string ToString() const;

		/**
		* @brief ���������� (������ �� ���������).
		*/
		~Store() = default;
    };
}