//
//  main.cpp
//  ex2
//
//  Created by Пушнова Алиса Сергеевна on 02.10.2018.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int main ()
{
    double d, e = pow(10, -3), sum = 0;
    int n = 1;
    
    do
    {
        d = (1 / pow(2, n)) + (1 / pow(3, n));
        n++;
        sum += d;
    }
    while (d > e);
    
    cout << "Значение суммы ряда " << sum;
    return 0;
}
