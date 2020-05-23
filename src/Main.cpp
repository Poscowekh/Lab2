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

    LinkedList< Complex<int,int> >* list1 = new LinkedList< Complex<int,int> >();
    list1->PushFront(&complex2);
    list1->PushFront(complex1);
    //list1->PushBack(&complex3);
    //list1->PushBack(complex4);
    cout << "First element:" << endl << "   ";
    list1->Front().PrintComplex();
    cout << "   ";
    list1->FrontPointer()->PrintComplex();
    cout << "Sesond element:" << endl << "   ";
    list1->Get(1).PrintComplex();
    //cout << "Third element:" << endl << "   ";
    //list1->GetPointer(2)->PrintComplex();
    /*cout << "Fourth element:" << endl << "   ";
    list1->Back().PrintComplex();
    cout << "   ";
    list1->BackPointer()->PrintComplex();  */
    cout << endl;
    for(int i = 0; i < list1->GetLength(); i++)
        list1->GetPointer(i)->PrintComplex();
    //LinkedList< Complex<int,int> >* list2 = list1->GetSubList(1,1);


    //ARRAY
    /*
    DynamicArray< Complex<int, int> >* array = new DynamicArray< Complex<int, int> >();
    array->PushFront(complex1);
    array->PushFront(complex2);
    array->PushBack(complex3);
    array->Front().PrintComplex();
    array->Get(1).PrintComplex();
    array->Back().PrintComplex();
    DynamicArray< Complex<int, int> >* copy_array = new DynamicArray< Complex<int, int> >(array);
    array->Front().PrintComplex();
    array->Get(1).PrintComplex();
    array->Back().PrintComplex();
    */

    return 0;
}
