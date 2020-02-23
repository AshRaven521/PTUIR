//
//  main.cpp
//  dop_1
//
//  Created by Пушнова Алиса Сергеевна on 28.09.2018.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, const char * argv[])
{
    int k, M;
    double y;
vvod:
    cout << "Введите четырехзначное число k=";
    cin >> k;
    
    if (k / 1000 > 9 || k / 1000 == 0)
    {
        cout << "!! Это не четырехзначное число !!" << endl;
        goto vvod;
    }
    else
    {
    M = (k % 10) + (k / 1000);
    switch (M)
    {
        case 3: y = pow(tan(k), 2) + (pow(sin(k), 2)) / 2.7;
        case 5:
        case 7: y = log(fabs(k-6));
        case 8:
        case 10: y = exp(0.2*k);
        default: y = k * (pow(sin(k), 2));
       
    }
    cout << "Значение у=" << y ;
    }
    
    return 0;
}
