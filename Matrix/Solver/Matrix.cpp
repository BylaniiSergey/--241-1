#include "Matrix.h"
#include "Generator.h"
#include <sstream>

namespace miit::algebra
{
    /**
    * @brief Конструктор для создания матрицы с заданным количеством строк и столбцов.
    * @param rows Количество строк в матрице.
    * @param cols Количество столбцов в матрице.
    */
    Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows, std::vector<int>(cols)) {}

    /**
    * @brief Конструктор копирования.
    * @param other Матрица, которую нужно скопировать.
    */
    Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(other.data) {}

    /**
    * @brief Конструктор перемещения.
    * @param other Матрица, данные которой нужно переместить.
    */
    Matrix::Matrix(Matrix&& other) noexcept : rows(other.rows), cols(other.cols), data(std::move(other.data))
    {
        other.rows = 0;
        other.cols = 0;
    }

    /**
    * @brief Оператор присваивания копированием.
    * @param other Матрица, данные которой нужно скопировать.
    * @return Ссылка на текущую матрицу.
    */
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

    /**
    * @brief Оператор присваивания перемещением.
    * @param other Матрица, данные которой нужно переместить.
    * @return Ссылка на текущую матрицу.
    */
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

    /**
    * @brief Оператор доступа к элементу матрицы по индексу строки.
    * @param index Индекс строки.
    * @return Ссылка на вектор, представляющий строку матрицы.
    */
    std::vector<int>& Matrix::operator[](int index)
    {
        return data[index];
    }

    /**
    * @brief Оператор доступа к элементу матрицы по индексу строки (константный).
    * @param index Индекс строки.
    * @return Константная ссылка на вектор, представляющий строку матрицы.
    */
    const std::vector<int>& Matrix::operator[](int index) const
    {
        return data[index];
    }

    /**
    * @brief Возвращает количество строк в матрице.
    * @return Количество строк в матрице.
    */
    int Matrix::getRows() const
    {
        return rows;
    }

    /**
    * @brief Возвращает количество столбцов в матрице.
    * @return Количество столбцов в матрице.
    */
    int Matrix::getCols() const
    {
        return cols;
    }

    /**
    * @brief Заполняет матрицу значениями, сгенерированными объектом Generator.
    * @param generator Объект, генерирующий значения для заполнения матрицы.
    */
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

    /**
    * @brief Выводит содержимое матрицы в поток вывода.
    * @param os Поток вывода, в который будет выведено содержимое матрицы.
    */
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

    /**
    * @brief Возвращает строковое представление матрицы.
    * @return Строковое представление матрицы.
    */
    std::string Matrix::toString() const
    {
        std::ostringstream oss;
        for (const auto& row : data)
        {
            for (const auto& elem : row)
            {
                oss << elem << " ";
            }
            oss << std::endl;
        }
        return oss.str();
    }
}