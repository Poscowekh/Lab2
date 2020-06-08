#pragma once
#include "Deque.hpp"
#include "RandomGen.hpp"
#include "Function.hpp"
#include <time.h>

using namespace std;

int overall_errors = 0;

typedef enum
{
    ERROR,
    NO_ERROR
} Check;

class Test
{
    private:
        void Realloc(int new_size)
        {
            TestFunction<Check>* tmp = (TestFunction<Check>*)malloc(new_size * el_size);
            memcpy(tmp, functions, count * el_size);
            free(functions);
            functions = tmp;
        };
        int el_size;
        int errors;
        string name;
        TestFunction<Check>* functions;
        int count;
    public:
        Test(string test_name)
        {
            name = test_name;
            count = 0;
            functions = 0;
            errors = 0;
            el_size = sizeof(TestFunction<Check>);
        };
        void AddTest(string func_name, Check(*const func)())
        {
            TestFunction<Check>* new_func = new TestFunction<Check>(func_name, func);
            Realloc(count + 1);
            memcpy(functions + count, new_func, el_size);
            count++;
        };
        void RunTests()
        {
            Check check;
            TestFunction<Check>* tmp;
            cout << "Testing " << name << "..." << endl;
            for(int i = 0; i < count; i++)
            {
                tmp = functions + i;
                check = tmp->function();
                cout << "   " << "test " << i + 1 << ": " << tmp->function_name << " - ";
                if(check == ERROR)
                {
                    errors++;
                    overall_errors++;
                    cout << "error" << endl;
                }
                else
                    cout << "no errors" << endl;
            };
            cout << "Errors found: " << errors << endl << "Test Finished." << endl;
        };
};

//Array
Check TestArrayCreate()
{
    srand(time(NULL));
    DynamicArray<int>* array;
    int size = rand() % 1000 + 1;
    array = new DynamicArray<int>();
    if(array->GetLength() != 0)
        return ERROR;
    array = new DynamicArray<int>(size);
    if(array->GetLength() != size)
        return ERROR;
    int* data = (int*)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++)
        memcpy(data + i, &size, sizeof(int));
    array = new DynamicArray<int>(data, size);
    if(array->GetLength() != size)
        return ERROR;
    for(int i = 0; i < array->GetLength(); i++)
        if(array->Get(i) != size)
            return ERROR;
    DynamicArray<int>* array_copy = new DynamicArray<int>(*array);
    if(array_copy->GetLength() != size)
        return ERROR;
    for(int i = 0; i < array_copy->GetLength(); i++)
        if(array_copy->Get(i) != size)
            return ERROR;
    delete array;
    delete array_copy;
    return NO_ERROR;
};

Check TestArraySetGet()
{
    int seed = time(NULL);
    int size = RandomInt(seed);
    seed++;
    DynamicArray<int>* array = new DynamicArray<int>(size);
    int tmp = RandomInt(seed);
    seed++;
    for(int i = 0; i < size; i++)
    {
        array->Set(i, tmp);
    };
    for(int i = 0; i < size; i++)
        if(array->Get(i) != tmp)
            return ERROR;
    delete array;
    return NO_ERROR;
};

Check TestArrayPushPop()
{
    int seed = time(NULL);
    DynamicArray<int>* array = new DynamicArray<int>();
    int r_size = RandomInt(seed);
    seed++;
    int a = RandomInt(seed);
    seed++;
    for(int i = 0; i < r_size; i++)
        array->PushFront(a);
    if(array->GetLength() != r_size)
        return ERROR;
    for(int i = 0; i < array->GetLength(); i++)
        if(array->Get(i) != a)
            return ERROR;
    int tmp = RandomInt(seed) % r_size;
    seed++;
    for(int i = 0; i < tmp; i++)
        array->PopFront();
    if(array->GetLength() != r_size - tmp)
        return ERROR;
    array->Clear();
    r_size = RandomInt(seed);
    seed++;
    a = RandomInt(seed);
    seed++;
    for(int i = 0; i < r_size; i++)
        array->PushBack(a);
    if(array->GetLength() != r_size)
        return ERROR;
    for(int i = 0; i < array->GetLength(); i++)
        if(array->Get(i) != a)
            return ERROR;
    tmp = RandomInt(seed) % r_size;
    seed++;
    for(int i = 0; i < tmp; i++)
        array->PopBack();
    if(array->GetLength() != r_size - tmp)
        return ERROR;
    delete array;
    return NO_ERROR;
};

Check TestArrayInsertRemove()
{
    int seed = time(NULL);
    DynamicArray<int>* array1 = new DynamicArray<int>();
    int r_size = RandomInt(seed);
    seed++;
    for(int i = 0; i < r_size; i++)
    {
        int a = RandomInt(seed);
        seed++;
        array1->PushBack(a);
    };
    DynamicArray<int>* array2 = new DynamicArray<int>(*array1);
    int a = RandomInt(seed) % (array2->GetLength() - 2) + 1;
    seed++;
    int b = RandomInt(seed);
    seed++;
    array2->InsertAt(b, a);
    if(array2->GetLength() != array1->GetLength() + 1)
        return ERROR;
    if(array2->Get(a - 1) != array1->Get(a - 1))
        return ERROR;
    if(array2->Get(a) != b)
        return ERROR;
    if(array2->Get(a + 1) != array1->Get(a))
        return ERROR;
    array2->RemoveAt(a);
    if(array2->GetLength() != array1->GetLength())
        return ERROR;
    if(array2 != array1)
        return ERROR;
    delete array1;
    delete array2;
    return NO_ERROR;
};

Check TestArraySubArray()
{
    int seed = time(NULL);
    DynamicArray<int>* array1 = new DynamicArray<int>();
    int r_size = RandomInt(seed);
    seed++;
    int a = RandomInt(seed);
    seed++;
    for(int i = 0; i < r_size; i++)
        array1->PushBack(a);
    int b = RandomInt(seed) % (array1->GetLength() / 2);
    int c = RandomInt(seed) % (array1->GetLength() / 2) + array1->GetLength() / 2;
    DynamicArray<int>* array2 = array1->GetSubArray(b, c);
    if(array2->GetLength() != c - b + 1)
        return ERROR;
    for(int i = 0; i < array2->GetLength(); i++)
        if(array2->Get(i) != a)
            return ERROR;
    delete array1;
    delete array2;
    return NO_ERROR;
};

Check TestArrayConcate()
{
    int seed = time(NULL);
    DynamicArray<int>* array1 = new DynamicArray<int>();
    DynamicArray<int>* array2 = new DynamicArray<int>();
    DynamicArray<int>* array3 = new DynamicArray<int>();
    int r_size1 = RandomInt(seed);
    seed++;
    int a = RandomInt(seed);
    seed++;
    for(int i = 0; i < r_size1; i++)
        array1->PushBack(a);
    int r_size2 = RandomInt(seed);
    seed++;
    int b = RandomInt(seed);
    seed++;
    for(int i = 0; i < r_size2; i++)
        array2->PushBack(b);
    array3->ConcateTo(*array2);
    array3->ConcateTo(*array1);
    if(array3->GetLength() != array1->GetLength() + array2->GetLength())
        return ERROR;
    for(int i = 0; i < array2->GetLength(); i++)
        if(array3->Get(i) != array2->Get(i))
            return ERROR;
    for(int i = array2->GetLength() - 1; i < array1->GetLength() + array2->GetLength(); i++)
        if(array3->Get(i) != array1->Get(i))
            return ERROR;
    delete array1;
    delete array2;
    delete array3;
    return NO_ERROR;
};

void TestArray()
{
    Test* array_test = new Test("array");
    //array_test->AddTest("Create Array", TestArrayCreate);
    //array_test->AddTest("Set/Get Array", TestArraySetGet);
    array_test->AddTest("Push/Pop Array", TestArrayPushPop);
    /*array_test->AddTest("InsertAt/RemoveAt Array", TestArrayInsertRemove);
    array_test->AddTest("SubArray", TestArraySubArray);
    array_test->AddTest("Concate Arrays", TestArrayConcate);*/
    array_test->RunTests();
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
for(int i = 0; i < array.GetLength(); i++)
    array[i].PrintComplex();
cout << endl;
DynamicArray< Complex<int, int> > array_copy = DynamicArray< Complex<int, int> >(array);
array_copy.RemoveAt(array_copy.GetLength() - 1);
array_copy.PopFront();
array_copy.PopBack();
array_copy.InsertAt(&complex4, 0);
array_copy.InsertAt(&complex1, 0);
array_copy.InsertAt(&complex5, 2);
array_copy.InsertAt(&complex3, array_copy.GetLength() - 1);
for(int i = 0; i < array_copy.GetLength(); i++)
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
for(int i = 0; i < arr->GetLength(); i++)
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
for(int i = 0; i < arr->GetLength(); i++)
    cout << arr->Get(i).ComplexToString() << endl;
cout << endl << "Deque:" << endl;
for(int i = 0; i < arr->GetLength(); i++)
    deque.PushFront(arr->GetPointer(i));
for(int i = 0; i < deque.GetLength(); i++)
    deque[i].PrintComplex();
seed++;
*/

void test_main()
{
    cout << endl;
    TestArray();
    getchar();
};
