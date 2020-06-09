#pragma once
#include "../../Structures/Sequences/LinkedListSequence.hpp"
#include "../../Utility/Randomization/RandomGen.hpp"
#include "../Basic/TestFunctions.hpp"
#include "../Basic/Check.h"
#include <time.h>

using namespace std;

Check TestSequenceCreate()
{
    srand(time(NULL));
    LinkedListSequence<int>* sequence;
    int size = rand() % 1000 + 1;
    sequence = new LinkedListSequence<int>();
    if(sequence->GetLength() != 0)
        return ERROR;
    int* data = (int*)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++)
        memcpy(data + i, &size, sizeof(int));
    sequence = new LinkedListSequence<int>(data, size);
    if(sequence->GetLength() != size)
        return ERROR;
    for(int i = 0; i < sequence->GetLength(); i++)
        if(sequence->Get(i) != size)
            return ERROR;
    LinkedListSequence<int>* sequence_copy = new LinkedListSequence<int>(*sequence);
    if(sequence_copy->GetLength() != size)
        return ERROR;
    for(int i = 0; i < sequence_copy->GetLength(); i++)
        if(sequence_copy->Get(i) != size)
            return ERROR;
    delete sequence;
    delete sequence_copy;
    return NO_ERROR;
};

Check TestSequenceSetGet()
{
    int seed = time(NULL);
    srand(seed);
    int size = rand() % 1000 + 1;
    seed++;
    LinkedListSequence<int>* sequence = new LinkedListSequence<int>();
    for(int i = 0; i < size; i++)
        sequence->Append(0);
    int tmp = RandomInt(seed);
    for(int i = 0; i < size; i++)
    {
        sequence->Set(i, tmp);
    };
    if(sequence->GetLength() != size)
        return ERROR;
    for(int i = 0; i < size; i++)
        if(sequence->Get(i) != tmp)
            return ERROR;
    delete sequence;
    return NO_ERROR;
};

Check TestSequencePushPop()
{
    int seed = time(NULL);
    srand(seed);
    LinkedListSequence<int>* sequence = new LinkedListSequence<int>();
    int r_size = rand() % 1000 + 1;
    int a = RandomInt(seed);
    seed++;
    for(int i = 0; i < r_size; i++)
        sequence->Prepend(a);
    if(sequence->GetLength() != r_size)
        return ERROR;
    for(int i = 0; i < sequence->GetLength(); i++)
        if(sequence->Get(i) != a)
            return ERROR;
    srand(seed);
    int tmp = rand() % r_size;
    seed++;
    for(int i = 0; i < tmp; i++)
        sequence->PopFront();
    if(sequence->GetLength() != r_size - tmp)
        return ERROR;
    sequence->Clear();
    srand(seed);
    r_size = rand() % 1000 + 1;
    a = RandomInt(seed);
    seed++;
    for(int i = 0; i < r_size; i++)
        sequence->Append(a);
    if(sequence->GetLength() != r_size)
        return ERROR;
    for(int i = 0; i < sequence->GetLength(); i++)
        if(sequence->Get(i) != a)
            return ERROR;
    srand(seed);
    tmp = rand() % r_size;
    seed++;
    for(int i = 0; i < tmp; i++)
        sequence->PopBack();
    if(sequence->GetLength() != r_size - tmp)
        return ERROR;
    delete sequence;
    return NO_ERROR;
};

Check TestSequenceInsertRemove()
{
    int seed = time(NULL);
    srand(seed);
    int r_size = 5;//rand() % 5 + 1;//% 1000 + 1;
    seed++;
    DynamicArray<int>* array = IntArray(seed, r_size);
    LinkedListSequence<int>* sequence = new LinkedListSequence<int>(array);
    LinkedListSequence<int>* sequence_copy = new LinkedListSequence<int>(*sequence);
    srand(seed);
    int at = rand() % r_size;
    int r_int = RandomInt(seed);
    seed++;
    sequence->InsertAt(r_int, at);
    if(sequence->GetLength() - 1 != sequence_copy->GetLength())
        return ERROR;
    if(at > 0)
        if(sequence->Get(at - 1) != sequence_copy->Get(at - 1))
            return ERROR;
    if(sequence->Get(at) != r_int)
        return ERROR;
    if(sequence->Get(at + 1) != sequence_copy->Get(at))
        return ERROR;
    sequence->RemoveAt(at);
    if(sequence->GetLength() != sequence_copy->GetLength())
        return ERROR;
    for(int i = 0; i < sequence->GetLength(); i++)
        if(sequence->Get(i) != sequence_copy->Get(i))
            return ERROR;
    delete sequence;
    delete sequence_copy;
    return NO_ERROR;
};

Check TestSubsequence()
{
    int seed = time(NULL);
    srand(seed);
    seed++;
    int r_size = rand() % 1000 + 1;
    LinkedListSequence<int>* sequence = new LinkedListSequence<int>();
    int a = RandomInt(seed);
    for(int i = 0; i < r_size; i++)
        sequence->Append(a);
    int from = rand() % (sequence->GetLength() / 4);
    int to = rand() % (sequence->GetLength() / 4) + sequence->GetLength() / 2;
    LinkedListSequence<int>* subsequence = sequence->GetSubsequence(from, to);
    if(subsequence->GetLength() != to - from + 1)
        return ERROR;
    for(int i = 0; i < subsequence->GetLength(); i++)
        if(subsequence->Get(i) != a)
            return ERROR;
    delete sequence;
    delete subsequence;
    return NO_ERROR;
};

Check TestSequenceConcate()
{
    int seed = time(NULL);
    srand(seed);
    LinkedListSequence<int>* sequence1 = new LinkedListSequence<int>();
    LinkedListSequence<int>* sequence2 = new LinkedListSequence<int>();
    LinkedListSequence<int>* sequence3 = new LinkedListSequence<int>();
    int r_size1 = 5;//rand() % 1000 + 1;
    int a = RandomInt(seed);
    seed++;
    srand(seed);
    int r_size2 = 6;//rand() % 1000 + 1;
    int b = RandomInt(seed);
    for(int i = 0; i < r_size1; i++)
        sequence1->Append(a);
    for(int i = 0; i < r_size2; i++)
        sequence2->Append(b);
    sequence3 = new LinkedListSequence<int>(*sequence1);
    sequence3->Concate(sequence2);
    if(sequence3->GetLength() != sequence1->GetLength() + sequence2->GetLength())
        return ERROR;
    for(int i = 0; i < sequence1->GetLength(); i++)
        if(sequence3->Get(i) != sequence1->Get(i))
            return ERROR;
    for(int i = 0; i < sequence2->GetLength(); i++)
        if(sequence3->Get(i + sequence1->GetLength()) != sequence2->Get(i))
            return ERROR;
    delete sequence1;
    delete sequence2;
    delete sequence3;
    return NO_ERROR;
};
