#pragma once
#include "DataTypes.h"
#include "Deque.h"
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
    cout << endl << endl << "List from this complex values:" << endl;
    LinkedList< int>* list = new LinkedList<int>();
    for(int i = 0; i < arr->GetSize(); i++)
        list->PushBack(arr->GetPointer(i));
    for(int i = 0; i < list->GetLength(); i++)
        cout << list->Get(i) << ' ';
    cout << endl << "List-copy:" << endl;
    LinkedList<int>* list_copy = new LinkedList<int>(*list);
    for(int i = 0; i < list_copy->GetLength(); i++)
        cout << list_copy->Get(i) << ' ';
    cout << endl << "Sublist from 2 to 3:" << endl;
    list_copy = list_copy->GetSubList(2, 3);
    for(int i = 0; i < list_copy->GetLength(); i++)
        cout << list_copy->Get(i) << ' ';
    delete list_copy;
    delete list;
};

void ExampleIntArray(DynamicArray<int>* arr)
{
    cout << endl << endl << "Array from this complex values:" << endl;
    DynamicArray<int>* array = new DynamicArray<int>();
    for(int i = 0; i < arr->GetSize(); i++)
        array->PushBack(arr->GetPointer(i));
    for(int i = 0; i < array->GetSize(); i++)
        cout << array->Get(i) << ' ';
    cout << endl << "Array-copy" << endl;
    DynamicArray<int>* array_copy = new DynamicArray<int>(*array);
    for(int i = 0; i < array_copy->GetSize(); i++)
        cout << array_copy->Get(i) << ' ';
    cout << endl << "Subarray from 2 to 3:" << endl;
    array_copy = array_copy->GetSubArray(2, 3);
    for(int i = 0; i < array_copy->GetSize(); i++)
        cout << array_copy->Get(i) << ' ';
    delete array;
    delete array_copy;
};

void ExampleIntSequence(DynamicArray<int>* arr)
{
    cout << endl << endl << "List sequence from this complex values:" << endl;
    LinkedListSequence<int>* list_sequence = new LinkedListSequence<int>();
    for(int i = 0; i < arr->GetSize(); i++)
        list_sequence->Prepend(arr->GetPointer(i));
    for(int i = 0; i < list_sequence->GetLength(); i++)
        cout << list_sequence->Get(i) << ' ';
    cout << endl << "List sequence - copy:" << endl;
    LinkedListSequence<int>* list_sequence_copy = new LinkedListSequence<int>(*list_sequence);
    for(int i = 0; i < list_sequence_copy->GetLength(); i++)
        cout << list_sequence_copy->Get(i) << ' ';
    cout << endl << "List sequence - subsequence from 2 to 3:" << endl;
    list_sequence_copy = list_sequence_copy->GetSubsequence(2, 3);
    for(int i = 0; i < list_sequence_copy->GetLength(); i++)
        cout << list_sequence_copy->Get(i) << ' ';
    delete list_sequence;
    delete list_sequence_copy;
};

void ExampleIntDeque(DynamicArray<int>* arr)
{
    cout << endl << endl << "Deque from this complex values:" << endl;
    Deque<int>* deque = new Deque<int>();
    for(int i = 0; i < arr->GetSize(); i++)
        deque->PushFront(arr->GetPointer(i));
    for(int i = 0; i < deque->GetSize(); i++)
        cout << deque->Get(i) << ' ';
    cout << endl << "Deque-copy:" << endl;
    Deque<int>* deque_copy = new Deque<int>(*deque);
    for(int i = 0; i < deque_copy->GetSize(); i++)
        cout << deque_copy->Get(i) << ' ';
};

void ExampleInt(int seed)
{
    cout << "Some complex values:" << endl;
    DynamicArray<int>* arr = IntArray(seed, 4);
    seed = RandomSeed(seed);
    for(int i = 0; i < arr->GetSize(); i++)
        cout << arr->Get(i) << ' ';
    getchar();
    ExampleIntList(arr);
    getchar();
    ExampleIntArray(arr);
    getchar();
    ExampleIntSequence(arr);
    getchar();
    ExampleIntDeque(arr);
    getchar();
    delete arr;
};


//FOR INT COMPLEX
void ExampleComplexList(DynamicArray< Complex<int, int> >* arr)
{
    cout << endl << endl << "List from this complex values:" << endl;
    LinkedList< Complex<int, int> >* list = new LinkedList< Complex<int, int> >();
    for(int i = 0; i < arr->GetSize(); i++)
        list->PushBack(arr->GetPointer(i));
    for(int i = 0; i < list->GetLength(); i++)
        list->Get(i).PrintComplex();
    cout << endl << "List-copy:" << endl;
    LinkedList< Complex<int, int> >* list_copy = new LinkedList< Complex<int, int> >(*list);
    for(int i = 0; i < list_copy->GetLength(); i++)
        list_copy->Get(i).PrintComplex();
    cout << endl << "Sublist from 2 to 3:" << endl;
    list_copy = list_copy->GetSubList(2, 3);
    for(int i = 0; i < list_copy->GetLength(); i++)
        list_copy->Get(i).PrintComplex();
    delete list_copy;
    delete list;
};

void ExampleComplexArray(DynamicArray< Complex<int, int> >* arr)
{
    cout << endl << endl << "Array from this complex values:" << endl;
    DynamicArray< Complex<int, int> >* array = new DynamicArray< Complex<int, int> >();
    for(int i = 0; i < arr->GetSize(); i++)
        array->PushBack(arr->GetPointer(i));
    for(int i = 0; i < array->GetSize(); i++)
        array->Get(i).PrintComplex();
    cout << endl << "Array-copy" << endl;
    DynamicArray< Complex<int, int> >* array_copy = new DynamicArray< Complex<int, int> >(*array);
    for(int i = 0; i < array_copy->GetSize(); i++)
        array_copy->Get(i).PrintComplex();
    cout << endl << "Subarray from 2 to 3:" << endl;
    array_copy = array_copy->GetSubArray(2, 3);
    for(int i = 0; i < array_copy->GetSize(); i++)
        array_copy->Get(i).PrintComplex();
    delete array;
    delete array_copy;
};

void ExampleComplexSequence(DynamicArray< Complex<int, int> >* arr)
{
    cout << endl << endl << "List sequence from this complex values:" << endl;
    LinkedListSequence< Complex<int, int> >* list_sequence = new LinkedListSequence< Complex<int, int> >();
    for(int i = 0; i < arr->GetSize(); i++)
        list_sequence->Prepend(arr->GetPointer(i));
    for(int i = 0; i < list_sequence->GetLength(); i++)
        list_sequence->Get(i).PrintComplex();
    cout << endl << "List sequence - copy:" << endl;
    LinkedListSequence< Complex<int, int> >* list_sequence_copy = new LinkedListSequence< Complex<int, int> >(*list_sequence);
    for(int i = 0; i < list_sequence_copy->GetLength(); i++)
        list_sequence_copy->Get(i).PrintComplex();
    cout << endl << "List sequence - subsequence from 2 to 3:" << endl;
    list_sequence_copy = list_sequence_copy->GetSubsequence(2, 3);
    for(int i = 0; i < list_sequence_copy->GetLength(); i++)
        list_sequence_copy->Get(i).PrintComplex();;
    delete list_sequence;
    delete list_sequence_copy;
};

void ExampleComplexDeque(DynamicArray< Complex<int, int> >* arr)
{
    cout << endl << endl << "Deque from this complex values:" << endl;
    Deque< Complex<int, int> >* deque = new Deque< Complex<int, int> >();
    for(int i = 0; i < arr->GetSize(); i++)
        deque->PushFront(arr->GetPointer(i));
    for(int i = 0; i < deque->GetSize(); i++)
        deque->Get(i).PrintComplex();
    cout << endl << "Deque-copy:" << endl;
    Deque< Complex<int, int> >* deque_copy = new Deque< Complex<int, int> >(*deque);
    for(int i = 0; i < deque->GetSize(); i++)
        deque->Get(i).PrintComplex();
};

void ExampleComplex(int seed)
{
    cout << "Some complex values:" << endl;
    DynamicArray< Complex<int, int> >* arr = IntComplexArray(seed, 4);
    seed = RandomSeed(seed);
    for(int i = 0; i < arr->GetSize(); i++)
        arr->Get(i).PrintComplex();
    getchar();
    ExampleComplexList(arr);
    getchar();
    ExampleComplexArray(arr);
    getchar();
    ExampleComplexSequence(arr);
    getchar();
    ExampleComplexDeque(arr);
    getchar();
    delete arr;
};


//FOR STRINGS
void ExampleStringList(DynamicArray<string>* arr)
{
    cout << endl << endl << "List from this complex values:" << endl;
    LinkedList<string>* list = new LinkedList<string>();
    for(int i = 0; i < arr->GetSize(); i++)
        list->PushBack(arr->GetPointer(i));
    for(int i = 0; i < list->GetLength(); i++)
        cout << list->Get(i) << ' ';
    cout << endl << "List-copy:" << endl;
    LinkedList<string>* list_copy = new LinkedList<string>(*list);
    for(int i = 0; i < list_copy->GetLength(); i++)
        cout << list_copy->Get(i) << ' ';
    cout << endl << "Sublist from 2 to 3:" << endl;
    list_copy = list_copy->GetSubList(2, 3);
    for(int i = 0; i < list_copy->GetLength(); i++)
        cout << list_copy->Get(i) << ' ';
    delete list_copy;
    delete list;
};

void ExampleStringArray(DynamicArray<string>* arr)
{
    {
        cout << endl << endl << "Array from this complex values:" << endl;
        DynamicArray<string>* array = new DynamicArray<string>();
        for(int i = 0; i < arr->GetSize(); i++)
            array->PushBack(arr->GetPointer(i));
        for(int i = 0; i < array->GetSize(); i++)
            cout << array->Get(i) << ' ';
        cout << endl << "Array-copy" << endl;
        DynamicArray<string>* array_copy = new DynamicArray<string>(*array);
        for(int i = 0; i < array_copy->GetSize(); i++)
            cout << array_copy->Get(i) << ' ';
        cout << endl << "Subarray from 2 to 3:" << endl;
        array_copy = array_copy->GetSubArray(2, 3);
        for(int i = 0; i < array_copy->GetSize(); i++)
            cout << array_copy->Get(i) << ' ';
        delete array;
        delete array_copy;
    };
};

void ExampleStringSequence(DynamicArray<string>* arr)
{
    cout << endl << endl << "List sequence from this complex values:" << endl;
    LinkedListSequence<string>* list_sequence = new LinkedListSequence<string>();
    for(int i = 0; i < arr->GetSize(); i++)
        list_sequence->Prepend(arr->GetPointer(i));
    for(int i = 0; i < list_sequence->GetLength(); i++)
        cout << list_sequence->Get(i) << ' ';
    cout << endl << "List sequence - copy:" << endl;
    LinkedListSequence<string>* list_sequence_copy = new LinkedListSequence<string>(*list_sequence);
    for(int i = 0; i < list_sequence_copy->GetLength(); i++)
        cout << list_sequence_copy->Get(i) << ' ';
    cout << endl << "List sequence - subsequence from 2 to 3:" << endl;
    list_sequence_copy = list_sequence_copy->GetSubsequence(2, 3);
    for(int i = 0; i < list_sequence_copy->GetLength(); i++)
        cout << list_sequence_copy->Get(i) << ' ';
    delete list_sequence;
    delete list_sequence_copy;
};

void ExampleStringDeque(DynamicArray<string>* arr)
{
    cout << endl << endl << "Deque from this complex values:" << endl;
    Deque<string>* deque = new Deque<string>();
    for(int i = 0; i < arr->GetSize(); i++)
        deque->PushFront(arr->GetPointer(i));
    for(int i = 0; i < deque->GetSize(); i++)
        cout << deque->Get(i) << ' ';
    cout << endl << "Deque-copy:" << endl;
    Deque<string>* deque_copy = new Deque<string>(*deque);
    for(int i = 0; i < deque_copy->GetSize(); i++)
        cout << deque_copy->Get(i) << ' ';
};

void ExampleString(int seed)
{
    cout << "Some strings:" << endl;
    DynamicArray<string>* arr = StringArray(seed, 4, 4);
    seed = RandomSeed(seed);
    for(int i = 0; i < arr->GetSize(); i++)
        cout << arr->Get(i) << ' ';
    getchar();
    ExampleStringList(arr);
    getchar();
    ExampleStringArray(arr);
    getchar();
    ExampleStringSequence(arr);
    getchar();
    ExampleStringDeque(arr);
    getchar();
    delete arr;
};


//MAIN EXAMPLE
void Example()
{
    int seed = time(NULL);
    ExampleComplex(seed);
    //ExampleInt(seed);
    //ExampleString(seed);
};
