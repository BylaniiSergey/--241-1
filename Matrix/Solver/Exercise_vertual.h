#pragma once

#include "..//Solver/Generator.h"
#include "..//Solver/Matrix.h"
#include <iostream>
#include <memory>

namespace miit::matrix::exercises
{
    class Exercise_vertual
    {
    protected:
        std::unique_ptr<miit::algebra::Matrix> matrix;
        std::ostream& out;

        virtual std::string title() const noexcept = 0;
        virtual void Task1() = 0;
        virtual void Task2() = 0;

    public:
        explicit Exercise_vertual(
            const int rows,
            const int columns,
            std::unique_ptr<miit::algebra::Generator> generator,
            std::ostream& out = std::cout);

        virtual ~Exercise_vertual();

        void Run();
    };
}