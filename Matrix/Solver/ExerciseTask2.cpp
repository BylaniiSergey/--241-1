#include "ExerciseTask2.h"

namespace miit::algebra
{
    ExerciseTask2::ExerciseTask2(Matrix& matrix, Generator& generator) : Exercise(matrix, generator) {}

    void ExerciseTask2::Task2()
    {
        std::vector<int> max_cols;
        for (int j = 0; j < matrix.getCols(); ++j)
        {
            int max_elem = matrix[0][j];
            bool is_max_col = true;
            for (int i = 1; i < matrix.getRows(); ++i)
            {
                if (matrix[i][j] > max_elem)
                {
                    max_elem = matrix[i][j];
                    is_max_col = false;
                }
                else if (matrix[i][j] != max_elem)
                {
                    is_max_col = false;
                }
            }
            if (is_max_col)
            {
                max_cols.push_back(j);
            }
        }

        for (int col : max_cols)
        {
            for (int i = 0; i < matrix.getRows(); ++i)
            {
                matrix[i].insert(matrix[i].begin() + col + 1, 0);
            }
        }
    }

    void ExerciseTask2::Task1() {}
}