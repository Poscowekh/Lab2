#pragma once
#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "DynamicArray.h"
#include "LinkedList.h"

using namespace std;

template<class DataType>
class Sequence
{
    public:
        virtual DataType GetLength() const = 0;
        virtual DataType GetFirst() const = 0;
        virtual DataType GetLast() const = 0;
        virtual DataType Get(const int index) const = 0;
        virtual Sequence<DataType>* GetSubsequence(const int from, const int to) const = 0;
        virtual void Append(DataType data) = 0;    //to tail
        virtual void Prepend(DataType data) = 0;   //to first
        virtual void InsertAt(const int index, DataType data) = 0;
        virtual void RemoveAt(const int index) = 0;
        virtual void RemoveAll()  = 0;
        virtual void Concate(Sequence<DataType>* other) = 0;
        virtual Sequence<DataType>* GetCopy() = 0;
        virtual void CopyTo(Sequence<DataType>* to, int from_index, int to_index) = 0;
        virtual ~Sequence(){};
};

template <class DataType>
class ArraySequence : Sequence<DataType>
{
    private:
        DynamicArray<DataType>* array;
        int length;
    public:
        ArraySequence()
        {
            array = 0;
            length = 0;
        };
        ArraySequence(DataType* data, int count)
        {
            array = new DynamicArray<DataType>(data, count);
            length = array->GetSize();
        };
        ArraySequence(const DynamicArray<DataType>& from)
        {
            array = new DynamicArray<DataType>(from);
            length = array->GetSize();
        };
        int GetLength()
        {
            return length;
        };
        DataType GetFirst()
        {
            return array->Front();
        };
        DataType Get(const int index)
        {
            return array->Get(index);
        };
        DataType GetLast()
        {
            return array->Back();
        };
        ArraySequence<DataType>* GetSubsequence(const int from, const int to)
        {
            ArraySequence<DataType>* result = new ArraySequence<DataType>();
            result->array = array->GetSubArray(from, to);
            return result;
        };
        void Append(DataType data)
        {
            array->PushBack(&data);
            length++;
        };
        void Prepend(DataType data)
        {
            array->PushFront(&data);
            length++;
        };
        void InsertAt(const int index, DataType data)
        {
            array->InsertAt(&data, index);
            length++;
        };
        void RemoveAt(const int index)
        {
            array->RemoveAt(index);
            length--;
        };
        void RemoveAll()
        {
            array->Clear();
            length = 0;
        };
        void Concate(ArraySequence<DataType>* other)
        {
            array->CopyToArray(other->array->FrontPointer(), 0, other->array->GetSize());
            length = array->GetSize();
        };
        ArraySequence<DataType>* GetCopy()
        {
            ArraySequence<DataType>* result = new ArraySequence<DataType>();
            result->array = array;
            return result;
        };
        void CopyTo(ArraySequence<DataType>* to, int from_index, int to_index)
        {
            to->array = array->GetSubArray(from_index, to_index);
            to->length = to->array->GetLength();
        };
        ~ArraySequence()
        {
            length = 0;
            delete array;
        };
};

template <class DataType>
class LinkedListSequence : Sequence<DataType>
{
    private:
        LinkedList<DataType>* list;
        int length;
    public:
        LinkedListSequence()
        {
            list = 0;
            length = 0;
        };
        LinkedListSequence(DataType* data, int count)
        {
            list = new LinkedList<DataType>(data, count);
            length = list->GetLength();
        };
        LinkedListSequence(const LinkedList<DataType>& from)
        {
            list = new LinkedList<DataType>(from);
            length = list->GetSize();
        };
        int GetLength()
        {
            return length;
        };
        DataType GetFirst()
        {
            return *list->FrontPointer();
        };
        DataType Get(const int index)
        {
            return *list->GetPointer(index);
        };
        DataType GetLast()
        {
            return *list->BackPointer();
        };
        LinkedListSequence<DataType>* GetSubsequence(const int from, const int to)
        {
            LinkedList<DataType>* result = new LinkedList<DataType>();
            result->list = list->GetSubList(from, to);
            return result;
        };
        void Append(DataType data)
        {
            list->PushBack(&data);
            length++;
        };
        void Prepend(DataType data)
        {
            list->PushFront(&data);
            length++;
        };
        void InsertAt(const int index, DataType data)
        {
            list->InsertAt(&data, index);
            length++;
        };
        void RemoveAt(const int index)
        {
            list->RemoveAt(index);
            length--;
        };
        void RemoveAll()
        {
            list->Clear();
            length = 0;
        };
        void Concate(LinkedListSequence<DataType> other)
        {
            list->CopyToArray(other->list->FrontPointer(), 0, other->list->GetSize());
            length = list->GetSize();
        };
        LinkedListSequence<DataType>* GetCopy()
        {
            LinkedListSequence<DataType>* result = new  LinkedListSequence<DataType>();
            result->list = list;
            result->length = length;
            return result;
        };
        void CopyTo( LinkedListSequence<DataType>* to, int from_index, int to_index)
        {
            to->list = list->GetSubArray(from_index, to_index);
        };
        DataType& operator[](const int index)
        {
            return *list->GetPointer(index);
        };
        ~LinkedListSequence()
        {
            delete list;
            length = 0;
        };
};

#endif // SEQUENCE_H
