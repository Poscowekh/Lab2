#ifndef LINKELIST_H
#define LINKELIST_H

using namespace std;

// LIST ELEMENT
template <class DataType>
class Node
{
    private:
        DataType* data;
        Node<DataType>* next;
    public:
        Node()
        {
            data = 0;
            next = 0;
        };
        Node(DataType* new_data)
        {
            data = new_data;
            next = 0;
        };
        Node(DataType* new_data, Node<DataType>* new_next)
        {
            data = new_data;
            next = new_next;
        };
        Node<DataType>* GetNext()
        {
            return next;
        };
        void SetNext(Node<DataType>* new_next)
        {
            next = new_next;
        };
        DataType Get()
        {
            return *data;
        };
        DataType* GetPointer()
        {
            return data;
        };
        void Set(DataType* new_data)
        {
            data = new_data;
        };
};

// LIST
template <class DataType>
class LinkedList
{
    private:
        int length;
        Node<DataType>* head;
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
        LinkedList(LinkedList<DataType>* list)
        {
            length = list->GetLength();
            for(int i = 0; i < length; i++)
                PushFront(list->GetPointer(i));
        };
        LinkedList(const LinkedList<DataType>& list)
        {
            //LinkedList<DataType>* tmp = list;
            length = list.GetLength();
            for(int i = 0; i < length; i++)
                PushBack(list.GetPointer(i));
        };
        void SetLength(int new_length)
        {
            length = new_length;
        };
        int GetLength()
        {
            return length;
        };
        void PopBack()
        {   //Exception length < 1
            if(length > 1)
                GetIndex(length - 2)->SetNext(0);
            else
                head = 0;
            length--;
        };
        void PushBack(DataType* new_data)
        {
            Node<DataType>* tmp = new Node<DataType>(new_data);
            if(length > 0)
                GetLast()->SetNext(tmp);
            else
                head = tmp;
            length++;
        };
        void PushBack(DataType new_data)
        {
            Node<DataType>* tmp = new Node<DataType>(&new_data);
            if(length > 0)
                GetLast()->SetNext(tmp);
            else
                head = tmp;
            length++;
        };
        void PopFront()
        {   //Exception length < 1
            head = head->GetNext();
            length--;
        };
        void PushFront(DataType* new_data)
        {
            Node<DataType>* tmp = new Node<DataType>(new_data);
            if(length != 0)
                tmp->SetNext(head);
            head = tmp;
            length++;
        };
        void PushFront(DataType new_data)
        {
            Node<DataType>* tmp = new Node<DataType>(&new_data);
            if(length != 0)
                tmp->SetNext(head);
            head = tmp;
            length++;
        };
        DataType Front()
        {
            return head->Get();
        };
        DataType* FrontPointer()
        {
            return head->GetPointer();
        };
        void Set(int index, DataType* data)
        {
            GetIndex(index)->Set(data);
        };
        void Set(int index, DataType data)
        {
            GetIndex(index)->Set(&data);
        };
        DataType Get(int index)
        {
            return GetIndex(index)->Get();
        };
        DataType* GetPointer(int index)
        {
            return GetIndex(index)->GetPointer();
        };
        DataType Back()
        {
            return GetLast()->Get();
        };
        DataType* BackPointer()
        {
            return GetLast()->GetPointer();
        };
        LinkedList<DataType>* GetSubList(int from, int to)
        {
            LinkedList<DataType>* sublist = new LinkedList<DataType>();
            for(int i = from; i <= to; i++)
                sublist->PushBack(GetPointer(i));
            return sublist;
        };
        DataType& operator[](int index)
        {
            return (this->GetIndex(index));
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
