//
//  main.cpp
//  zad2_v4
//
//  Created by Пушнова Алиса Сергеевна on 03.10.2018.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int main ()
{
    double fun, n, step, min = 100000;
    cout << "Вычисление минимального значения функции на промежутке [-2; 0]\n";
    
    do {
    cout << "\tНа сколько частей разделить область поиска корня? n=";
    cin >> n;
        
            if (n <= 0)
            {
                cout << "Неправильный ввод!!";
            }
        
        } while (n <= 0);
        
    step = 2.0 / n;
    cout << "Шаг функции " << step << "\n";
    
    double minx = 0;
    
    for (double x = -2; x <= 0; x += step)
    {
        fun = exp(x) - sin( cos(x) );
        fun = fabs(fun);
        
        if (fun < min)
        {
            min = fun;
            minx = x;
        }
    }
    
    cout << "Минимальное значение функции "<< min << "\n" ;
    cout << "Корень уравнения " << minx;
    return 0;
}
