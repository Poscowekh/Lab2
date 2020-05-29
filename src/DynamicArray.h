#pragma once
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <mem.h>
#include <stdlib.h>
#include "Exception.h"

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
            size = new_size;
            data = (DataType*)malloc(element_size * size);
        };
        void Reallocate(int new_size)
        {
            size = new_size;
            DataType* tmp = (DataType*)malloc(element_size * size);
            memcpy(tmp, data, element_size * size);
            data = tmp;
        };
        DataType* NewDataPointer(int new_size)
        {
            DataType* tmp = (DataType*)malloc(element_size * new_size);
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
            size = count;
            element_size = sizeof(DataType);
            if(count < 1)
            {
                try{
                    throw 1;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            data = (DataType*)malloc(element_size * size);
            memcpy(data, new_data, element_size * size);
            if(size > 0)
                empty = false;
            else
                empty = true;
        };
        DynamicArray(const DynamicArray<DataType> &array)
        {
            element_size = array.element_size;
            size = array.size;
            data = (DataType*)malloc(element_size * size);
            memcpy(data, array.data, element_size * size);
            if(size > 0)
                empty = false;
            else
                empty = true;
        };
        int GetSize()
        {
            return size;
        };
        int GetElementSize()
        {
            return element_size;
        };
        DataType* FrontPointer()
        {
            if(size < 1)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            if(data == 0)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            return data;
        };
        DataType Front()
        {
            return *FrontPointer();
        };
        DataType* GetPointer(int index)
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
            if(index + 1 > size)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            DataType* tmp = data + index;
            if(tmp == 0)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            return tmp;
        };
        DataType Get(int index)
        {
            return *GetPointer(index);
        };
        DataType* BackPointer()
        {
            if(size < 0)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            return GetPointer(size - 1);
        };
        DataType Back()
        {
            return *BackPointer();
        };
        void CopyToArray(DataType* new_data, int from, int count)
        {
            if(from < 0)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            if(from + 1 > size)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            if(count < 0)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            if(from + 1 > size)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            if(from + count - 1 > size )
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            int old_size = size;
            Reallocate(count + size);
            memcpy(data + old_size, new_data, element_size * count);
            if(size > 0)
                empty = false;
            else
                empty = true;
        };  
        void Set(int index, DataType* new_data)
        {   //One elememnt
            if(index < 0)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            if(index + 1 > size)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            data + index = new_data;
            empty = false;
        };
        void Set(int index, DataType new_data)
        {
            Set(index, &new_data);
        };
        void PopBack()
        {
            if(size < 1)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
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
            if(size < 1)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
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
            if(new_size < 1)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            Reallocate(new_size);
            if(size == 0)
                empty = true;
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
            if(index + 1 > size)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            DataType* tmp = NewDataPointer(size - 1);
            if(index == 0)
                PopFront();
            else
            {
                if(index == size - 1)
                    PopBack();
                else
                {
                    memcpy(tmp, data, index * element_size);
                    memcpy(tmp, data + index + 1, element_size * (size - index));
                    data = tmp;
                    size--;
                };
            };
            if(size == 0)
                empty = true;
        };
        void InsertAt(DataType* new_data, int index)
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
            if(index + 1 > size)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            if(index == 0)
                PushFront(new_data);
            else
            {
                DataType* tmp = NewDataPointer(size + 1);
                memcpy(tmp, data, index * element_size);
                memcpy(tmp + index, new_data, element_size);
                memcpy(tmp + index + 1, data + index, element_size * (size - index));
                data = tmp;
                size++;
            };
            empty = false;
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
                for(int j = i; j < size; j++)
                    if(Get(j) < Get(i))
                    {
                        DataType tmp = Get(i);
                        Get(i) = Get(j);
                        Get(j) = tmp;
                    };
        };
        DataType& operator[](const int index)
        {
            return *GetPointer(index);
        };
        DynamicArray<DataType>* GetSubArray(int from, int to)
        {
            if(from < 0)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            if(from + 1 > size)
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
            if(to + 1 > size)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            if(from > size)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            if(from + to - 1 > size)
            {
                try{
                    throw 0;
                } catch(int code){
                    Exception* a = new Exception(code);
                    delete a;
                };
            };
            DynamicArray<DataType>* result = new DynamicArray<DataType>();
            CopyToArray(data, from, from - to + 1);
            return result;
        };
        bool Empty()
        {
            return empty;
        };
};

#endif // DYNAMICARRAY_H
