#pragma once
#include "DataTypes.hpp"
#include "Deque.hpp"
#include "RandomGen.hpp"
#include <time.h>

using namespace std;

int RandomSeed(int seed)
{
    seed += RandomInt(seed);
    seed -= RandomInt(seed);
    return seed;
};

//FOR INTS
void ExampleIntList(DynamicArray<int>* arr)
{
    cout << endl << "List from this ints:" << endl;
    LinkedList< int>* list = new LinkedList<int>();
    for(int i = 0; i < arr->GetSize(); i++)
        list->PushBack(arr->Get(i));
    for(int i = 0; i < list->GetLength(); i++)
        cout << list->Get(i) << ' ';
    cout << endl << "List-copy:" << endl;
    LinkedList<int>* list_copy = new LinkedList<int>(*list);
    for(int i = 0; i < list_copy->GetLength(); i++)
        cout << list_copy->Get(i) << ' ';
    cout << endl << "Sublist from 2 to 6:" << endl;
    list_copy = list_copy->GetSublist(2, 6);
    for(int i = 0; i < list_copy->GetLength(); i++)
        cout << list_copy->Get(i) << ' ';
    cout << endl << "Concated lists" << endl;
    list = list->Concate(*list, *list_copy);
    for(int i = 0; i < list->GetLength(); i++)
        cout << list->Get(i) << ' ';
    cout << endl << "Copy from array" << endl;
    LinkedList<int>* copy_array = new LinkedList<int>(arr->DataPointer(), arr->GetSize());
    for(int i = 0; i < copy_array->GetLength(); i++)
        cout << copy_array->Get(i) << ' ';
};

void ExampleIntArray(DynamicArray<int>* arr)
{
    cout << endl << "Array from this ints:" << endl;
    DynamicArray<int>* array = new DynamicArray<int>(arr->DataPointer(), arr->GetSize());
    for(int i = 0; i < array->GetSize(); i++)
        cout << array->Get(i) << ' ';
    cout << endl << "Array-copy" << endl;
    DynamicArray<int>* array_copy = new DynamicArray<int>(*array);
    for(int i = 0; i < array_copy->GetSize(); i++)
        cout << array_copy->Get(i) << ' ';
    cout << endl << "Subarray from 2 to 5:" << endl;
    DynamicArray<int>* subarray = array_copy->GetSubArray(2, 5);
    for(int i = 0; i < subarray->GetSize(); i++)
        cout << subarray->Get(i) << ' ';
    cout << endl << "Concated arrays:" << endl;
    array_copy->ConcateTo(*subarray);
    for(int i = 0; i < array_copy->GetSize(); i++)
        cout << array_copy->Get(i) << ' ';
};

void ExampleIntSequence(DynamicArray<int>* arr)
{
    cout << endl << "List sequence from this ints:" << endl;
    LinkedListSequence<int>* list_sequence = new LinkedListSequence<int>(arr->DataPointer(), arr->GetSize());
    for(int i = 0; i < list_sequence->GetLength(); i++)
        cout << list_sequence->Get(i) << ' ';
    cout << endl << "List sequence - copy:" << endl;
    LinkedListSequence<int>* list_sequence_copy = new LinkedListSequence<int>(*list_sequence);
    for(int i = 0; i < list_sequence_copy->GetLength(); i++)
        cout << list_sequence_copy->Get(i) << ' ';
    cout << endl << "List sequence - subsequence from 2 to 6:" << endl;
    list_sequence_copy = list_sequence_copy->GetSubsequence(2, 6);
    for(int i = 0; i < list_sequence_copy->GetLength(); i++)
        cout << list_sequence_copy->Get(i) << ' ';
    list_sequence->Concate(list_sequence_copy);
    cout << endl << "Concated sequences" << endl;
    for(int i = 0; i < list_sequence->GetLength(); i++)
        cout << list_sequence->Get(i) << ' ';
    Function<int, int>* f = new Function<int, int>("reducer", 1);

};

void ExampleIntDeque(DynamicArray<int>* arr)
{
    cout << endl << endl << "Deque from this ints:" << endl;
    Deque<int>* deque = new Deque<int>();
    for(int i = 0; i < arr->GetSize(); i++)
        deque->PushFront(arr->Get(i));
    for(int i = 0; i < deque->GetSize(); i++)
        cout << deque->Get(i) << ' ';
    cout << endl << "Deque-copy:" << endl;
    Deque<int>* deque_copy = new Deque<int>(*deque);
    for(int i = 0; i < deque_copy->GetSize(); i++)
        cout << deque_copy->Get(i) << ' ';
};

void ExampleInt(int seed)
{
    cout << "Some ints:" << endl;
    DynamicArray<int>* arr = IntArray(seed, 8);
    seed = RandomSeed(seed);
    for(int i = 0; i < arr->GetSize(); i++)
        cout << arr->Get(i) << ' ';
    //getchar();
    //ExampleIntList(arr);
    //getchar();
    //ExampleIntArray(arr);
    //getchar();
    ExampleIntSequence(arr);
    //getchar();
    //ExampleIntDeque(arr);
    //getchar();
    delete arr;
};

//MAIN EXAMPLE
void Example()
{
    int seed = time(NULL);
    ExampleInt(seed);
};
