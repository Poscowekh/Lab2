#pragma once
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <mem.h>
#include <stdlib.h>
#include "Exception.hpp"

using namespace std;

template <class DataType>
class DynamicArray
{
    private:
        int size;
        int element_size;
        bool empty;
        DataType* data;
        void Allocate(int new_size)
        {
            data = 0;
            size = new_size;
            data = (DataType*)malloc(element_size * size);
        };
        void Reallocate(int new_size)
        {
            size = new_size;
            DataType* tmp = NewDataPointer(size);
            memcpy(tmp, data, element_size * size);
            data = tmp;
        };
        DataType* NewDataPointer(int new_size)
        {
            DataType* tmp = (DataType*)malloc(element_size * new_size);
            return tmp;
        };
        void CheckEmpty()
        {
            if(size > 0)
                empty = false;
            else
                empty = true;
        };
        void CheckIndex(int index)
        {
            if(index < 0 || index + 1 > size)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
        };
        void CheckIndex(int index1, int index2)
        {
            if(index1 < 0 || index1 + 1 > size || index2 < 0 || index2 + 1 > size)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
        };
        void CheckNegative(int some)
        {
            if(some < 0)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
        };
        void CheckPointer(DataType* pointer)
        {
            if(pointer == 0)
            {
                try{
                    throw 2;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
        };
        DataType* GetPointer(int index)
        {
            CheckIndex(index);
            DataType* tmp = data + index;
            CheckPointer(tmp);
            return tmp;
        };
    public:
        DynamicArray()
        {
            element_size = sizeof(DataType);
            Allocate(0);
            empty = true;
        };
        DynamicArray(int new_size)
        {
            element_size = sizeof(DataType);
            Allocate(new_size);
            empty = true;
        };
        DynamicArray(DataType* new_data, int count)
        {
            CheckNegative(count);
            element_size = sizeof(DataType);
            Allocate(count);
            memcpy(data, new_data, element_size * size);
            CheckEmpty();
        };
        DynamicArray(const DynamicArray<DataType>& array)
        {
            element_size = array.element_size;
            Allocate(array.size);
            memcpy(data, array.data, element_size * size);
            CheckEmpty();
        };
        int GetSize()
        {
            return size;
        };
        int GetElementSize()
        {
            return element_size;
        };
        DataType Front()
        {
            CheckNegative(size - 1);
            CheckPointer(data);
            return *data;
        };
        DataType* DataPointer()
        {
            return data;
        };
        DataType Get(int index)
        {
            return *GetPointer(index);
        };
        DataType Back()
        {
            CheckNegative(size - 1);
            return GetPointer(size - 1);
        };
        void CopyToArray(DataType* new_data, int from, int count)
        {
            CheckIndex(from, count);
            if(from + count - 1 > size)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            int old_size = size;
            Reallocate(size + count);
            memcpy(data + old_size, new_data + from, element_size * count);
            CheckEmpty();
        };  
        void Set(int index, DataType* new_data)
        {   //One elememnt
            CheckIndex(index);
            memcpy(data + index, new_data, element_size);
            empty = false;
        };
        void Set(int index, DataType new_data)
        {
            Set(index, &new_data);
        };
        void PopBack()
        {
            CheckNegative(size - 1);
            Reallocate(size - 1);
            if(size == 0)
                empty = true;
        };
        void PushBack(DataType* new_data)
        {
            Reallocate(size + 1);
            memcpy(data + size - 1, new_data, element_size);
            empty = false;
        };
        void PushBack(DataType new_data)
        {
            PushBack(&new_data);
        };
        void PopFront()
        {
            CheckNegative(size - 1);
            DataType* tmp = NewDataPointer(size - 1);
            memcpy(tmp, data + 1, element_size * (size - 1));
            data = tmp;
            size--;
            if(size == 0)
                empty = true;
        };
        void PushFront(DataType* new_data)
        {
            DataType* tmp = NewDataPointer(size + 1);
            memcpy(tmp, new_data, element_size);
            memcpy(tmp + 1, data, element_size * size);
            data = tmp;
            size++;
            empty = false;
        };
        void PushFront(DataType new_data)
        {
            PushFront(&new_data);
        };
        void Resize(int new_size)
        {
            CheckNegative(new_size - 1);
            Reallocate(new_size);
            if(size == 0)
                empty = true;
        };
        void RemoveAt(int index)
        {
            CheckIndex(index);
            if(index == 0)
                PopFront();
            else
            {
                if(index == size - 1)
                    PopBack();
                else
                {
                    DataType* tmp = NewDataPointer(size - 1);
                    memcpy(tmp, data, index * element_size);
                    memcpy(tmp, data + index + 1, element_size * (size - index - 1));
                    data = tmp;
                    size--;
                };
            };
            if(size == 0)
                empty = true;
        };
        void InsertAt(DataType* new_data, int index)
        {
            CheckIndex(index);
            if(index == 0)
                PushFront(new_data);
            else
            {
                DataType* tmp = NewDataPointer(size + 1);
                memcpy(tmp, data, index * element_size);
                memcpy(tmp + index, new_data, element_size);
                memcpy(tmp + index + 1, data + index, element_size * (size - index - 1));
                data = tmp;
                size++;
            };
            empty = false;
        };
        void InsertAt(DataType new_data, int index)
        {
            InsertAt(&new_data, index);
        };
        void Clear()
        {
            data = 0;
            size = 0;
            empty = true;
        };
        void Sort()
        {
            for(int i = 0; i < size; i++)
                for(int j = 0; j < size - 1; j++)
                    if(Get(j) < Get(j + 1))
                    {
                        DataType tmp = Get(j);
                        Set(j, Get(j + 1));
                        Set(j + 1, tmp);
                    };
        };
        void ConcateTo(const DynamicArray<DataType>& array)
        {
            CopyToArray(array.data, 0, array.size);
        };
        void ConcateTo(const DynamicArray<DataType>& array1, const DynamicArray<DataType>& array2)
        {
            CopyToArray(array1.data, 0, array1.size);
            CopyToArray(array2.data, 0, array2.size);
        };
        DynamicArray<DataType>* ConcateThisTo(const DynamicArray<DataType>& array)
        {
            DynamicArray<DataType>* result = new DynamicArray<DataType>(this);
            result->CopyToArray(array.data, 0, array.size - 1);
            return result;
        };
        DynamicArray<DataType>* ConcateThisTo(const DynamicArray<DataType>& array1, const DynamicArray<DataType>& array2)
        {
            DynamicArray<DataType>* result = new DynamicArray<DataType>(this);
            result->CopyToArray(array1.data, 0, array1.size - 1);
            result->CopyToArray(array2.data, 0, array2.size - 1);
            return result;
        };
        DataType& operator[](const int index)
        {
            return *GetPointer(index);
        };
        DynamicArray<DataType>* GetSubArray(int from, int to)
        {
            CheckIndex(from, to);
            if(to - from + 1 > size)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            DynamicArray<DataType>* result = new DynamicArray<DataType>(data + from, to - from + 1);
            return result;
        };
        DynamicArray<DataType>* operator+(const DynamicArray<DataType>& array)
        {
            DynamicArray<DataType>* result = new DynamicArray<DataType>(this);
            result->Concate(array);
            return result;
        };
        DynamicArray<DataType>* operator+=(DataType new_data)
        {
            this->PushBack(new_data);
            return this;
        };
        DynamicArray<DataType>* operator+=(DataType* new_data)
        {
            return operator+=(&new_data);
        };
        DynamicArray<DataType>* operator-(int cut)
        {
            for(int i = 0; i < cut; i++)
                this->PopBack();
            return this;
        };
        DynamicArray<DataType>* operator--()
        {
            this->PopBack();
            return this;
        };
        bool operator==(const DynamicArray<DataType>& array)
        {
            if(size == 0 && array.size == 0)
                return true;
            if(size != array.size)
                return false;
            DataType* tmp1 = data;
            DataType* tmp2 = array.data;
            int count = 0;
            while(*tmp1 == *tmp2 && count < size)
            {
                tmp1 = tmp1 + 1;
                tmp2 = tmp2 + 1;
            };
            return (*tmp1 == *tmp2);
        };
        bool operator!=(const DynamicArray<DataType>& array)
        {
            return !(this == array);
        };
        bool operator>(const DynamicArray<DataType>& array)
        {
            return (size > array.size);
        };
        bool operator<(const DynamicArray<DataType>& array)
        {
            return (size < array.size);
        };
        bool operator>=(const DynamicArray<DataType>& array)
        {
            return (size >= array.size);
        };
        bool operator<=(const DynamicArray<DataType>& array)
        {
            return (size <= array.size);
        };
        bool Empty()
        {
            return empty;
        };
        ~DynamicArray(){};
};

#endif // DYNAMICARRAY_H
