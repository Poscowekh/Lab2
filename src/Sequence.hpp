#pragma once
#ifndef SEQUENCE_H
#define SEQUENCE_H

template<class DataType>
class Sequence
{
    public:
        virtual DataType GetLength() const = 0;
        virtual DataType GetFirst() const = 0;
        virtual DataType GetLast() const = 0;
        virtual DataType Get(const int index) const = 0;
        virtual Sequence<DataType>* GetSubsequence(const int from, const int to) const = 0;
        virtual void Append(DataType data) = 0;    //to tail
        virtual void Prepend(DataType data) = 0;   //to first
        virtual void InsertAt(const int index, DataType data) = 0;
        virtual void RemoveAt(const int index) = 0;
        virtual void RemoveAll()  = 0;
        virtual void Concate(Sequence<DataType>* other) = 0;
        virtual Sequence<DataType>* GetCopy() = 0;
        virtual void CopyTo(Sequence<DataType>* to, int from_index, int to_index) = 0;
        virtual ~Sequence(){};
        virtual Sequence<DataType>* operator+(const Sequence<DataType>* other) = 0;
        virtual DataType& operator[](const int index) = 0;
};

#endif // SEQUENCE_H
