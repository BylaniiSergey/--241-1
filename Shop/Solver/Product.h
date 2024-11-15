#pragma once
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <sstream>
#include <string>

namespace bakery::product
{
	/**
	* @brief Класс Товар.
	*
	* Данный класс представляет товар, который хранится на складе.
	* Он содержит информацию о товаре, такую как артикул, название и цена.
	*/
	class Product final
	{
	private:
		/**
		* @brief Артикул товара.
		* Уникальный идентификатор товара, используемый для его идентификации.
		*/
		std::string item_number;

		/**
		* @brief Название товара.
		* Наименование товара, которое будет отображаться пользователю.
		*/
		std::string product_name;

		/**
		* @brief Цена товара (за 1 шт.).
		* Стоимость товара за одну единицу.
		*/
		double price;

	public:

		Product(const std::string& item_number, const std::string& product_name, double price);

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
		friend std::ostream& operator<<(std::ostream& os, const Product& product);

		/**
		* @brief Метод сериализации в строку ToString().
		* @return Возвращает строку, в которой содержится информация о товаре.
		*/
		std::string toString() const;

		/**
		* @brief Деструктор (создан по умолчанию).
		*/
		~Product() = default;

		/**
		* @brief Получение цены товара.
		* @return Возвращает цену товара (за 1 шт.).
		*/
		double GetPrice() const;
	};
}
#endif