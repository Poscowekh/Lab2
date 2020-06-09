#pragma once
#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

template<class DataType>
class Sequence
{
    public:
        virtual int GetLength() = 0;
        virtual DataType GetFirst() = 0;
        virtual DataType GetLast() = 0;
        virtual DataType Get(const int index) = 0;
        virtual Sequence<DataType>* GetSubsequence(const int from, const int to) = 0;
        virtual void Append(DataType data) = 0;    //to tail
        virtual void Prepend(DataType data) = 0;   //to first
        virtual void InsertAt(DataType data, const int index) = 0;
        virtual void RemoveAt(const int index) = 0;
        virtual void Clear() = 0;
        //virtual void Concate(Sequence<DataType>* other) = 0;
        virtual Sequence<DataType>* GetCopy() = 0;
        //virtual void CopyTo(Sequence<DataType>* to, int from_index, int to_index) = 0;
        virtual ~Sequence(){};
        virtual DataType& operator[](const int index) = 0;
};

#endif // SEQUENCE_HPP
