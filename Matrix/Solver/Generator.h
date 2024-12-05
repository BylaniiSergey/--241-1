#pragma once

namespace miit::algebra
{
    /**
    * @brief јбстрактный базовый класс Generator.
    */
    class Generator
    {
    public:
        /**
        * @brief ¬иртуальный деструктор.
        */
        virtual ~Generator() = 0 {};

        /**
        * @brief „исто виртуальный метод дл¤ генерации значени¤.
        * @return —генерированное значение типа int.
        */
        virtual int generate() = 0;
    };
}