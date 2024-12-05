#pragma once

#include "Exercise.h"

namespace miit::algebra
{
    class ExerciseTask1 : public Exercise
    {
    public:
        ExerciseTask1(Matrix& matrix, Generator& generator);
        void Task1() override;
        void Task2() override;
    };
}
