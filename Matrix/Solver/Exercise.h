#pragma once

#include "Matrix.h"
#include "Generator.h"

namespace miit::algebra
{
    /**
    * @brief јбстрактный базовый класс Exercise, представл¤ющий задачу, котора¤ может быть выполнена над матрицей.
    */
    class Exercise
    {
    protected:
        /**
        * @brief —сылка на матрицу, над которой будет выполн¤тьс¤ задача.
        */
        Matrix matrix;

        /**
        * @brief —сылка на генератор значений, используемый дл¤ заполнени¤ матрицы.
        */
        Generator& generator;

    public:
        /**
        * @brief  онструктор класса Exercise.
        * @param matrix —сылка на матрицу, над которой будет выполн¤тьс¤ задача.
        * @param generator —сылка на генератор значений.
        */
        Exercise(Matrix& matrix, Generator& generator);

        /**
        * @brief ¬иртуальный деструктор.
        */
        virtual ~Exercise() = default;

        /**
        * @brief „исто виртуальный метод дл¤ выполнени¤ задачи Task1.
        */
        virtual void Task1() = 0;

        /**
        * @brief „исто виртуальный метод дл¤ выполнени¤ задачи Task2.
        */
        virtual void Task2() = 0;
    };
}