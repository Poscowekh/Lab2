#pragma once
#ifndef LINKELIST_H
#define LINKELIST_H

#include <cassert>

using namespace std;

// LIST ELEMENT
template <class DataType>
class Node
{
    private:
        DataType* data;
        Node<DataType>* next;
        Node<DataType>* prev;
    public:
        Node()
        {
            data = 0;
            next = 0;
            prev = 0;
        };
        Node(DataType* new_data)
        {
            data = new_data;
            next = 0;
            prev = 0;
        };
        Node(DataType* new_data, Node<DataType>* new_next,  Node<DataType>* new_prev)
        {
            data = new_data;
            next = new_next;
            prev = new_prev;
        };
        Node<DataType>* GetNext()
        {
            return next;
        };
        Node<DataType>* GetPrev()
        {
            return prev;
        };
        void SetNext(Node<DataType>* new_next)
        {
            next = new_next;
        };
        void SetPrev(Node<DataType>* new_prev)
        {
            prev = new_prev;
        };
        void Set(DataType* new_data)
        {
            data = new_data;
        };
        DataType Get()
        {
            return *data;
        };
        DataType* GetPointer()
        {
            return data;
        };
};

// LIST
template <class DataType>
class LinkedList
{
    private:
        int length;
        Node<DataType>* head;
        Node<DataType>* tail;
        Node<DataType>* GetIndex(int index)
        {
            Node<DataType>* tmp = head;
            for(int i = 0; i < index; i++)
                tmp = tmp->GetNext();
            return tmp;
        };
        void SetIndex(int index, DataType* data)
        {
            GetIndex(index)->Set(data);
        };
        Node<DataType>* GetLast()
        {
            return GetIndex(length - 1);
        };
        void SetLast(DataType* data)
        {
            GetLast()->Set(data);
        };
    public:
        LinkedList()
        {
            length = 0;
            head = new Node<DataType>();
        };
        LinkedList(const LinkedList<DataType> & list)
        {
            length = list.length;
            head = list.head;
            tail = list.tail;
        };
        LinkedList(DataType* new_data, int count)
        {
            assert(count < 1 && "IndexOutOfRange");
            for(int i = 0; i < count; i++)
                PushBack(new_data + i);
        };
        void SetLength(int new_length)
        {
            assert(new_length < 1 && "IndexOutOfRange");
            if(new_length < length)
            for(int i = 0; i < new_length - length; i++)
                PopBack();
            length = new_length;
        };
        int GetLength()
        {
            return length;
        };
        void PopBack()
        {
            assert(length < 1 && "IndexOutOfRange");
            if(length > 1)
            {
                GetIndex(length - 2)->SetNext(0);
                tail = GetIndex(length - 2);
            }
            else
            {
                head = 0;
                tail = 0;
            };
            length--;
        };
        void PushBack(DataType* new_data)
        {
            Node<DataType>* tmp = new Node<DataType>(new_data);
            if(length > 0)
                GetLast()->SetNext(tmp);
            else
                head = tmp;
            tail = tmp;
            length++;
        };
        void PopFront()
        {
            assert(length < 1 && "IndexOutOfRange");
            head = head->GetNext();
            length--;
        };
        void PushFront(DataType* new_data)
        {
            Node<DataType>* tmp = new Node<DataType>(new_data);
            if(length != 0)
                tmp->SetNext(head);
            head = tmp;
            if(length == 0)
                tail = head;
            length++;
        };
        DataType Front()
        {
            assert(length < 1 && "IndexOutOfRange");
            return head->Get();
        };
        DataType* FrontPointer()
        {
            assert(length < 1 && "IndexOutOfRange");
            return head->GetPointer();
        };
        void Set(int index, DataType* data)
        {
            assert(index < 0 && "IndexOutOfRange");
            assert(index + 1 > length && "IndexOutOfRange");
            GetIndex(index)->Set(data);
        };
        void Set(int index, DataType data)
        {
            Set(index, &data);
        };
        void RemoveAt(int index)
        {
            assert(index < 0 && "IndexOutOfRange");
            assert(index + 1 > length && "IndexOutOfRange");
            if(index == 0)
                PopFront();
            else
            {
                if(index == length - 1)
                    PopBack();
                else
                {
                    GetIndex(index - 1)->SetNext(GetIndex(index)->GetNext());
                };
            };
            length--;
        };
        void InsertAt(DataType* data, int index)
        {
            assert(index < 0 && "IndexOutOfRange");
            assert(index + 1 > length && "IndexOutOfRange");
            Node<DataType>* tmp = new Node<DataType>(data);
            tmp->SetNext(GetIndex(index));
            GetIndex(index - 1)->SetNext(tmp);
            length++;
        };
        void Clear()
        {
            head = 0;
            tail = 0;
            length = 0;
        };
        DataType Get(int index)
        {
            assert(index < 0 && "IndexOutOfRange");
            assert(index + 1 > length && "IndexOutOfRange");
            return GetIndex(index)->Get();
        };
        DataType* GetPointer(int index)
        {
            assert(index < 0 && "IndexOutOfRange");
            assert(index + 1 > length && "IndexOutOfRange");
            return GetIndex(index)->GetPointer();
        };
        DataType Back()
        {
            assert(length < 1 && "IndexOutOfRange");
            return tail->Get();
        };
        DataType* BackPointer()
        {
            assert(length < 1 && "IndexOutOfRange");
            return tail->GetPointer();
        };
        LinkedList<DataType>* GetSubList(int from, int to)
        {
            assert(from + 1 > length && "IndexOutOfRange");
            assert(to + 1 > length && "IndexOutOfRange");
            assert(from < 0 && "IndexOutOfRange");
            assert(to < 0 && "IndexOutOfRange");
            assert(from > to && "IndexOutOfRange");
            LinkedList<DataType>* sublist = new LinkedList<DataType>();
            for(int i = from; i <= to; i++)
                sublist->PushBack(GetPointer(i));
            return sublist;
        };
        DataType& operator[](const int index)
        {
            assert(index < 0 && "IndexOutOfRange");
            assert(index + 1 > length && "IndexOutOfRange");
            return *GetPointer(index);
        };

        /*
        LinkedList(T* items, int count); //Копировать элементы из переданного массива
        LinkedList(); Создать пустой список
        LinkedList(LinkedList <T> & list const); //Копирующий конструктор

        Декомпозиция
        T GetFirst();
        T GetLast();
        DataType Get(int index);
        LinkedList<DataType>* GetSubList(int startIndex, int endIndex);
        Может выбрасывать исключения:
        − IndexOutOfRange (если хотя бы один из индексов отрицательный
        или больше/равен числу элементов)
        Получить список из всех
        элементов, начиная с startIndex и
        заканчивая endIndex.*/
};

#endif // LINKELIST_H
