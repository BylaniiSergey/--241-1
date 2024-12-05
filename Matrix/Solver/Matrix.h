#pragma once
#include "Generator.h"
#include <vector>
#include <iostream>

namespace miit::algebra
{
    /**
    * @brief Класс Matrix представляет двумерный массив (матрицу) целых чисел.
    */
    class Matrix
    {
    private:
        /**
        * @brief Двумерный массив целых чисел, представляющий матрицу.
        */
        std::vector<std::vector<int>> data;

        /**
        * @brief Количество строк в матрице.
        */
        int rows;

        /**
        * @brief Количество столбцов в матрице.
        */
        int cols;

    public:
        /**
        * @brief Конструктор для создания матрицы с заданным количеством строк и столбцов.
        * @param rows Количество строк в матрице.
        * @param cols Количество столбцов в матрице.
        */
        Matrix(int rows, int cols);

        /**
        * @brief Конструктор копирования.
        * @param other Матрица, которую нужно скопировать.
        */
        Matrix(const Matrix& other);

        /**
        * @brief Конструктор перемещения.
        * @param other Матрица, данные которой нужно переместить.
        */
        Matrix(Matrix&& other) noexcept;

        /**
        * @brief Деструктор.
        */
        ~Matrix() = default;

        /**
        * @brief Оператор присваивания копированием.
        * @param other Матрица, данные которой нужно скопировать.
        * @return Ссылка на текущую матрицу.
        */
        Matrix& operator=(const Matrix& other);

        /**
        * @brief Оператор присваивания перемещением.
        * @param other Матрица, данные которой нужно переместить.
        * @return Ссылка на текущую матрицу.
        */
        Matrix& operator=(Matrix&& other) noexcept;

        /**
        * @brief Оператор доступа к элементу матрицы по индексу строки.
        * @param index Индекс строки.
        * @return Ссылка на вектор, представляющий строку матрицы.
        */
        std::vector<int>& operator[](int index);

        /**
        * @brief Оператор доступа к элементу матрицы по индексу строки (константный).
        * @param index Индекс строки.
        * @return Константная ссылка на вектор, представляющий строку матрицы.
        */
        const std::vector<int>& operator[](int index) const;

        /**
        * @brief Возвращает количество строк в матрице.
        * @return Количество строк в матрице.
        */
        int getRows() const;

        /**
        * @brief Возвращает количество столбцов в матрице.
        * @return Количество столбцов в матрице.
        */
        int getCols() const;

        /**
        * @brief Заполняет матрицу значениями, сгенерированными объектом Generator.
        * @param generator Объект, генерирующий значения для заполнения матрицы.
        */
        void fill(Generator& generator);

        /**
        * @brief Выводит содержимое матрицы в поток вывода.
        * @param os Поток вывода, в который будет выведено содержимое матрицы.
        */
        void print(std::ostream& os) const;
    };
}