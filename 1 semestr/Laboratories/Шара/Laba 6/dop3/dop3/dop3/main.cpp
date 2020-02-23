//
//  main.cpp
//  dop3
//
//  Created by Пушнова Алиса Сергеевна on 12/4/18.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int FindRepeat(char* s)
{
    int p = -1, i, j;
    for (i = 0; i < strlen(s); i++)
    {
        for (j = i + 1; j < strlen(s); j++)
        {
            if (s[i] == s[j])
            {
                p = i;
                break;
            }
        }
        if (p != -1)
            break;
    }
    return p;
}

long double fact(int count_of_letters)
{
    if(count_of_letters < 0)
        return 0;
    if (count_of_letters == 0)
        return 1;
    else
        return count_of_letters * fact(count_of_letters - 1); // делаем рекурсию.
}

long double fact2(int quantity)
{
    if(quantity < 0)
        return 0;
    if (quantity == 0)
        return 1;
    else
        return quantity * fact2(quantity - 1);
}

int main()
{
    char str[100];
    cout << "Введите текст: ";
    cin.getline(str, 100);

    int pos = FindRepeat(str);
    int quantity = 1;
    
    if (pos == -1)
        quantity = 0;
    else
        quantity++;
   
    int count_of_letters = strlen(str);
   
    double result;
    
    if (quantity == 0)
        result = fact(count_of_letters);
    else
        result = fact(count_of_letters) / fact2(quantity);

    cout << "Результат: " << result << endl;

    return 0;
}







