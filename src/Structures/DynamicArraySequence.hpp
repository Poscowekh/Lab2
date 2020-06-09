#pragma once
#ifndef ARRAYSEQUENCE_H
#define ARRAYSEQUENCE_H
#include "Sequence.hpp"
#include "DynamicArray.hpp"

template <class DataType>
class DynamicArraySequence
{
    private:
        DynamicArray<DataType>* array;
        int length;
        bool empty;
        void CheckEmpty()
        {
            if(length > 0)
                empty = false;
            else
                empty = true;
        };
    public:
        DynamicArraySequence()
        {
            array = 0;
            length = 0;
            empty = true;
        };
        DynamicArraySequence(DataType* data, int count)
        {
            array = new DynamicArray<DataType>(data, count);
            length = array->GetLength();
            CheckEmpty();
        };
        DynamicArraySequence(const DynamicArray<DataType>& from)
        {
            array = new DynamicArray<DataType>(from);
            length = array->GetLength();
            CheckEmpty();
        };
        DynamicArraySequence(const DynamicArraySequence<DataType>& from)
        {
            array = new DynamicArray<DataType>(from.array);
            length = from.length;
            CheckEmpty();
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
        DynamicArray<DataType>* DataPointer()
        {
            return array;
        };
        DynamicArraySequence<DataType>* GetSubsequence(const int from, const int to)
        {
            DynamicArraySequence<DataType>* result = new DynamicArraySequence<DataType>();
            result->array = array->GetSubArray(from, to);
            result->CheckEmpty();
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
        void Concate(DynamicArraySequence<DataType>* other)
        {
            array->CopyToArray(other->array->FrontPointer(), 0, other->array->GetLength());
            length = array->GetLength();
            CheckEmpty();
        };
        DynamicArraySequence<DataType>* GetCopy()
        {
            DynamicArraySequence<DataType>* result = new DynamicArraySequence<DataType>();
            result->array = array;
            result->length = length;
            CheckEmpty();
            return result;
        };
        void CopyTo(DynamicArraySequence<DataType>* to, int from_index, int to_index)
        {
            to->array = array->GetSubArray(from_index, to_index);
            to->length = to->array->GetLength();
            CheckEmpty();
        };
        DataType& operator[](const int index)
        {
            return Get(index);
        };
        DynamicArraySequence<DataType>* operator=(DynamicArraySequence<DataType>* other)
        {
            return new DynamicArray<DataType>(*other);
        };
        DynamicArray<DataType>* operator+(DynamicArray<DataType>* other)
        {
            DynamicArray<DataType>* result;
            result->ConcateTo(*this, *other);
            result->length = length + other->length;
            result->CheckEmpty();
            return result;
        };
        ~DynamicArraySequence(){};
};

#endif // ARRAYSEQUENCE_H
