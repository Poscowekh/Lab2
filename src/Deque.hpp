#pragma once
#ifndef DEQUE_H
#define DEQUE_H
#include "Sequence.hpp"

using namespace std;

template<class DataType>
class Deque
{
    private:
        LinkedListSequence<DataType> data;
        int size;
        bool empty;
        void CheckEmpty()
        {
            if(size > 0)
                empty = false;
            else
                empty = true;
        };
    public:
        Deque()
        {
            size = 0;
            empty = true;
            data = LinkedListSequence<DataType>();
        };
        Deque(const DataType* new_data, const int count)
        {
            data = LinkedListSequence<DataType>(new_data, count);
            size = count;
            CheckEmpty();
        };
        Deque(const Deque<DataType>& deque)
        {
            data = LinkedListSequence<DataType>(deque.data);
            size = deque.size;
            CheckEmpty();
        };
        int GetSize()
        {
            return size;
        };
        bool Empty()
        {
            return empty;
        };
        DataType Get(int index)
        {
            return data.Get(index);
        };
        void PopBack()
        {
            data.PopBack();
            size--;
            CheckEmpty();
        };
        void PopFront()
        {
            data.PopFront();
            size--;
            CheckEmpty();
        };
        void PushBack(DataType new_data)
        {
            data.Append(new_data);
            size++;
            empty = false;
        };
        void PushBack(DataType* new_data)
        {
            PushBack(&new_data);
        };
        void PushFront(DataType new_data)
        {
            data.Prepend(new_data);
            size++;
            empty = false;
        };
        void PushFront(DataType* new_data)
        {
            PushFront(new_data);
        };
        void Clear()
        {
            data.RemoveAll();
            size = 0;
            empty = true;
        };
        DataType& operator[](const int index)
        {
            return data[index];
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
            data.~LinkedListSequence<DataType>();
            delete data;
            size = 0;
            empty = true;
            delete this;
        };
};

#endif // DEQUE_H
