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
        //virtual void Concate(Sequence<DataType>* other) = 0;
        //virtual Sequence<DataType>* GetCopy() = 0;
        virtual void CopyTo(Sequence<DataType>* to, int from_index, int to_index) = 0;
        virtual ~Sequence(){};
};

template <class DataType>
class ArraySequence
{
    private:
        DynamicArray<DataType>* array;
        int length;
        bool empty;
    public:
        ArraySequence()
        {
            array = 0;
            length = 0;
            empty = true;
        };
        ArraySequence(DataType* data, int count)
        {
            array = new DynamicArray<DataType>(data, count);
            length = array->GetSize();
            if(length > 0)
                empty = false;
            else
                empty = true;
        };
        ArraySequence(const DynamicArray<DataType>& from)
        {
            array = new DynamicArray<DataType>(from);
            length = array->GetSize();
            if(length > 0)
                empty = false;
            else
                empty = true;
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
            if(length > 0)
                result->empty = false;
            else
                result->empty = true;
            return result;
        };
        void Append(DataType data)
        {
            array->PushBack(&data);
            length++;
            empty = false;
        };
        void Prepend(DataType data)
        {
            array->PushFront(&data);
            length++;
            empty = false;
        };
        void InsertAt(const int index, DataType data)
        {
            array->InsertAt(&data, index);
            length++;
            empty = false;
        };
        void RemoveAt(const int index)
        {
            array->RemoveAt(index);
            length--;
            if(length < 1)
                empty = true;
        };
        void RemoveAll()
        {
            array->Clear();
            length = 0;
            empty = true;
        };
        void Concate(ArraySequence<DataType>* other)
        {
            array->CopyToArray(other->array->FrontPointer(), 0, other->array->GetSize());
            length = array->GetSize();
            if(length > 0)
                empty = false;
        };
        ArraySequence<DataType>* GetCopy()
        {
            ArraySequence<DataType>* result = new ArraySequence<DataType>();
            result->array = array;
            result->length = length;
            if(length > 0)
                result->empty = false;
            else
                result->empty = true;
            return result;
        };
        void CopyTo(ArraySequence<DataType>* to, int from_index, int to_index)
        {
            to->array = array->GetSubArray(from_index, to_index);
            to->length = to->array->GetLength();
            if(to->length > 0)
                to->empty = false;
            else
                to->empty = true;
        };
        ~ArraySequence()
        {
            length = 0;
            empty = true;
            delete array;
        };
};

template <class DataType>
class LinkedListSequence
{
    private:
        LinkedList<DataType>* list;
        int length;
        bool empty;
    public:
        LinkedListSequence()
        {
            list = new LinkedList<DataType>();
            length = 0;
            empty = true;
        };
        LinkedListSequence(DataType* data, int count)
        {
            list = new LinkedList<DataType>(data, count);
            length = list->GetLength();
            if(count > 0)
                empty = false;
            else
                empty = true;
        };
        LinkedListSequence(const LinkedList<DataType>& from)
        {
            list = from;
            length = list->GetLength();
            if(length > 0)
                empty = false;
            else
                empty = true;
        };
        int GetLength()
        {
            return length;
        };
        bool Empty()
        {
            return empty;
        };
        DataType GetFirst()
        {
            return *list->FrontPointer();
        };
        DataType Get(const int index)
        {
            return list->Get(index);
        };
        DataType* GetPointer(const int index)
        {
            return list->GetPointer(index);
        };
        DataType GetLast()
        {
            return *list->BackPointer();
        };
        LinkedListSequence<DataType>* GetSubsequence(const int from, const int to)
        {
            LinkedListSequence<DataType>* result = new LinkedListSequence<DataType>();
            result->list = list->GetSubList(from, to);
            length = list->GetLength();
            if(length > 0)
                result->empty = false;
            return result;
        };
        void Append(DataType* data)
        {
            list->PushBack(data);
            length++;
            empty = false;
        };
        void Prepend(DataType* data)
        {
            list->PushFront(data);
            length++;
            empty = false;
        };
        void InsertAt(const int index, DataType* data)
        {
            list->InsertAt(data, index);
            length++;
        };
        void RemoveAt(const int index)
        {
            list->RemoveAt(index);
            length--;
            if(length < 1)
                empty = true;
        };
        void RemoveAll()
        {
            list->Clear();
            length = 0;
            empty = true;
        };
        void Concate(LinkedListSequence<DataType>* other)
        {
            list->CopyToArray(other->list->FrontPointer(), 0, other->list->GetSize());
            length = list->GetSize();
            if(length > 0)
                empty = false;
        };
        LinkedListSequence<DataType>* GetCopy()
        {
            LinkedListSequence<DataType>* result = new LinkedListSequence<DataType>();
            result->list = list;
            result->length = length;
            result->empty = empty;
            return result;
        };
        void CopyTo( LinkedListSequence<DataType>* to, int from_index, int to_index)
        {
            to->list = list->GetSubArray(from_index, to_index);
            if(to->length > 0)
                to->empty = false;
            else
                to->empty = true;
        };
        DataType& operator[](const int index)
        {
            return *(GetPointer(index));
        };
        ~LinkedListSequence()
        {
            delete list;
            empty = true;
            length = 0;
        };
};

#endif // SEQUENCE_H
