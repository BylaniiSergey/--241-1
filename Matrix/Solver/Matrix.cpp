#include "Matrix.h"
#include "Generator.h"

namespace miit::algebra
{
    Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows, std::vector<int>(cols)) {}

    Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(other.data) {}

    Matrix::Matrix(Matrix&& other) noexcept : rows(other.rows), cols(other.cols), data(std::move(other.data))
    {
        other.rows = 0;
        other.cols = 0;
    }

    Matrix& Matrix::operator=(const Matrix& other)
    {
        if (this != &other)
        {
            rows = other.rows;
            cols = other.cols;
            data = other.data;
        }
        return *this;
    }

    Matrix& Matrix::operator=(Matrix&& other) noexcept
    {
        if (this != &other)
        {
            rows = other.rows;
            cols = other.cols;
            data = std::move(other.data);
            other.rows = 0;
            other.cols = 0;
        }
        return *this;
    }

    std::vector<int>& Matrix::operator[](int index)
    {
        return data[index];
    }

    const std::vector<int>& Matrix::operator[](int index) const
    {
        return data[index];
    }

    int Matrix::getRows() const
    {
        return rows;
    }

    int Matrix::getCols() const
    {
        return cols;
    }

    void Matrix::fill(Generator& generator)
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                data[i][j] = generator.generate();
            }
        }
    }

    void Matrix::print(std::ostream& os) const
    {
        for (const auto& row : data)
        {
            for (const auto& elem : row)
            {
                os << elem << " ";
            }
            os << std::endl;
        }
    }
}