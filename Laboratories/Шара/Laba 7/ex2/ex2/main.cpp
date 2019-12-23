//
//  main.cpp
//  ex2
//
//  Created by Пушнова Алиса Сергеевна on 12/10/18.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.
//  Из естественной формы в прямой код

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int number;
    char element[20];
    
    cout << "Введите число в 10 ричной: ";
    cin >> number;
    cout << "Результат: ";
    
    if (number > 0) cout << "0";
    else cout << "1";
    
    int i = 0;
    
    while (number)
    {
        element[i] += (number % 2) + '0';
        number /= 2;
        i++;
    }
    
    while (i >= 0)
    {
        if (element[i] == '/') element[i] = '1';
        cout << element[i];
        i--;
    }
    
    cout << endl;
    return 0;
}
