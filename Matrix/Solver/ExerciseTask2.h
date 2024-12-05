#pragma once

#include "Exercise.h"

namespace miit::algebra
{
    class ExerciseTask2 : public Exercise
    {
    public:
        ExerciseTask2(Matrix& matrix, Generator& generator);
        void Task1() override;
        void Task2() override;
    };
}