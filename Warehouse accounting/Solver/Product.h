#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace bakery::product
{
	/**
	* @brief Класс Товар.
	*/
	class Product final
	{
	private:
		/**
		* @brief Артикул товара.
		*/
		string item_number;

		/**
		* @brief Название товара.
		*/
		string product_name;

		/**
		* @brief Цена товара (за 1 шт.).
		*/
		double price;
	public:
		/**
			* @brief Конструктор.
			* @param item_number - артикул товара.
			* @param product_name - название товара.
			* @param price - цена товара (за 1 шт.).
			*/
		Product(const string& item_number, const string& product_name, double price);

		/**
		* @brief Конструктор перемещения (создан по умолчанию).
		* @param other_product - другой товар.
		*/
		Product(Product&& other_product) = default;

		/**
		* @brief Конструктор копирования (запрещён).
		* @param other_product - другой товар.
		*/
		Product(const Product& other_product) = delete;

		/**
		* @brief Переопределение оператора присваивания для конструктора перемещения (создано по умолчанию).
		* @param other_product - другой товар.
		* @return Возвращает созданный товар.
		*/
		Product& operator=(Product&& other_product) = default;

		/**
		* @brief Переопределение оператора присваивания для конструктора копирования (запрещено).
		* @param other_product - другой товар.
		*/
		Product& operator=(const Product& other_product) = delete;

		/**
		* @brief Переопределение оператора сравнения на равенство.
		* @param other_product - товар, с которым будем сравнивать.
		* @return Возвращает true, если два объекта равны, в противном случае - false.
		*/
		bool operator==(const Product& other_product);

		/**
		* @brief Переопределение оператора сдвига влево.
		* @param os - поток.
		* @param product - товар.
		* @return Возвращает поток с введённой в него информацией о товаре.
		*/
		friend ostream& operator<<(ostream& os, const Product& product);

		/**
		* @brief Метод сериализации в строку ToString().
		* @return Возвращает строку, в которой содержится информация о товаре.
		*/
		string ToString() const;

		/**
		* @brief Деструктор (создан по умолчанию).
		*/
		~Product() = default;

		double GetPrice() const;
	};
}