#pragma once
#ifndef LINKELIST_H
#define LINKELIST_H
#include "Exception.h"

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
            data = NULL;
            next = NULL;
            prev = NULL;
        };
        Node(DataType* new_data)
        {
            data = new_data;
            next = NULL;
            prev = NULL;
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
        bool empty;
        Node<DataType>* GetIndex(int index)
        {
            Node<DataType>* tmp;
            if(index < length / 2)
            {
                tmp = head;
                for(int i = 0; i < index; i++)
                    tmp = tmp->GetNext();
            }
            else
            {
                tmp = tail;
                for(int i = length - 1; i > index; i--)
                    tmp = tmp->GetPrev();
            };
            return tmp;
        };
        void SetIndex(int index, DataType* data)
        {
            GetIndex(index)->Set(data);
        };
    public:
        LinkedList()
        {
            length = 0;
            head = NULL;
            tail = NULL;
            empty = true;
        };
        LinkedList(const LinkedList<DataType>& list)
        {
            length = list.length;
            head = list.head;
            tail = list.tail;
            if(head == NULL)
                empty = true;
            else
                empty = false;
        };
        LinkedList(DataType* new_data, int count)
        {
            if(count < 1)
                try{
                    throw 1;
                } catch(int code){
                    Exception* a = new Exception(code);
                };
            for(int i = 0; i < count; i++)
                PushBack(new_data + i);
            if(length > 0)
                empty = false;
            else
                empty = true;
        };
        void SetLength(int new_length)
        {
            if(new_length < 1)
            {
                try{
                    throw 1;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            for(int i = 0; i < new_length - length; i++)
                PopBack();
            length = new_length;
            if(length == 0)
                empty = true;
        };
        int GetLength()
        {
            return length;
        };
        void PopBack()
        {
            if(length < 1)
            {
                try{
                    throw 1;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            if(length > 1)
            {
                GetIndex(length - 2)->SetNext(0);
                tail = GetIndex(length - 2);
            }
            else
            {
                head = NULL;
                tail = NULL;
            };
            length--;
            if(length == 0)
                empty = true;
        };
        void PushBack(DataType* new_data)
        {
            Node<DataType>* tmp = new Node<DataType>(new_data, NULL, tail);
            tail = tmp;
            if(length == 0)
                head = tmp;
            empty = false;
            length++;
        };
        void PushBack(DataType new_data)
        {
            PushBack(&new_data);
        };
        void PopFront()
        {
            if(length < 1)
            {
                try{
                    throw 1;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            head = head->GetNext();
            length--;
            if(length == 0)
                empty = true;
        };
        void PushFront(DataType* new_data)
        {
            Node<DataType>* tmp = new Node<DataType>(new_data, GetIndex(0), NULL);
            head = tmp;
            if(length == 0)
                tail = tmp;
            length++;
            empty = false;
        };
        void PushFront(DataType new_data)
        {
            PushFront(&new_data);
        };
        DataType* FrontPointer()
        {
            if(length < 1)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            return head->GetPointer();
        };
        DataType Front()
        {
            return *FrontPointer();
        };
        void Set(int index, DataType* data)
        {
            if(index < 0)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            if(index + 1 > length)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            if(length > 0)
                GetIndex(index)->Set(data);
            else
                PushFront(data);
        };
        void Set(int index, DataType data)
        {
            Set(index, &data);
        };
        void RemoveAt(int index)
        {
            if(index < 0)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            if(index + 1 > length)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            if(index == 0)
                PopFront();
            else
            {
                if(index == length - 1)
                    PopBack();
                else
                {
                    GetIndex(index - 1)->SetNext(GetIndex(index)->GetNext());
                    GetIndex(index)->GetNext()->SetPrev(GetIndex(index - 1));
                };
            };
            length--;
            if(length == 0)
                empty = true;
        };
        void InsertAt(DataType* data, int index)
        {
            if(index < 0)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            if(index + 1 > length)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            if(index == 0)
                PushFront(data);
            else
            {
                Node<DataType>* tmp = new Node<DataType>(data, GetIndex(index), GetIndex(index - 1));
                tmp->GetNext()->SetPrev(tmp);
                tmp->GetPrev()->SetNext(tmp);
                length++;
            };
            empty = false;
        };
        void Clear()
        {
            head = NULL;
            tail = NULL;
            length = 0;
            empty = true;
        };
        void Sort()
        {
            for(int i = 0; i < length; i++)
                for(int j = i; j < length; j++)
                    if(Get(j) < Get(i))
                    {
                        DataType tmp = Get(i);
                        Get(i) = Get(j);
                        Get(i) = tmp;
                    };
        };
        DataType* GetPointer(int index)
        {
            if(index + 1 > length)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            if(index < 0)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            DataType* tmp;
            if(index == 0)
                tmp = FrontPointer();
            else
            {
                if(index == length - 1)
                    tmp = BackPointer();
                else
                    GetIndex(index)->GetPointer();
            };
            return tmp;
        };
        DataType Get(int index)
        {
            return *GetPointer(index);
        };
        DataType* BackPointer()
        {
            if(length < 1)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            return tail->GetPointer();
        };
        DataType Back()
        {
            return *BackPointer();
        };
        LinkedList<DataType>* GetSubList(int from, int to)
        {
            if(from + 1 > length)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            if(to + 1 > length)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            if(from < 0)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            if(to < 0)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            if(from > to)
            {
                try{
                    throw 1;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            LinkedList<DataType>* sublist = new LinkedList<DataType>();
            sublist->head = GetIndex(from);
            sublist->tail = GetIndex(to);
            sublist->length = to - from + 1;
            sublist->empty = false;
            return sublist;
        };
        DataType& operator[](const int index)
        {
            if(index + 1 > length)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            if(index < 0)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            return *GetPointer(index);
        };
        bool Empty()
        {
            return empty;
        };
        LinkedList<DataType>& operator+(const LinkedList<DataType>& list2)
        {
            Node<DataType>* tmp = list2.head;
            tmp->GetPrev() = tail;
            tail->SetNext() = tmp;
            tail = NULL;
            length += list2.length;
            if(length > 0)
                empty = false;
        }
        void operator+=(const Node<DataType>& node)
        {
            PushBack(node);
        };
        void operator-=(const int amount)
        {
            if(amount > length)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            for(int i = 0; i < amount; i++)
                PopBack();
        };

};

#endif // LINKELIST_H
