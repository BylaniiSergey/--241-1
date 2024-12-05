#include "ExerciseTask1.h"

namespace miit::algebra
{
    ExerciseTask1::ExerciseTask1(Matrix& matrix, Generator& generator) : Exercise(matrix, generator) {}

    void ExerciseTask1::Task1()
    {
        for (int i = 0; i < matrix.getRows(); ++i)
        {
            int max_elem = matrix[i][0];
            for (int j = 1; j < matrix.getCols(); ++j)
            {
                if (matrix[i][j] > max_elem)
                {
                    max_elem = matrix[i][j];
                }
            }
            for (int j = 0; j < matrix.getCols(); ++j)
            {
                if (matrix[i][j] == max_elem)
                {
                    matrix[i][j] = -max_elem;
                }
            }
        }
    }

    void ExerciseTask1::Task2() {}
}