//
//  main.cpp
//  ex_3
//
//  Created by Пушнова Алиса Сергеевна on 12/5/18.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.

/* Осуществить сложение чисел. Разработать функции для выполнения операции сложения. Предусмотреть ввод положительных и отрицательных чисел. Найдите сумму двоичных чисел, заданных в естественной форме. Сложение выполните в обратном коде. Ответ выразите в прямом коде. */

#include <iostream>
using namespace std;

int invers(int i)
{
    if ( i == 0 )
        return 1;
    else return 0;
}

int main()
{
    char str[9];
    int mas[8] = {0,0,0,0,0,0,0,0}, masobr[8] = {0,0,0,0,0,0,0,0}, masobr2[8] = {0,0,0,0,0,0,0,0}, per = 0,
    preriv = 0, size;
    bool Bool = true, Bool2 = true, Bool3 = true;
    while(preriv < 2)
    {
    cout << "Введите число с учетом того, что первый символ (+/-) определяет его знак: ";
    cin >> str;
        size = 7;
        for (long int i = strlen(str) - 1; i > 0; i--)
        {
            mas[size] = str[i] - '0';
            if(str[0] == '+')
            {
                masobr[0] = 0;
                masobr[size] = mas[size];
            }
            else
            {
                if (Bool3)
                {
                    for (int i = 0; i < 8; i++) masobr[i] = 1;
                    Bool3 = false;
                }
                masobr[size] = invers(mas[size]);
                if (Bool2)
                {
                    if (masobr[size] == 0)
                    {
                        per = size;
                        Bool2 = false;
                    }
                }
                
                if (i == 1)
                {
                    masobr[per] = 1;
                    for (int j = 7; j > per; j--) masobr[j] = 0;
                }
            }
            size--;
        }
    
        for (int i = 0; i < 8; i++)
            cout  <<  masobr[i];
            if (Bool)
            {
                for(int i = 0; i < 8; i++)
                {
                    masobr2[i] = masobr[i];
                }
                Bool = false;
                for(int i = 0; i < 8; i++)
                    masobr[i] = 0;
            }
        cout << endl;
        preriv++;
        Bool2 = true;
        Bool3 = true;
    }
    
    Bool = true;
    for(int i = 7; i >= 0; i--)
    {
        Bool2 = true;
        if (Bool && Bool2)
        {
            if (masobr2[i] + masobr[i] == 0);
            else if (masobr2[i] + masobr[i] == 1) masobr2[i] = 1;
            else if (masobr2[i] + masobr[i] == 2)
            {
                Bool = false;
                masobr2[i] = 0;
            }
            Bool2 = false;
        }
        if (!Bool && Bool2)
        {
            if (masobr2[i] + masobr[i] == 0)
            {
                masobr2[i] = 1;
                Bool = true;
            }
            else if (masobr2[i] + masobr[i] == 1) masobr2[i] = 0;
            else if (masobr2[i] + masobr[i] == 2)masobr2[i] = 1;
        }
        
    }
    cout << endl;
    Bool = 1;
    if (masobr2[0] == 0)
    {
        cout << "Положительное значение: " << "+";
        for (int i = 0; i < 8; i++)
        {
            if ((masobr2[i]) == 0 && Bool);
        else
        {
            Bool = 0;
            cout << (masobr2[i]);
        }
        }
    }
    
    if (masobr2[0] == 1)
    {
        cout << "Отрицательное значение: " << "-";
        int i = 0;
        while (i <= 7)
        {
            masobr2[i] = 1;
            i++;
        }
        cout << masobr2[0];
        Bool = 1;
        for (int j = 1; j < 8; j++)
        {
            if (invers(masobr2[j]) == 0 && Bool);
            else
            {
                Bool = 0;
                cout  <<  invers(masobr2[j]);
            }
        }
    }
    cout << endl;
}
