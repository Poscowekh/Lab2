#pragma once
#include "../../Structures/Result/Deque.hpp"
#include "../../Utility/Randomization/RandomGen.hpp"
#include "../Basic/TestFunctions.hpp"
#include "../../Utility/UtilityFunctions/Functions.hpp"
#include "../Basic/Check.h"
#include <time.h>

using namespace std;

Check TestDequeCreate()
{
    srand(time(NULL));
    Deque<int>* deque;
    int size = rand() % 1000 + 1;
    deque = new Deque<int>();
    if(deque->GetLength() != 0)
        return ERROR;
    int* data = (int*)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++)
        memcpy(data + i, &size, sizeof(int));
    deque = new Deque<int>(data, size);
    if(deque->GetLength() != size)
        return ERROR;
    for(int i = 0; i < deque->GetLength(); i++)
        if(deque->Get(i) != size)
            return ERROR;
    Deque<int>* deque_copy = new Deque<int>(*deque);
    if(deque_copy->GetLength() != size)
        return ERROR;
    for(int i = 0; i < deque_copy->GetLength(); i++)
        if(deque_copy->Get(i) != size)
            return ERROR;
    delete deque;
    delete deque_copy;
    return NO_ERROR;
};

Check TestDequeSetGet()
{
    int seed = time(NULL);
    srand(seed);
    int size = rand() % 1000 + 1;
    seed++;
    Deque<int>* deque = new Deque<int>();
    for(int i = 0; i < size; i++)
        deque->PushBack(0);
    int tmp = RandomInt(seed);
    for(int i = 0; i < size; i++)
    {
        deque->Set(i, tmp);
    };
    if(deque->GetLength() != size)
        return ERROR;
    for(int i = 0; i < size; i++)
        if(deque->Get(i) != tmp)
            return ERROR;
    delete deque;
    return NO_ERROR;
};

Check TestDequePushPop()
{
    int seed = time(NULL);
    srand(seed);
    Deque<int>* deque = new Deque<int>();
    int r_size = rand() % 1000 + 1;
    int a = RandomInt(seed);
    seed++;
    for(int i = 0; i < r_size; i++)
        deque->PushBack(a);
    if(deque->GetLength() != r_size)
        return ERROR;
    for(int i = 0; i < deque->GetLength(); i++)
        if(deque->Get(i) != a)
            return ERROR;
    srand(seed);
    int tmp = rand() % r_size;
    seed++;
    for(int i = 0; i < tmp; i++)
        deque->PopFront();
    if(deque->GetLength() != r_size - tmp)
        return ERROR;
    deque->Clear();
    srand(seed);
    r_size = rand() % 1000 + 1;
    a = RandomInt(seed);
    seed++;
    for(int i = 0; i < r_size; i++)
        deque->PushFront(a);
    if(deque->GetLength() != r_size)
        return ERROR;
    for(int i = 0; i < deque->GetLength(); i++)
        if(deque->Get(i) != a)
            return ERROR;
    srand(seed);
    tmp = rand() % r_size;
    seed++;
    for(int i = 0; i < tmp; i++)
        deque->PopBack();
    if(deque->GetLength() != r_size - tmp)
        return ERROR;
    delete deque;
    return NO_ERROR;
};

Check TestDequeInsertRemove()
{
    int seed = time(NULL);
    srand(seed);
    int r_size = rand() % 1000 + 1;
    seed++;
    DynamicArray<int>* array = IntArray(seed, r_size);
    Deque<int>* deque = new Deque<int>(array);
    Deque<int>* deque_copy = new Deque<int>(*deque);
    srand(seed);
    int at = rand() % r_size;
    int r_int = RandomInt(seed);
    deque->InsertAt(r_int, at);
    if(deque->GetLength() - 1 != deque_copy->GetLength())
        return ERROR;
    if(at > 0)
        if(deque->Get(at - 1) != deque_copy->Get(at - 1))
            return ERROR;
    if(deque->Get(at) != r_int)
        return ERROR;
    if(deque->Get(at + 1) != deque_copy->Get(at))
        return ERROR;
    deque->RemoveAt(at);
    if(deque->GetLength() != deque_copy->GetLength())
        return ERROR;
    for(int i = 0; i < deque->GetLength(); i++)
        if(deque->Get(i) != deque_copy->Get(i))
            return ERROR;
    delete deque;
    delete deque_copy;
    delete array;
    return NO_ERROR;
};

Check TestSubdeque()
{
    int seed = time(NULL);
    srand(seed);
    seed++;
    int r_size = rand() % 1000 + 4;
    Deque<int>* deque = new Deque<int>();
    int a = RandomInt(seed);
    for(int i = 0; i < r_size; i++)
        deque->PushBack(a);
    int from = rand() % (deque->GetLength() / 4);
    int to = rand() % (deque->GetLength() / 4) + deque->GetLength() / 2;
    Deque<int>* subdeque = deque->SubDeque(from, to);
    if(subdeque->GetLength() != to - from + 1)
        return ERROR;
    for(int i = 0; i < subdeque->GetLength(); i++)
        if(subdeque->Get(i) != deque->Get(i + from))
            return ERROR;
    delete deque;
    delete subdeque;
    return NO_ERROR;
};

Check TestDequeConcate()
{
    int seed = time(NULL);
    srand(seed);
    Deque<int>* deque1 = new Deque<int>();
    Deque<int>* deque2 = new Deque<int>();
    Deque<int>* deque3 = new Deque<int>();
    int r_size1 = 5;//rand() % 1000 + 1;
    int a = RandomInt(seed);
    seed++;
    srand(seed);
    int r_size2 = 6;//rand() % 1000 + 1;
    int b = RandomInt(seed);
    for(int i = 0; i < r_size1; i++)
        deque1->PushBack(a);
    for(int i = 0; i < r_size2; i++)
        deque2->PushBack(b);
    deque3 = new Deque<int>(*deque1);
    deque3->Concate(deque2);
    if(deque3->GetLength() != deque1->GetLength() + deque2->GetLength())
        return ERROR;
    for(int i = 0; i < deque1->GetLength(); i++)
        if(deque3->Get(i) != deque1->Get(i))
            return ERROR;
    for(int i = 0; i < deque2->GetLength(); i++)
        if(deque3->Get(i + deque1->GetLength()) != deque2->Get(i))
            return ERROR;
    delete deque1;
    delete deque2;
    delete deque3;
    return NO_ERROR;
};

Check TestDequeSort()
{
    int seed = time(NULL);
    srand(seed);
    seed++;
    int r_size = rand() % 1000 + 1;
    Deque<int>* deque = new Deque<int>();
    int a = RandomInt(seed);
    for(int i = 0; i < r_size; i++)
        deque->PushBack(a);
    deque = Sort(deque);
    if(deque->GetLength() != r_size)
        return ERROR;
    int tmp = deque->Last();
    for(int i = 1; i < deque->GetLength(); i++)
        if(deque->Get(i) < tmp)
            return ERROR;
    delete deque;
    return NO_ERROR;
};

Check TestDequeMap()
{
    int seed = time(NULL);
    srand(seed);
    seed++;
    int r_size = rand() % 1000 + 1;
    Deque<int>* deque = new Deque<int>();
    int a = RandomInt(seed);
    for(int i = 0; i < r_size; i++)
        deque->PushBack(a);
    Deque<int>* deque_copy = new Deque<int>(*deque);
    deque = Map(deque, [](int x){ return x % 100; });
    if(deque->GetLength() != deque_copy->GetLength())
        return ERROR;
    for(int i = 0; i < deque->GetLength(); i++)
        if(deque->Get(i) != deque_copy->Get(i) % 100)
            return ERROR;
    delete deque;
    delete deque_copy;
    return NO_ERROR;
};

Check TestDequeWhere()
{
    int seed = time(NULL);
    srand(seed);
    seed++;
    int r_size = rand() % 1000 + 1;
    Deque<int>* deque = new Deque<int>();
    int a = RandomInt(seed);
    for(int i = 0; i < r_size; i++)
        deque->PushBack(a);
    int count = 0;
    for(int i = 0; i < deque->GetLength(); i++)
        if(deque->Get(i) < 0)
            count++;
    deque = Where(deque, [](int x){ return x < 0; });
    if(deque->GetLength() != count)
        return ERROR;
    for(int i = 0; i < deque->GetLength(); i++)
        if(deque->Get(i) >= 0)
            return ERROR;
    delete deque;
    return NO_ERROR;
};

Check TestDequeReduce()
{
    int seed = time(NULL);
    srand(seed);
    seed++;
    int r_size = rand() % 1000 + 1;
    Deque<int>* deque = new Deque<int>();
    int a = RandomInt(seed);
    for(int i = 0; i < r_size; i++)
        deque->PushBack(a);
    int sum = r_size;
    for(int i = 0; i < deque->GetLength(); i++)
        sum += deque->Get(i);
    int b = Reduce(deque, [](int x1, int x2){ return x1 + x2; }, r_size);
    if(b != sum)
        return ERROR;
    delete deque;
    return NO_ERROR;
};
