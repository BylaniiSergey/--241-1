#pragma once

#include "Exercise.h"

namespace miit::algebra
{
    /**
    * @brief Класс ExerciseTask1, реализующий задачу Task1 для матрицы.
    */
    class ExerciseTask1 : public Exercise
    {
    public:
        /**
        * @brief Конструктор класса ExerciseTask1.
        * @param matrix Ссылка на матрицу, над которой будет выполняться задача.
        * @param generator Ссылка на генератор значений.
        */
        ExerciseTask1(Matrix& matrix, Generator& generator);

        /**
        * @brief Метод для выполнения задачи Task1.
        */
        void Task1() override;

        /**
        * @brief Метод для выполнения задачи Task2 (пустая реализация).
        */
        void Task2() override;
    };
}