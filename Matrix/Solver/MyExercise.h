#pragma once
#include "Exercise_vertual.h"

class MyExercise : public miit::matrix::exercises::Exercise_vertual
{
public:
    MyExercise(
        const int rows,
        const int columns,
        std::unique_ptr<miit::algebra::Generator> generator,
        std::ostream& out = std::cout)
        : Exercise_vertual(rows, columns, std::move(generator), out) {}

protected:
    std::string title() const noexcept override;
    void Task1() override;
    void Task2() override;
};
