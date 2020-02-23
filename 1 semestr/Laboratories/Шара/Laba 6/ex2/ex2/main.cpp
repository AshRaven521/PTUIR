//
//  main.cpp
//  ex2
//
//  Created by Пушнова Алиса Сергеевна on 11/24/18.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.
//  В тексте после указанного символа вставить подстроку.

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char s[80], sub[10], symbol, rez[80];
    cout << "Введите текст: ";
    cin.getline(s, 80);
    
    cout << "Введите подстроку: ";
    cin.getline(sub, 10);
    
    cout << "Введите символ: ";
    cin >> symbol;
    
    int i = 0, j = 0;
    for (; s[i] != '\0'; i++, j++)
    {
        if (s[i] == symbol)
        {
            rez[j] = symbol;
            for (int k = 0; sub[k] != '\0'; k++, j++)
                    rez[j + 1] = sub[k];
        }  else rez[j] = s[i];
    }
    rez[j] = '\0';
    
    cout << endl  << "Результат: " << rez << endl;
    return 0;
}

