#pragma once
#include <iostream>
#include <sstream>
#include <string>

namespace bakery::shop
{
	/**
	* @brief Класс Магазин.
	* Данный класс представляет магазин с его уникальными характеристиками, такими как идентификационный номер налогоплательщика, название и адрес.
	*/
	class Store final
	{
	private:
		/**
		* @brief Идентификационный номер налогоплательщика.
		* Уникальный номер, присвоенный магазину для налоговых целей.
		*/
		int taxpayer_id;

		/**
		* @brief Название магазина.
		* Наименование магазина, которое будет отображаться клиентам.
		*/
		std::string shop_name;

		/**
		* @brief Адрес магазина.
		* Физический адрес, по которому расположен магазин.
		*/
		std::string shop_address;

	public:
		/**
		* @brief Конструктор класса Store.
		* Инициализирует новый объект магазина с заданными параметрами.
		* @param taxpayer_id - идентификационный номер налогоплательщика.
		* @param shop_name - название магазина.
		* @param shop_address - адрес магазина.
		*/
		Store(int taxpayer_id, const std::string& shop_name, const std::string& shop_address);

		/**
		* @brief Метод сериализации в строку ToString().
		* Формирует строку, содержащую информацию о магазине в удобочитаемом формате.
		* @return Возвращает строку, содержащую название магазина, адрес и идентификационный номер налогоплательщика.
		*/
		std::string toString() const;

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
		friend std::ostream& operator<<(std::ostream& os, const Store& shop);

		/**
		* @brief Деструктор (создан по умолчанию).
		*/
		~Store() = default;
	};
}