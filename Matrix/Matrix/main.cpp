#include <iostream>
#include <locale>
#include "..//Solver/Matrix.h"
#include "..//Solver/RandomGenerator.h"
#include "..//Solver/IStreamGenerator.h"
#include "..//Solver/ExerciseTask1.h"
#include "..//Solver/ExerciseTask2.h"

using namespace miit::algebra;

/**
* @brief Точка входа в программу
* @return 0 в случае успеха
*/
int main()
{
    setlocale(LC_ALL, "RU");
    int rows, cols;
    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;

    Matrix matrix(rows, cols);

    int choice;
    std::cout << "Выберите способ заполнения матрицы (1 - случайным образом, 2 - вручную):";
    std::cin >> choice;

    if (choice == 1)
    {
        RandomGenerator randomGenerator(1, 100);
        matrix.fill(randomGenerator);
    }
    else if (choice == 2)
    {
        IStreamGenerator istreamGenerator(std::cin);
        matrix.fill(istreamGenerator);
    }
    else
    {
        std::cerr << "Неверный выбор!" << std::endl;
        return 1;
    }

    std::cout << "Исходная матрица:" << std::endl;
    matrix.print(std::cout);

    ExerciseTask1 task1(matrix, *dynamic_cast<Generator*>(new RandomGenerator(1, 100)));
    task1.Task1();

    std::cout << "Матрица после выполнения задачи 1:" << std::endl;
    matrix.print(std::cout);

    ExerciseTask2 task2(matrix, *dynamic_cast<Generator*>(new RandomGenerator(1, 100)));
    task2.Task2();

    std::cout << "Матрица после выполнения задания 2:" << std::endl;
    matrix.print(std::cout);

    return 0;
}