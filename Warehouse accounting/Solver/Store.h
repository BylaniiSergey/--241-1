#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace bakery::shop
{
    /**
    * @brief Класс Магазин.
    */
    class Store final
    {
    private:
        /**
        * @brief ИНН.
        */
        int taxpayer_id;

        /**
        * @brief Название магазина.
        */
        string shop_name;

        /**
        * @brief Адрес магазина.
        */
        string shop_address;
	public:
		/**
		* @brief Конструктор.
		* @param taxpayer_id - ИНН.
		* @param shop_name - название магазина.
		* @param shop_address - адрес магазина.
		*/
		Store(const int taxpayer_id, const string& shop_name, const string& shop_address);

		/**
		* @brief Конструктор перемещения (создан по умолчанию).
		* @param other_shop - другой магазин.
		*/
		Store(Store&& other_shop) = default;

		/**
		* @brief Конструктор копирования (запрещён).
		* @param other_shop - другой магазин.
		*/
		Store(const Store& other_shop) = delete;

		/**
		* @brief Переопределение оператора присваивания для конструктора перемещения (создано по умолчанию).
		* @param other_shop - другой магазин.
		* @return Возвращает созданный магазин.
		*/
		Store& operator=(Store&& other_shop) = default;

		/**
		* @brief Переопределение оператора присваивания для конструктора копирования (запрещено).
		* @param other_shop - другой магазин.
		*/
		Store& operator=(const Store& other_shop) = delete;

		/**
		* @brief Переопределение оператора сравнения на равенство.
		* @param other_shop - магазин, с которым будем сравнивать.
		* @return Возвращает true, если два объекта равны, в противном случае - false.
		*/
		bool operator==(const Store& other_shop);

		/**
		* @brief Переопределение оператора сдвига влево.
		* @param os - поток.
		* @param shop - магазин.
		* @return Возвращает поток с введённой в него информацией о магазине.
		*/
		friend ostream& operator<<(ostream& os, const Store& shop);

		/**
		* @brief Метод сериализации в строку ToString().
		* @return Возвращает строку, в которой содержится информация о магазине.
		*/
		string ToString() const;

		/**
		* @brief Деструктор (создан по умолчанию).
		*/
		~Store() = default;
    };
}