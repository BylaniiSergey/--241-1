#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    /**
    * @brief Класс ExerciseTask2, реализующий задачу Task2 для матрицы.
    */
    class ExerciseTask2 : public Exercise
    {
    public:
        /**
        * @brief Конструктор класса ExerciseTask2.
        * @param matrix Ссылка на матрицу, над которой будет выполняться задача.
        * @param generator Ссылка на генератор значений.
        */
        ExerciseTask2(Matrix& matrix, Generator& generator);

        /**
        * @brief Метод для выполнения задачи Task1.
        */
        void Task1() override;

        /**
        * @brief Метод для выполнения задачи Task2.
        */
        void Task2() override;
    };
}