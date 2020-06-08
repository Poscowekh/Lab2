#pragma once
#ifndef LINKEDLISTSEQUENCE_H
#define LINKEDLISTSEQUENCE_H
#include "LinkedList.hpp"
#include "Sequence.hpp"
#include "DynamicArraySequence.hpp"

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
            CheckEmpty();
        };
        LinkedListSequence(const LinkedList<DataType>& from)
        {
            list = new LinkedList<DataType>(from);
            length = list->GetLength();
            CheckEmpty();
        };
        LinkedListSequence(const LinkedListSequence<DataType>& from)
        {
            list = new LinkedList<DataType>(*(from.list));
            length = list->GetLength();
            CheckEmpty();
        };
        LinkedListSequence(DynamicArray<DataType>* from)
        {
            list = new LinkedList<DataType>(from->DataPointer(), from->GetLength());
            length = from->GetLength();
            CheckEmpty();
        };
        void Set(int index, DataType new_data)
        {
            list->Set(index, new_data);
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
            result->CheckEmpty();
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
            list->Concate(other->list);
            length = list->GetLength();
            CheckEmpty();
        };
        /*
        void Concate(LinkedList<DataType>* other)
        {
            list->ConcateFrom(other);
            length = list->GetSize();
            if(length > 0)
                empty = false;
        };
        */
        LinkedListSequence<DataType>* GetConcated(LinkedListSequence<DataType>* other)
        {
            LinkedListSequence<DataType>* result = new LinkedListSequence<DataType>(*this);
            result->Concate(other);
            return result;
        };
        LinkedListSequence<DataType>* GetCopy()
        {
            LinkedListSequence<DataType>* result = new LinkedListSequence<DataType>();
            result->list = list;
            result->length = length;
            result->empty = empty;
            return result;
        };
        void CopyTo(LinkedListSequence<DataType>* to, int from_index, int to_index)
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
};

#endif // LINKEDLISTSEQUENCE_H
