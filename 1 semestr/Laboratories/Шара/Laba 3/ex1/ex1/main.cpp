//
//  main.cpp
//  ex1
//
//  Created by Пушнова Алиса Сергеевна on 01.10.2018.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int main ()
{
    double N, a, b, sum = 0;
    int i = 1;
    while (i <= 30)
    {
        if (i % 2 == 0) a = i / 2;
            else a = i;
        if (i % 2 == 0) b = pow(i, 3);
            else b = pow(i, 2);
    
    N = pow ((a - b), 2);
    sum += N;
        i++;
    }
    cout << "Значение выражения N=" << sum << endl;
    return 0;
}
