//
//  main.cpp
//  ex_1
//
//  Created by Пушнова Алиса Сергеевна on 12/10/18.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int ten = 0;
    int element_a = 0;
    string number;
    cout << "Введите число в 11-ричной: ";
    getline(cin, number);
    int size = number.length();
    
    for (int i = 0, last_element = size - 1; static_cast<void>((i < size)), last_element >= 0; last_element--, i++)
    {
        if (number[i] == 'a' || number[i] == 'A')
            element_a = 10 * powl(11, last_element);
        else
            element_a = (number[i] - '0') * powl(11, last_element);
        ten += element_a;
    }
    cout << "Число в 10-ричной = " << ten << endl;
    
    int result = 0;
    
    for (int i = 0; ten > 0; i++)
    {
        result += (ten % 7) * pow(10, i);
        ten /= 7;
    }
    cout << "Число в 7-ричной = " << result << endl;
    
    return 0;
}
