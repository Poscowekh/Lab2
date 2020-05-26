#pragma once
#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <stdio.h>

using namespace std;

namespace Interface
{
    void Exit()
    {
        int choise;
        cout << "Exit?" << endl << "1 for yes, 0 for no" << endl;
        scnaf("%d", choise);
        if(choise != 0 && choise != 1)
        {
            cout << "Wrong, try again" << endl;
            Exit();
        };
    };

    void Clear()
    {
        printf("\e[1;1H\e[2J");
    };

    void StartUp()
    {
        int choise;
        cout << "Enter 0 for example" << endl;
        cout << "Enter 1 for tests" << endl;
        cout << "Enter 2 for manual input" << endl;
        scanf("%d", choise);
        if(choise > 2 || choise < 0)
        {
            cout << "Wrong, try again" << endl;
            Clear();
            StartUp();
        }
        else
            switch(choise)
            {
                case 0:

                    break;
                case 1:

                    break;
                case 2:

                    break;
            };
        Clear();
        Exit();
    };
};
#endif // INTERFACE_H
