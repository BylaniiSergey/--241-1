#pragma once

#include "Matrix.h"
#include "Generator.h"
#include <string>
#include <sstream>

namespace miit::algebra
{
    /**
    * @brief обстрактный базовый класс Exercise, представляющий задачу, которая может быть выполнена над матрицей.
    */
    class Exercise
    {
    protected:
        /**
        * @brief ссылка на матрицу, над которой будет выполняться задача.
        */
        Matrix matrix;

        /**
        * @brief ссылка на генератор значений, используемый для заполнения матрицы.
        */
        Generator& generator;

    public:
        /**
        * @brief конструктор класса Exercise.
        * @param matrix ссылка на матрицу, над которой будет выполняться задача.
        * @param generator ссылка на генератор значений.
        */
        Exercise(Matrix& matrix, Generator& generator);

        /**
        * @brief виртуальный деструктор.
        */
        ~Exercise() = default;

        /**
        * @brief метод для выполнения задачи Task1.
        */
        std::string Task1();

        /**
        * @brief метод для выполнения задачи Task2.
        */
       std::string Task2();

       /**
       * @brief Возвращает строковое представление задачи.
       * @return Строковое представление задачи.
       */
       std::string toString() const;
    };
}