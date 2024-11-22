#pragma once
#include <iostream>
#include <sstream>
#include <string>

namespace bakery::client
{
	/**
	* @brief Класс, представляющий клиента.
	* Данный класс содержит информацию о клиенте, включая его имя и
	* процент скидки, который он может получить.
	*/
	class Client final
	{
	private:
		std::string name;
		double discount;

	public:
		/**
		* @brief Конструктор класса Client.
		* Данный конструктор инициализирует объект клиента с заданным именем и процентом скидки.
		* @param name Имя клиента.
		* @param discount Процент скидки, который будет применяться к покупкам клиента.
		*/
		Client(const std::string& name, double discount);

		/**
		* @brief Метод получения строкового представления клиента.
		* Данный метод возвращает строку, содержащую информацию о клиенте, включая его имя и процент скидки.
		* @return Строковое представление клиента.
		*/
		std::string toString() const;

		/**
		* @brief Конструктор перемещения (создан по умолчанию).
		* @param other_client - другой клиент.
		*/
		Client(Client&& other_client) = default;

		/**
		* @brief Конструктор копирования (запрещён).
		* @param other_client - другой клиетн.
		*/
		Client(const Client& other_client) = delete;

		/**
		* @brief Переопределение оператора присваивания для конструктора перемещения (создано по умолчанию).
		* @param other_client - другой клиент.
		* @return Возвращает созданный клиент.
		*/
		Client& operator=(Client&& other_client) = default;

		/**
		* @brief Переопределение оператора присваивания для конструктора копирования (запрещено).
		* @param other_client - другой клиент.
		*/
		Client& operator=(const Client& other_client) = delete;

		/**
		* @brief Переопределение оператора сравнения на равенство.
		* @param other_client - клиент, с которым будем сравнивать.
		* @return Возвращает true, если два объекта равны, в противном случае - false.
		*/
		bool operator==(const Client& other_client);

		/**
		* @brief Переопределение оператора сдвига влево.
		* @param os - поток.
		* @param client - клиент.
		* @return Возвращает поток с введённой в него информацией о магазине.
		*/
		friend std::ostream& operator<<(std::ostream& os, const Client& client);

		/**
		* @brief Деструктор (создан по умолчанию).
		*/
		~Client() = default;

		double GetDiscount() const;
	};
}