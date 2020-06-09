#pragma once
#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>

using namespace std;        //Project Specific

class Exception
{
    public:
        Exception(const int code)
        {
            switch(code)
            {
                case 0:
                    cout << "Error code 0: Index out of range!" << endl;
                    exit(code + 1000);
                break;
                case 1:
                    cout << "Error code 1: Wrong Length!" << endl;
                    exit(code + 1000);
                break;
                case 2:
                    cout << "Error code 2: Null pointer!" << endl;
                    exit(code + 1000);
                break;
            };
        };
};

#endif // EXCEPTION_H
