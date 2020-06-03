#pragma once
#include <iostream>
#include <stdio.h>
#include "Example.hpp"
#include "Tests.hpp"

using namespace std;

void StartMenu()
{
    int choise = -1;
    cout << "Choose option:" << endl;
    cout << "   Enter '0' to exit:" << endl;
    cout << "   Enter '1' for examle:" << endl;
    cout << "   Enter '2' for tests:" << endl;
    cout << "   Enter '3' for manual input:" << endl;
    cin >> choise;
    switch(choise)
    {
        case 0:
            exit(0);
        break;
        case 1:
            Example();
            StartMenu();
        break;
        case 2:
            test_main();
            StartMenu();
        break;
        case 3:

        break;
        cout << "Wrong input" << endl;
        StartMenu();
        break;
    };
};
