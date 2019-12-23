//
//  main.cpp
//  ex3
//
//  Created by Пушнова Алиса Сергеевна on 01.10.2018.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main ()
{
    cout << "Подсчет значения функции:" << "\n";
    int  A = 0, M = 20;
    double y, x = 0.0, B = M_PI / 2, H = (B - A) / M;
    cout << "x" << "\t\t\t" << "y" << "\n";
    
    for (double i = 0; x <= B && x >= A; i++)
    {
        x = A + i * H;
        y = sin(x) - cos(x);
        cout << floor(x * 100) / 100 << "\t\t" << floor(y * 100) / 100 << "\n";
    }
    return 0;
}
