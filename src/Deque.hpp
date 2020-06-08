#pragma once
#ifndef DEQUE_H
#define DEQUE_H
#include "LInkedListSequence.hpp"
#include "DynamicArraySequence.hpp"

using namespace std;

template<class DataType>
class Deque
{
    private:
        LinkedListSequence<DataType>* data;
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
        Deque()
        {
            length = 0;
            empty = true;
            data = new LinkedListSequence<DataType>();
        };
        Deque(const DataType* new_data, const int count)
        {
            data = new LinkedListSequence<DataType>(new_data, count);
            length = count;
            CheckEmpty();
        };
        Deque(const Deque<DataType>& deque)
        {
            data = new LinkedListSequence<DataType>(*(deque.data));
            length = deque.length;
            CheckEmpty();
        };
        Deque(DynamicArray<DataType>* array)
        {
            data = new LinkedListSequence<DataType>(array);
            length = array->GetLength();
            CheckEmpty();
        };
        int GetLength()
        {
            return length;
        };
        bool Empty()
        {
            return empty;
        };
        DataType Get(int index)
        {
            return data->Get(index);
        };
        void Set(int index, DataType new_data)
        {
            data->Set(index, new_data);
        };
        void PopBack()
        {
            data->PopBack();
            length--;
            CheckEmpty();
        };
        void PopFront()
        {
            data->PopFront();
            length--;
            CheckEmpty();
        };
        void PushBack(DataType new_data)
        {
            data->Append(new_data);
            length++;
            empty = false;
        };
        void PushBack(DataType* new_data)
        {
            PushBack(&new_data);
        };
        void PushFront(DataType new_data)
        {
            data->Prepend(new_data);
            length++;
            empty = false;
        };
        void PushFront(DataType* new_data)
        {
            PushFront(new_data);
        };
        void Clear()
        {
            data->RemoveAll();
            length = 0;
            empty = true;
        };
        void PrintDeque()
        {
            for(int i = 0; i < length; i++)
                cout << i << ": " << Get(i) << endl;
            cout << endl;
        };
        void PrintDequeForComplex()
        {
            for(int i = 0; i < length; i++)
                cout << i << ": " << Get(i).ComplexToString() << endl;
            cout << endl;
        };
        void RemoveAt(const int index)
        {
            data->RemoveAt(index);
        };
        void InsertAt(const int index, DataType new_data)
        {
            data->InsertAt(index, new_data);
        };
        Deque<DataType>* SubDeck(int from, int to)
        {
            Deque<DataType>* result = new Deque<DataType>();
            result->data = data->GetSubsequence(from, to);
            result->length = to - from + 1;
            result->CheckEmpty();
            return result;
        };
        DataType& operator[](const int index)
        {
            return &data->Get(index);
        };
        Deque<DataType>& operator=(const Deque* deque)
        {
            data = deque->data;
            length = deque->length;
            empty = deque->empty;
            return this;
        };
        Deque<DataType>& operator=(const Deque& deque)
        {
            data = deque->data;
            length = deque->length;
            empty = deque->empty;
            return this;
        };
        void Concate(Deque<DataType>* other)
        {
            data->Concate(other->data);
            length = data->GetLength();
            CheckEmpty();
        };
        Deque<DataType>* GetConcated(Deque<DataType>* other)
        {
            Deque<DataType>* result = new Deque<DataType>(*this);
            result->Concate(other);
            return result;
        };
        Deque<DataType>& operator+(Deque<DataType>* other)
        {
            Deque<DataType>* result = new Deque<DataType>(*this);
            result->Concate(other);
            return result;
        };
        void operator--()
        {
            PopBack();
        };
        ~Deque(){};
};

#endif // DEQUE_H
