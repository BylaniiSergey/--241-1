#pragma once

#include "Generator.h"
#include <iostream>

namespace miit::algebra
{
    /**
    * @brief Класс IStreamGenerator, реализующий интерфейс Generator для генерации значений из входного потока.
    */
    class IStreamGenerator : public Generator
    {
    private:
        /**
        * @brief Ссылка на входной поток, из которого будут считываться значения.
        */
        std::istream& in;

    public:
        /**
        * @brief Конструктор класса IStreamGenerator.
        * @param in Ссылка на входной поток.
        */
        IStreamGenerator(std::istream& in = std::cin);

        /**
        * @brief Метод для генерации значения из входного потока.
        * @return Считанное значение типа int.
        */
        int generate() override;
    };
}