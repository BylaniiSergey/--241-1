#include "MyExercise.h"
#include <iostream>

std::string MyExercise::title() const noexcept
{
    return "My Exercise";
}

void MyExercise::Task1()
{
    out << "Выполнение задачи 1:" << std::endl;

    for (int i = 0; i < matrix->getRows(); ++i)
    {
        int max_elem = (*matrix)[i][0];
        for (int j = 1; j < matrix->getCols(); ++j)
        {
            if ((*matrix)[i][j] > max_elem)
            {
                max_elem = (*matrix)[i][j];
            }
        }

        for (int j = 0; j < matrix->getCols(); ++j)
        {
            if ((*matrix)[i][j] == max_elem)
            {
                (*matrix)[i][j] = -max_elem;
            }
        }
    }

    out << *matrix << std::endl;
}


void MyExercise::Task2()
{
    out << "Выполнение задачи 2:" << std::endl;

    for (int j = 0; j < matrix->getCols(); ++j)
    {
        int max_elem = (*matrix)[0][j];
        for (int i = 1; i < matrix->getRows(); ++i)
        {
            if ((*matrix)[i][j] > max_elem)
            {
                max_elem = (*matrix)[i][j];
            }
        }

        for (int i = 0; i < matrix->getRows(); ++i)
        {
            for (int k = 0; k < matrix->getCols(); ++k)
            {
                if ((*matrix)[i][k] == max_elem)
                {
                    (*matrix)[i].insert((*matrix)[i].begin() + k + 1, 0);
                    k++;
                }
            }
        }
    }

    out << *matrix << std::endl;
}