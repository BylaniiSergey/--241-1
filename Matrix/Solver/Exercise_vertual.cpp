#include "Exercise_vertual.h"
#include <iostream>

namespace miit::matrix::exercises
{
    Exercise_vertual::Exercise_vertual(
        const int rows,
        const int columns,
        std::unique_ptr<miit::algebra::Generator> generator,
        std::ostream& out)
        : out(out)
    {
        matrix = std::make_unique<miit::algebra::Matrix>(rows, columns, *generator);
    }

    Exercise_vertual::~Exercise_vertual() = default;

    void Exercise_vertual::Run()
    {
        out << "=== " << title() << " ===" << std::endl;

        out << "Исходная матрица:" << std::endl;
        out << *matrix << std::endl;

        out << "Результат выполнения Task 1:" << std::endl;
        Task1();

        out << "Результат выполнения Task 2:" << std::endl;
        Task2();
    }
}
