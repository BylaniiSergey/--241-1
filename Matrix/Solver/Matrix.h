#pragma once
#include "Generator.h"
#include <vector>
#include <iostream>

namespace miit::algebra
{
    class Matrix
    {
    private:
        std::vector<std::vector<int>> data;
        int rows;
        int cols;

    public:
        Matrix(int rows, int cols);
        Matrix(const Matrix& other);
        Matrix(Matrix&& other) noexcept;
        ~Matrix() = default;

        Matrix& operator=(const Matrix& other);
        Matrix& operator=(Matrix&& other) noexcept;

        std::vector<int>& operator[](int index);
        const std::vector<int>& operator[](int index) const;

        int getRows() const;
        int getCols() const;

        void fill(Generator& generator);
        void print(std::ostream& os) const;
    };
}