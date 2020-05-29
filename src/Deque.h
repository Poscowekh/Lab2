#pragma once
#ifndef DEQUE_H
#define DEQUE_H
#include "DynamicArray.h"
#include "LinkedList.h"
#include "Sequence.h"

using namespace std;

template<class DataType>
class Deque
{
    private:
        LinkedListSequence<DataType>* data;
        int size;
        bool empty;
    public:
        Deque()
        {
            size = 0;
            empty = true;
            data = new LinkedListSequence<DataType>();
        };
        Deque(const DataType* new_data, const int count)
        {
            data = new LinkedListSequence<DataType>(new_data, count);
            size = count;
            if(size > 0)
                empty = false;
            else
                empty = true;
        };
        Deque(LinkedListSequence<DataType>* new_data)
        {
            data = new LinkedListSequence<DataType>(new_data);
            size = new_data->GetLength();
            if(size > 0)
                empty = false;
            else
                empty = true;
        };
        int GetSize()
        {
            return size;
        };
        bool Empty()
        {
            return empty;
        };
        DataType Get(const int index) const
        {
            return data->Get(index);
        };
        DataType* GetPointer(const int index) const
        {
            return data->GetPointer(index);
        };
        void PopBack()
        {
            data->RemoveAt(data->GetLength() - 1);
            size--;
            if(size == 0)
                empty = true;
        };
        void PopFront()
        {
            data->RemoveAt(0);
            size--;
            if(size == 0)
                empty = true;
        };
        void PushBack(DataType new_data)
        {
            data->Append(&new_data);
            size++;
            empty = false;
        };
        void PushBack(DataType* new_data)
        {
            data->Append(new_data);
            size++;
            empty = false;
        };
        void PushFront(DataType new_data)
        {
            data->Prepend(&new_data);
            size++;
            empty = false;
        };
        void PushFront(DataType* new_data)
        {
            data->Prepend(new_data);
            size++;
            empty = false;
        };
        void Clear()
        {
            data->RemoveAll();
            size = 0;
            empty = true;
        };
        DataType& operator[](const int index)
        {
            return *(GetPointer(index));
        };
        Deque& operator=(const Deque& deque)
        {
            data = deque.data;
            size = deque.size;
            empty = deque.empty;
            return this;
        };
        ~Deque()
        {
            data->~LinkedListSequence<DataType>();
            delete data;
            size = 0;
            empty = true;
        }
};

#endif // DEQUE_H
