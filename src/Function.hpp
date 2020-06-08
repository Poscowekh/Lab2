#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H
#include <string>

using namespace std;

template<typename Container, typename Function>
Container* Map(Container* container, Function function)
{
    Container* result = new Container;
    for(int i = 0; i < container->GetLength(); ++i)
        result->PushBack(function(container->Get(i)));
    return result;
};

template<typename Container, typename Function>
Container* Where(Container* container, Function function)
{
    Container* result = new Container;
    for(int i = 0; i < container->GetLength(); ++i)
        if(function(container->Get(i)))
            result->PushBack(container->Get(i));
    return result;
};

template<typename DataType, typename Container, typename Function>
DataType Reduce(Container* container, Function function, DataType const_value)
{
    DataType result = function(container->Get(0), const_value);
    for(int i = 1; i < container->GetLength(); ++i)
        result = function(container->Get(i), result);
    return result;
};

template<typename Container>
Container* Sort(Container* container)
{
    Container* result = new Container(*container);
    for(int i = 0; i < result->GetLength() - 1; i++)
        for(int j = i; j < result->GetLength(); j++)
            if(result->Get(i) > result->Get(j))
            {
                auto tmp = result->Get(i);
                result->Set(i, result->Get(j));
                result->Set(j, tmp);
            };
    return result;
};

template<class ReturnType, class ArgumentType>
class TestFunctionWithArgs
{
    public:
        string function_name;
        ReturnType(*const function(ArgumentType))();
        ReturnType operator()()
        {
            return function();
        };
        TestFunctionWithArgs(string func_name, ReturnType(*const func(ArgumentType))())
        {
            function_name = func_name;
            function = func;
        };
};

template<class ReturnType>
class TestFunction
{
    public:
        string function_name;
        ReturnType(*function)() = 0;
        ReturnType operator()()
        {
            return function();
        };
        TestFunction(string func_name, ReturnType(*const func)())
        {
            function_name = func_name;
            function = func;
        };
};

#endif // FUNCTION_H
