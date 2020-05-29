#pragma once
#include "Deque.h"
#include "RandomGen.hpp"
#include <time.h>

using namespace std;

typedef enum
{
    ERROR,
    NO_ERROR
} Check;

//Array
/*Check TestArrayCreate(int seed)
{
    DynamicArray<int>* array = new DynamicArray<int>();
    int a = RandomInt(seed);
    seed++;
    for(int i = 0; i < a; i++)
        array->PushFront(a);
    if(array->GetSize() != a)
        return ERROR;
    for(int i = 0; i < array->GetSize(); i++)
       if(array->Get(i) != a)
           return ERROR;
    delete array;
    return NO_ERROR;
};

/*
int seed = time(NULL);

//COMPLEX

Complex<int, int> complex1(1,2);
Complex<int, int> complex2(2,4);
Complex<int, int> complex3(3,8);
Complex<int, int> complex4(4,16);
Complex<int, int> complex5 = ++complex2.GetConjugate();
/*
complex1 *= complex1;
cout << "First complex:  ";
complex1.PrintComplex();
complex2 *= complex3;
cout << "Second complex: ";
complex2.PrintComplex();
complex3.Conjugate();
cout << "Third complex:  ";
complex3.PrintComplex();
++complex4;
cout << "Fourth complex: ";
complex4.PrintComplex();
*/

//LINKEDLIST
/*
LinkedList< Complex<int, int> >* list = new LinkedList< Complex<int, int> >();
list->PushFront(&complex4);
list->PushFront(&complex1);
list->PushBack(&complex3);
list->PushBack(&complex2);
cout << "List:" << endl;
for(int i = 0; i < list->GetLength(); i++)
    list->Get(i).PrintComplex();
cout << endl;
LinkedList< Complex<int, int> >* list_copy = new LinkedList< Complex<int, int> >(*list);
list_copy->InsertAt(&complex5, 2);
cout << "List copy:" << endl;
for(int i = 0; i < list_copy->GetLength(); i++)
    list_copy->Get(i).PrintComplex();
cout << endl;
list_copy->Sort();
cout << "Sorted list if possible:" << endl;
for(int i = 0; i < list_copy->GetLength(); i++)
    list_copy->Get(i).PrintComplex();
cout << endl;
list_copy = list_copy->GetSubList(1, 3);
cout << "Sublist from 1 to 3 from list copy:" << endl;
for(int i = 0; i < list_copy->GetLength(); i++)
    list_copy->Get(i).PrintComplex();
cout << endl;
list_copy->Clear();
cout << "Cleared list:" << endl;
for(int i = 0; i < list_copy->GetLength(); i++)
    list_copy->Get(i).PrintComplex();
cout << endl;
delete list_copy;
delete list;
*/

//ARRAY
/*
DynamicArray< Complex<int, int> > array = DynamicArray< Complex<int, int> >();
array.PushFront(complex2);
array.PushFront(complex1);
array.PushBack(complex3);
array.PushBack(complex4);
for(int i = 0; i < array.GetSize(); i++)
    array[i].PrintComplex();
cout << endl;
DynamicArray< Complex<int, int> > array_copy = DynamicArray< Complex<int, int> >(array);
array_copy.RemoveAt(array_copy.GetSize() - 1);
array_copy.PopFront();
array_copy.PopBack();
array_copy.InsertAt(&complex4, 0);
array_copy.InsertAt(&complex1, 0);
array_copy.InsertAt(&complex5, 2);
array_copy.InsertAt(&complex3, array_copy.GetSize() - 1);
for(int i = 0; i < array_copy.GetSize(); i++)
    array_copy[i].PrintComplex();
cout << endl;
*/

//SEQUENCE
/*
DynamicArray< Complex<float, float> >* arr = FloatComplexArray(seed, 5);
LinkedListSequence< Complex<float, float> > list_sequence = LinkedListSequence< Complex<float, float> >();
LinkedListSequence< Complex<float, float> >* list_subsequence;
seed += RandomInt(seed);
seed -= RandomInt(seed);
cout << "List sequence:" << endl;
for(int i = 0; i < arr->GetSize(); i++)
    list_sequence.Prepend(arr->GetPointer(i));
for(int i = 0; i < list_sequence.GetLength(); i++)
    cout << list_sequence.Get(i).StringComplex() << endl;
list_subsequence = list_sequence.GetSubsequence(1,3);
cout << endl << "List subsequence" << endl;
for(int i = 0; i < list_subsequence->GetLength(); i++)
    (*list_subsequence)[i].PrintComplex();
cout << endl;
delete arr;
*/

//DEQUE
/*
Deque< Complex<int, int> > deque = Deque< Complex<int, int> >();
if(deque.Empty())
    cout << "EMPTY" << endl;
DynamicArray< Complex<int, int> >* arr = IntComplexArray(seed, rand() % 4 + 2);
cout << "Some array:" << endl;
for(int i = 0; i < arr->GetSize(); i++)
    cout << arr->Get(i).ComplexToString() << endl;
cout << endl << "Deque:" << endl;
for(int i = 0; i < arr->GetSize(); i++)
    deque.PushFront(arr->GetPointer(i));
for(int i = 0; i < deque.GetSize(); i++)
    deque[i].PrintComplex();
seed++;
*/

void test_main()
{
    int seed = time(NULL);
    //TestArrayCreate(seed);
};
