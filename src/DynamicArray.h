#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <mem.h>
#include <stdlib.h>

using namespace std;

template <class DataType>
class DynamicArray
{
    private:
        int size;
        int element_size;
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
        };
        DynamicArray(int new_size)
        {
            element_size = sizeof(DataType);
            Allocate(new_size);
        };
        DynamicArray(DynamicArray<DataType>* array)
        {
            element_size = array->GetElementSize();
            Reallocate(array->GetSize());
            memcpy(data, array->GetPointer(0), element_size * size);
        }
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
            return *data;
        };
        DataType* FrontPointer()
        {
            return data;
        };
        DataType Get(int index)
        {
            DataType* tmp = data + index;
            return *tmp;
        };
        DataType* GetPointer(int index)
        {
            DataType* tmp = data + index;
            return tmp;
        };
        DataType Back()
        {
            return Get(size - 1);
        };
        DataType* BackPointer()
        {
            return GetPointer(size - 1);
        };
        void CopyArray(DataType* new_data, int from, int count)
        {
            Reallocate(count - from + 1);
            for(int i = 0; i < size; i++)
                memcpy(data + i, new_data + i, element_size);
        };
        void Set(int index, DataType new_data)
        {   //One elememnt
            //memcpy(data + index, &new_data, element_size);
            data + index = &new_data;
        };
        void PopBack()
        {
            Reallocate(size - 1);
        };
        void PushBack(DataType* new_data)
        {
            Reallocate(size + 1);
            memcpy(data + size - 1, new_data, element_size);
        };
        void PushBack(DataType new_data)
        {
            Reallocate(size + 1);
            memcpy(data + size - 1, &new_data, element_size);
        };
        void PopFront()
        {
            DataType* tmp = NewDataPointer(size - 1);
            memcpy(tmp, data + 1, element_size * (size - 1));
            data = tmp;
            size--;
        };
        void PushFront(DataType* new_data)
        {
            DataType* tmp = NewDataPointer(size + 1);
            memcpy(tmp + 1, data, element_size * size);
            memcpy(tmp, new_data, element_size);
            data = tmp;
            size++;
        };
        void PushFront(DataType new_data)
        {
            DataType* tmp = NewDataPointer(size + 1);
            memcpy(tmp + 1, data, element_size * size);
            memcpy(tmp, &new_data, element_size);
            data = tmp;
            size++;
        };
};
/*Создание объекта
DynamicArray(T* items, int count); Копировать элементы из
переданного массива
DynamicArray(int size); Создать массив заданной длины
DynamicArray(DynamicArray<T> & dynamicArray const); Копирующий конструктор

Декомпозиция
T Get(int index);
Может выбрасывать исключения:
− IndexOutOfRange (если индекс отрицательный, больше/равен числу
элементов или указывает на не заданный элемент)
Получить элемент по индексу.
int GetSize(); Получить размер массива
Операции

void Set(int index, T value); Задать элемент по индексу
3
Может выбросить
IndexOutOfRange
void Resize(int newSize); Изменить размер массива. Если
размер увеличивается, все
элементы копируются в начало
новой памяти. Если уменьшается
– элементы, которые не
помещаются, отбрасываются.*/

#endif // DYNAMICARRAY_H
