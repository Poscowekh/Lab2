#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H
#include <string>

template<class DataType, class ...ArgumentsType>
class Function
{
    public:
        const std::string name;
        DataType(*const function)(ArgumentsType...);
        DataType operator()(ArgumentsType... arguments)
        {
            return function(arguments...);
        };
};

#endif // FUNCTION_H
