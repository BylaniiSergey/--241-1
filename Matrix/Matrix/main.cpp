﻿#include "..//Solver/Matrix.h"
#include "..//Solver/Generator.h"
#include "..//Solver/IStreamGenerator.h"
#include "..//Solver/RandomGenerator.h"
#include "..//Solver/Exercise_vertual.h"
#include "..//Solver/MyExercise.h"
#include <iostream>
#include <locale>

int main()
{
    setlocale(LC_ALL, "RU");
    std::unique_ptr<miit::algebra::Generator> randomGenerator = std::make_unique<miit::algebra::RandomGenerator>(1, 100);

    MyExercise exercise(3, 3, std::move(randomGenerator));

    exercise.Run();

    return 0;
}