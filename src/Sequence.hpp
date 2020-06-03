#pragma once
#ifndef SEQUENCE_H
#define SEQUENCE_H
#include "DynamicArray.hpp"
#include "LinkedList.hpp"
#include "Function.hpp"

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
        virtual DataType Reduce(Function<DataType, DataType> function, DataType const_value) = 0;
        virtual Sequence<DataType>* Map(Function<DataType, DataType> function) = 0;
        virtual Sequence<DataType>* Where(Function<bool, DataType> function) = 0;
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
        ArraySequence<DataType>* Map(Function<DataType, DataType> function)
        {
            ArraySequence<DataType>* result = new ArraySequence<DataType>();
            for(int i = 0; i < length; i++)
                result->Append(function(Get(i)));
            return result;
        };
        ArraySequence<DataType>* Where(Function<DataType, DataType> function)
        {
            ArraySequence<DataType>* result = new ArraySequence<DataType>();
            for(int i = 0; i < length; i++)
                if(function(Get(i)))
                    result->Append(Get(i));
            return result;
        };
        DataType Reduce(Function<DataType, DataType> function, DataType const_value)
        {
            DataType result = function(Get(0), const_value);
            for(size_t i = 1; i < length; ++i)
                result = function(Get(i), result);
            return result;
        };
        ~ArraySequence(){};
};

template <class DataType>
class LinkedListSequence
{
    private:
        LinkedList<DataType>* list;
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
            list = new LinkedList<DataType>(from);
            length = list->GetLength();
            if(length > 0)
                empty = false;
            else
                empty = true;
        };
        LinkedListSequence(const LinkedListSequence<DataType>& from)
        {
            list = new LinkedList<DataType>(*from.list);
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
            return list->Front();
        };
        DataType Get(const int index)
        {
            return list->Get(index);
        };
        DataType GetLast()
        {
            return list->Back();
        };
        LinkedListSequence<DataType>* GetSubsequence(const int from, const int to)
        {
            LinkedListSequence<DataType>* result = new LinkedListSequence<DataType>();
            result->list = list->GetSublist(from, to);
            result->length = result->list->GetLength();
            CheckEmpty();
            return result;
        };
        void Append(DataType data)
        {
            list->PushBack(data);
            length++;
            empty = false;
        };
        void Append(DataType* data)
        {
            Append(*data);
        };
        void Prepend(DataType data)
        {
            list->PushFront(data);
            length++;
            empty = false;
        };
        void Prepend(DataType* data)
        {
            Prepend(*data);
        };
        void InsertAt(const int index, DataType data)
        {
            list->InsertAt(data, index);
            length++;
        };
        void InsertAt(const int index, DataType* data)
        {
            InsertAt(*data, index);
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
        void PopBack()
        {
            list->PopBack();
            length--;
            CheckEmpty();
        };
        void PopBack(int cut)
        {
            list->PopBack(cut);
            length--;
            CheckEmpty();
        };
        void PopFront()
        {
            list->PopFront();
            length--;
            CheckEmpty();
        };
        void PopFront(int cut)
        {
            list->PopFront(cut);
            length--;
            CheckEmpty();
        };
        void Concate(LinkedListSequence<DataType>* other)
        {
            list = list->ConcateFrom(*other->list);
            length = list->GetLength();
            if(length > 0)
                empty = false;
        };
        void Concate(LinkedList<DataType>* other)
        {
            list->ConcateFrom(other);
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
            to->list = list->GetSublist(from_index, to_index);
            if(to->length > 0)
                to->empty = false;
            else
                to->empty = true;
        };
        DataType& operator[](const int index)
        {
            return (*list)[index];
        };
        ~LinkedListSequence(){};
        LinkedListSequence<DataType>* Map(Function<DataType, DataType> function)
        {
            LinkedListSequence<DataType>* result = new LinkedListSequence<DataType>();
            for(int i = 0; i < length; i++)
                result->Append(function(Get(i)));
            return result;
        };
        LinkedListSequence<DataType>* Where(Function<DataType, DataType> function)
        {
            LinkedListSequence<DataType>* result = new LinkedListSequence<DataType>();
            for(int i = 0; i < length; i++)
                if(function(Get(i)))
                    result->Append(Get(i));
            return result;
        };
        DataType Reduce(Function<DataType, DataType> function, DataType const_value)
        {
            DataType result = function(Get(0), const_value);
            for(size_t i = 1; i < length; ++i)
                result = function(Get(i), result);
            return result;
        };
};

#endif // SEQUENCE_H
