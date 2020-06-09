#pragma once
#ifndef TEST_H
#define TEST_H
#include "Check.h"
#include <iostream>
#include "TestFunctions.hpp"

using namespace std;

class Test
{
    private:
        void Realloc(int new_size)
        {
            TestFunction<Check>* tmp = (TestFunction<Check>*)malloc(new_size * el_size);
            memcpy(tmp, functions, count * el_size);
            free(functions);
            functions = tmp;
        };
        int el_size;
        int errors;
        string name;
        TestFunction<Check>* functions;
        int count;
    public:
        Test(string test_name)
        {
            name = test_name;
            count = 0;
            functions = 0;
            errors = 0;
            el_size = sizeof(TestFunction<Check>);
        };
        void AddTest(string func_name, Check(*const func)())
        {
            TestFunction<Check>* new_func = new TestFunction<Check>(func_name, func);
            Realloc(count + 1);
            memcpy(functions + count, new_func, el_size);
            count++;
        };
        void RunTests()
        {
            Check check;
            TestFunction<Check>* tmp;
            cout << "Testing " << name << "..." << endl;
            for(int i = 0; i < count; i++)
            {
                tmp = functions + i;
                check = tmp->function();
                cout << "   " << "test " << i + 1 << ": " << tmp->function_name << " - ";
                if(check == ERROR)
                {
                    errors++;
                    overall_errors++;
                    cout << "error" << endl;
                }
                else
                    cout << "no errors" << endl;
            };
            cout << "Errors found: " << errors << endl << "Test Finished." << endl << endl;
        };
};

#endif // TEST_H
