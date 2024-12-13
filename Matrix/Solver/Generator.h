#pragma once

namespace miit::algebra
{
    /**
    * @brief 
    */
    class Generator
    {
    public:
        /**
        * @brief 
        */
        virtual ~Generator() = 0 {};

        /**
        * @brief 
        * @return 
        */
        virtual int generate() = 0;
    };
}