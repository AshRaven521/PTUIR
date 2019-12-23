//
//  main.cpp
//  dop_2
//
//  Created by Пушнова Алиса Сергеевна on 28.09.2018.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int main ()

{
   double a, b, c, x, y;
    
    cout << "Введите размеры кирпича: " << endl;
    cout << "a=";
    cin >> a;
    cout << "b=";
    cin >> b;
    cout << "c=";
    cin >> c;
    
    cout << "Введите размеры отверстия: " << endl;
    cout << "x=";
    cin >> x;
    cout << "y=";
    cin >> y;
    
    if (a > 0 && b > 0 && c > 0 && x > 0 && y > 0)
    {
        if (x >= a || (y >= a && x >= b) || (y >= b && x >= c) || y >= c)
        {
          cout << "Кирпич пройдет в отверстие!";
        }
        else
        {
          cout << "Кирпич НЕ пройдет в отверстие!";
        }
    }
    else
    {
        cout << "Это невозможно" ;
    }
    return 0;
}
