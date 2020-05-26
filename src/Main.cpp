#include "LinkedList.h"
#include "DataTypes.h"
#include "DynamicArray.h"
//#include "DynamicSequence"

/* TODOLIST:
 * 1)exceptions for List;
 * 2)tests for List;
 * 3)sort, concate, subsequence, map, where, reduce for deck
 */

using namespace std;
int main()
{
    //COMPLEX

    Complex<int, int> complex1(1,2);
    Complex<int, int> complex2(2,4);
    Complex<int, int> complex3(3,8);
    Complex<int, int> complex4(4,16);
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
    list->PushFront(&complex2);
    list->PushFront(&complex1);
    list->PushBack(&complex3);
    list->PushBack(&complex4);
    cout << "First element:" << endl << "   ";
    cout << list->Front().StringComplex() << ' ' << list->FrontPointer()->StringComplex() << ' '
         << list->Get(0).StringComplex() << ' ' << list->GetPointer(0)->StringComplex() << endl;
    cout << "Sesond element:" << endl << "   ";
    cout << list->Get(1).StringComplex() << ' ' << list->GetPointer(1)->StringComplex() << endl;
    cout << "Third element:" << endl << "   ";
    cout << list->Get(2).StringComplex() << ' ' << list->GetPointer(2)->StringComplex() << endl;
    cout << "Fourth element:" << endl << "   ";
    cout << list->Back().StringComplex() << ' ' << list->BackPointer()->StringComplex() << ' '
         << list->Get(3).StringComplex() << ' ' << list->GetPointer(3)->StringComplex() << endl;
    cout << endl;
    LinkedList< Complex<int, int> >* list_copy = new LinkedList< Complex<int, int> >(*list);
    for(int i = 0; i < list_copy->GetLength(); i++)
        (*list_copy)[i].PrintComplex();
    cout << endl;
    list_copy = list_copy->GetSubList(1,2);
    for(int i = 0; i < list_copy->GetLength(); i++)
        (*list_copy)[i].PrintComplex();
    delete list_copy;
    delete list;
    */

    //ARRAY

    DynamicArray< Complex<int, int> >* array = new DynamicArray< Complex<int, int> >();
    array->PushFront(complex2);
    array->PushFront(complex1);
    array->PushBack(complex3);
    array->PushBack(complex4);
    for(int i = 0; i < array->GetSize(); i++)
        (*array)[i].PrintComplex();
    cout << endl;
    DynamicArray< Complex<int, int> >* array_copy = new DynamicArray< Complex<int, int> >(*array);
    array_copy->Resize(3);
    array_copy->PopFront();
    array_copy->PopBack();
    for(int i = 0; i < array_copy->GetSize(); i++)
        (*array_copy)[i].PrintComplex();
    cout << endl;
    delete array_copy;
    delete array;


    return 0;
}
