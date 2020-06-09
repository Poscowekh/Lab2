#pragma once
#include "../Structures/Result/Deque.hpp"
#include "../Utility/Randomization/RandomGen.hpp"
#include "../Utility/UtilityFunctions/Functions.hpp"
#include <time.h>

using namespace std;

int RandomSeed(int seed)
{
    seed += RandomInt(seed);
    seed -= RandomInt(seed);
    return seed;
};

//MAIN EXAMPLE
void Example()
{
    int seed = RandomSeed(time(NULL));
    int size = rand() % 5 + 7;
    seed = RandomSeed(seed);
    DynamicArray<int>* array = IntArray(seed, size);
    seed = RandomSeed(seed);
    cout << "RANDOM DEQUE" << endl;
    Deque<int>* deque1 = new Deque<int>(array);
    deque1->PrintDeque();
    getchar();
    cout << "DEQUE - COPY" << endl;
    Deque<int>* deque2 = new Deque<int>(*deque1);
    deque2->PrintDeque();
    getchar();
    deque1->PopBack();
    deque1->PopFront();
    seed = RandomSeed(seed);
    deque1->PushBack(RandomInt(seed));
    seed = RandomSeed(seed);
    deque1->PushFront(RandomInt(seed));
    cout << "DEQUE - POP & PUSH" << endl;
    deque1->PrintDeque();
    getchar();
    cout << "DEQUE - Sort" << endl;
    deque2 = Sort(deque1);
    deque2->PrintDeque();
    getchar();
    cout << "DEQUE - MAP" << endl;
    deque2 = Map(deque2, [](int x){ return x % 100; });
    deque2->PrintDeque();
    getchar();
    cout << "DEQUE - WHERE" << endl;
    deque2 = Where(deque1, [](int x){ return x < 0; });
    deque2->PrintDeque();
    getchar();
    int sum = 0;
    for(int i = 0; i < deque1->GetLength(); i++)
        sum += deque1->Get(i);
    int y = Reduce(deque1, [](int x1, int x2){ return x1 + x2; }, 0);
    cout << "DEQUE - REDUCE" << endl << y << " = " << sum << endl << endl;
    getchar();
    cout << "DEQUE - SUBDECK 2 TO 5" << endl;
    deque2 = deque1->SubDeck(2, 5);
    deque2->PrintDeque();
    getchar();
    cout << "DEQUE - CONCATE" << endl;
    deque2->Concate(deque1);
    deque2->PrintDeque();
    delete array;
    delete deque1;
    delete deque2;
};
