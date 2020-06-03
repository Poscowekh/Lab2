#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "Exception.hpp"

using namespace std;

template<class DataType>
class LinkedList
{
    private:
        typedef struct Node
        {
            DataType data;
            Node* prev;
            Node* next;
        } Node;
        Node* head;
        Node* tail;
        int length;
        bool empty;
        void CheckEmpty()
        {
            if(length > 0)
                empty = false;
            else
                empty = true;
        };
        void CheckIndex(int index)
        {
            if(index < 0 || index + 1 > length)
            {
                try {
                    throw 0;
                } catch(int code) {
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
        };
        void CheckIndex(int index1, int index2)
        {
            if(index1 < 0 || index1 + 1 > length || index2 < 0 || index2 + 1 > length)
            {
                try {
                    throw 0;
                } catch(int code) {
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
        };
        void CheckNegative(int some)
        {
            if(some < 0)
            {
                try {
                    throw 0;
                } catch(int code) {
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
        };
        void CheckLength()
        {
            if(length < 0)
            {
                try {
                    throw 1;
                } catch(int code) {
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
        };
        Node* GetPointer(int index)
        {
            CheckIndex(index);
            if(index > length / 2 && index > 3)
                return FromTail(index);
            else
                return FromHead(index);
        };
        Node* FromHead(int index)
        {
            Node* tmp = head;
            for(int i = 0; i < index; i++)
                tmp = tmp->next;
            return tmp;
        };
        Node* FromTail(int index)
        {
            Node* tmp = tail;
            for(int i = length; i > index; i--)
                tmp = tmp->prev;
            return tmp;
        };
        DataType& GetData(int index)
        {
            return GetPointer(index)->data;
        };
        void SwapElements(int index1, int index2)
        {
            DataType tmp = GetPointer(index1)->data;
            Set(index1, Get(index2));
            Set(index2, tmp);
        };
        LinkedList<DataType>* GetCopy()
        {
            LinkedList<DataType>* result = new LinkedList<DataType>();
            for(int i = 0; i < length; i++)
                result->PushBack(Get(i));
            return result;
        };
    public:
        LinkedList()
        {
            length = 0;
            head = 0;
            tail = 0;
            empty = false;
        };
        LinkedList(const LinkedList<DataType>& list)
        {
            head = 0;
            tail = 0;
            length = 0;
            Node* tmp = new Node;
            tmp->next = list.head;
            for(int i = 0; i < list.length; i++)
            {
                tmp = tmp->next;
                PushBack(tmp->data);
            };
        };
        LinkedList(DataType* data, int count)
        {
            head = 0;
            tail = 0;
            length = 0;
            CheckNegative(count);
            if(count > 0 && data != 0)
                for(int i = 0; i < count; i++)
                    PushBack(data + i);
            else
                LinkedList();
            CheckEmpty();
        };
        LinkedList(DataType* data, int from, int count)
        {
            CheckNegative(from);
            LinkedList(data + from, count);
        };
        void PushFront(DataType data)
        {
            Node* tmp = new Node;
            tmp->data = data;
            tmp->prev = 0;
            tmp->next = head;
            if(length == 0)
                tail = tmp;
            else
                head->prev = tmp;
            head = tmp;
            length++;
            empty = false;
        };
        void PushFront(DataType* data)
        {
            PushFront(*data);
        };
        void PushBack(DataType data)
        {
            Node* tmp = new Node;
            tmp->data = data;
            tmp->prev = tail;
            tmp->next = 0;
            if(length == 0)
                head = tmp;
            else
                tail->next = tmp;
            tail = tmp;
            length++;
            empty = false;
        };
        void PushBack(DataType* data)
        {
            PushBack(*data);
        };
        DataType Front()
        {
            CheckIndex(0);
            return head->data;
        };
        DataType Get(int index)
        {
            Node* tmp = head;
            for(int i = 0; i < index; i++)
                tmp = tmp->next;
            return tmp->data;
        };
        DataType Back()
        {
            CheckIndex(length - 1);
            return tail->data;
        };
        void Set(int index, DataType data)
        {
            CheckIndex(index);
            GetPointer(index)->data = data;
        };
        void Set(int index, DataType* data)
        {
            Set(index, *data);
        };
        int GetLength()
        {
            return length;
        };
        void PopBack()
        {
            CheckLength();
            if(length > 1)
            {
                tail->prev->next = 0;
                tail = tail->prev;
            }
            else
                head = tail = 0;
            length--;
            if(length == 0)
                empty = true;
        };
        void PopBack(int cut)
        {
            for(int i = 0; i < cut; i++)
                PopBack();
        };
        void PopFront()
        {
            CheckLength();
            if(length > 1)
            {
                head->next->prev = 0;
                head = head->next;
            }
            else
                head = tail = 0;
            length--;
            if(length == 0)
                empty = true;
        };
        void PopFront(int cut)
        {
            for(int i = 0; i < cut; i++)
                PopFront();
        };
        void Clear()
        {
            PopBack(length);
        };
        void InsertAt(int index, DataType data)
        {
            CheckIndex(index);
            if(index > 0)
            {
                Node* tmp = GetPointer(index);
                Node* new_node;
                new_node->data = data;
                new_node->next = tmp;
                new_node->prev = tmp->prev;
                new_node->prev->next = new_node;
                tmp->prev = new_node;
                length++;
                empty = false;
            }
            else
                PushFront(data);
        };
        void RemoveAt(int index)
        {
            CheckIndex(index);
            if(index == 0)
                PopFront();
            else
            {
                if(index == length - 1)
                    PopBack();
                else
                {
                    Node* tmp = GetPointer(index);
                    tmp->next->prev = tmp->prev;
                    tmp->prev->next = tmp->next;
                    delete tmp;
                    length--;
                };
            };
        };
        LinkedList<DataType>* GetSublist(int from, int to)
        {
            CheckIndex(from, to);
            CheckNegative(to - from);
            LinkedList<DataType>* result = new LinkedList<DataType>();
            result->head = GetPointer(from);
            result->tail = GetPointer(to + 1);
            result->head->prev = 0;
            result->tail->next = 0;
            result->length = to - from + 1;
            result->CheckEmpty();
            return result;
        };
        LinkedList<DataType>* Concate(const LinkedList<DataType>& list1, const LinkedList<DataType>& list2)
        {
            LinkedList<DataType>* result = new LinkedList<DataType>(list1);
            result->tail->next = list2.head;
            result->tail->next->prev = result->tail;
            //result->tail = list2.tail;
            result->length += list2.length;
            result->CheckEmpty();
            return result;
        };
        LinkedList<DataType>* ConcateFrom(const LinkedList<DataType>& list2)
        {
            return Concate(*this, list2);
        };
        void Sort()
        {
            CheckLength();
            for(int i = 0; i < length; i++)
                for(int j = 0; j < length - 1; j++)
                    if(Get(j) > Get(j + 1))
                        SwapElements(j, j + 1);
        };
        DataType& operator[](const int index)
        {
            return *GetPointer(index);
        };
        LinkedList<DataType>* GetSorted()
        {
            LinkedList<DataType>* result = new LinkedList<DataType>(*this);
            result->Sort();
            return result;
        };
        LinkedList<DataType>& operator+=(const DataType& data)
        {
            PopBack(data);
            return this;
        };
        LinkedList<DataType>& operator-=(const int cut)
        {
            PopBack(cut);
            return this;
        };
        LinkedList<DataType>& operator+(const LinkedList<DataType>& list)
        {
            return ConcateFrom(list);
        };
        bool operator<(const LinkedList<DataType>& list)
        {
            return (length < list.length);
        };
        bool operator>(const LinkedList<DataType>& list)
        {
            return (length < list.length);
        };
        bool operator==(const LinkedList<DataType>& list)
        {
            if(length == 0 && list.length == 0)
                return true;
            if(length != list.length)
                return false;
            Node* tmp1 = head;
            Node* tmp2 = list.head;
            while(tmp1->data == tmp2->data || tmp1 != 0)
            {
                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            };
            return (tmp1 == tmp2);

        };
        bool operator!=(const LinkedList<DataType>& list)
        {
            return !(this == list);
        };
        bool operator<=(const LinkedList<DataType>& list)
        {
            return (this == list || this < list);
        };
        bool operator>=(const LinkedList<DataType>& list)
        {
            return (this == list || this > list);
        };
        bool Empty()
        {
            return empty;
        };
        ~LinkedList(){};
};


#endif // LINKEDLIST_H
