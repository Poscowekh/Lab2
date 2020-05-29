#include "Example.hpp"
#include "Interface.hpp"
#include "Tests.hpp"
#include <time.h>

//map, where, reduce for deck

using namespace std;
int main()
{
    DynamicArray<int>* ar = IntArray(time(NULL), 4);
    cout << ar->Get(0) << endl;
    LinkedList<int>* li = new LinkedList<int>();
    //for(int i = 0; i < li->GetLength(); i++)
    //    cout << li->Get(i) << endl;
    li->PushBack(ar->Get(0));
    cout << li->Get(0);
    //Example();
    //test_main();
    return 0;
}
