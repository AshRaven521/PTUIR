//
//  main.cpp
//  dop
//
//  Created by Пушнова Алиса Сергеевна on 12/12/18.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.
//

#include<iostream>

using namespace std;

int main()
{
    int number, help;
    cout << "Введите число: ";
    cin >> number;
    help = number;
    
    while (help > 0)
        help -= 3;
    
    if (help == 0)
        cout << "Число делится на " << "3" << endl;
    help = number;
    
    while (help > 0)
        help -= 61;
    
    if (help == 0)
        cout << "Число делится на " << "61" << endl;
    help = number;
    
    while (help > 0)
        help -= 131;
    
    if (help == 0)
        cout << "Число делится на " << "131" << endl;

    return 0;
}
