#pragma once

#include "Matrix.h"
#include "Generator.h"

namespace miit::algebra
{
    class Exercise
    {
    protected:
        Matrix matrix;
        Generator& generator;

    public:
        Exercise(Matrix& matrix, Generator& generator);
        virtual ~Exercise() = default;

        virtual void Task1() = 0;
        virtual void Task2() = 0;
    };
}