#pragma once

#include "Matrix.h"
#include "Generator.h"

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
        virtual ~Exercise() = default;

        /**
        * @brief чисто виртуальный метод для выполнения задачи Task1.
        */
        virtual void Task1() = 0;

        /**
        * @brief яисто виртуальный метод для выполнения задачи Task2.
        */
        virtual void Task2() = 0;
    };
}