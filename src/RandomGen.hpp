#pragma once
#include <random>
#include "DataTypes.h"
#include "DynamicArray.h"

using namespace std;

int RandomInt(int seed)
{
    srand(seed);
    int r = rand() % 2000 - 1000;
    return r;
};

float RandomFloat(int seed)
{
    srand(seed);
    float tmp1 = (float)RandomInt(seed);
    seed = seed + RandomInt(seed);
    srand(seed);
    float tmp2 = (float)RandomInt(seed);
    float r = (tmp1 / tmp2);
    return r;
};

string RandomChar(int seed)
{
    srand(seed);
    return to_string((char)(rand() % (127 - 33) + 33));
};

string RandomString(int seed, int size)
{
    string r;
    for(int i = 0; i < size; i++)
    {
        r = r + RandomChar(seed);
        seed = seed + RandomInt(seed);
    };
    return r;
};

DynamicArray<int>* IntArray(int seed, int size)
{
    DynamicArray<int>* result = new DynamicArray<int>();
    srand(seed);
    for(int i = 0; i < size; i++)
    {
        result->PushFront(RandomInt(seed));
        seed = seed + RandomInt(seed);
        srand(seed);
    };
    return result;
};

DynamicArray<float>* FloatArray(int seed, int size)
{
    DynamicArray<float>* result = new DynamicArray<float>();
    srand(seed);
    for(int i = 0; i < size; i++)
    {
        result->PushFront(RandomFloat(seed));
        seed = seed + RandomInt(seed);
        srand(seed);
    };
    return result;
};

DynamicArray<string>* StringArray(int seed, int size, int string_size)
{
    DynamicArray<string>* result = new DynamicArray<string>();
    srand(seed);
    for(int i = 0; i < size; i++)
    {
        result->PushFront(RandomString(seed, string_size));
        seed = seed + RandomInt(seed);
        srand(seed);
    };
    return result;
};

DynamicArray<string>* StringArray(int seed, int size)
{
    DynamicArray<string>* result = new DynamicArray<string>();
    srand(seed);
    int random_size = rand() % 3 + 3;
    for(int i = 0; i < size; i++)
    {
        result->PushFront(RandomString(seed, random_size));
        seed = seed + RandomInt(seed);
        srand(seed);
    };
    return result;
};

DynamicArray< Complex<int, int> >* IntComplexArray(int seed, int size)
{
    DynamicArray< Complex<int, int> >* result = new DynamicArray< Complex<int, int> >();
    srand(seed);
    for(int i = 0; i < size; i++)
    {
        int tmp1 = RandomInt(seed);
        seed = seed + RandomInt(seed);
        srand(seed);
        int tmp2 = RandomInt(seed);
        seed = seed + RandomInt(seed);
        srand(seed);
        Complex<int, int> tmp(tmp1, tmp2);
        result->PushFront(tmp);
    };
    return result;
};

DynamicArray< Complex<float, float> >* FloatComplexArray(int seed, int size)
{
    DynamicArray< Complex<float, float> >* result = new DynamicArray< Complex<float, float> >();
    srand(seed);
    for(int i = 0; i < size; i++)
    {
        float tmp1 = RandomFloat(seed);
        seed = seed + RandomInt(seed);
        srand(seed);
        float tmp2 = RandomFloat(seed);
        seed = seed + RandomInt(seed);
        srand(seed);
        Complex<float, float> tmp(tmp1, tmp2);
        result->PushFront(tmp);
    };
    return result;
};
