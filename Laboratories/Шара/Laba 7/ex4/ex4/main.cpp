//
//  main.cpp
//  ex4
//
//  Created by Пушнова Алиса Сергеевна on 12/12/18.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
char *sub(char m[10], char p[10])
{
    int i;
    bool s = 0;
    i = strlen(m) - 1;
    char *f = new char[i];
    for (; i >= 0; i--)
    {
        bool d = 0, h = 0;
        if (m[i] == 'a')
        {
            m[i] = '9';
            d = 1;
        }
        if (p[i] == 'a')
        {
            p[i] = '9';
            h = 1;
        }
        if (s)
            m[i] = (m[i] - '0' - 1) + '0';
        if ((m[i] - '0' + d) - (p[i] - '0' + h) == 10)
        {
            f[i] = 'a';
            s = 0;
        }
        else if ((m[i] - '0' + d) - (p[i] - '0' + h) < 0)
        {
            if ((m[i] - '0' + d + 11) - (p[i] - '0' + h) == 10)
                f[i] = 'a';
            else f[i] = ((m[i] - '0' + d + 11) - (p[i] - '0' + h)) + '0';
            s = 1;
        }
        else
        {
            f[i] = ((m[i] - '0' + d) - (p[i] - '0' + h)) + '0';
            s = 0;
        }
        
    }
    f[strlen(p)] = '\0';
    return f;
}

char *sum(char m[10], char p[10])
{
    int i;
    bool s = 0;
    i = strlen(m) - 1;
    char *f = new char[i];
    for (; i >= 0; i--)
    {
        bool d = 0, h = 0;
        if (m[i] == 'a')
        {
            m[i] = '9';
            d = 1;
        }
        if (p[i] == 'a')
        {
            p[i] = '9';
            h = 1;
        }
        if (s)
            p[i] = (p[i] - '0' + 1)+'0';
        if ((m[i] - '0'+d) + (p[i] - '0'+h) == 21)
        {
            f[i] = 'a';
            s = 1;
        }
        else if ((m[i] - '0' + d) + (p[i] - '0' + h) == 10)
        {
            f[i] = 'a';
            s = 0;
        }
        else if ((m[i] - '0'+d) + (p[i] - '0'+h) > 10)
        {
            f[i] = (((m[i] - '0'+d) + (p[i] - '0'+h)) - 11) + '0';
            s = 1;
        }
        else
        {
            f[i] = ((m[i] - '0' + d) + (p[i] - '0' + h)) + '0';
            s = 1;
        }
    }
    f[strlen(p)] = '\0';
    return f;
}

int main()
{
    char m[10], p[10];
    char a;
    char *sume;
    cout << "Введите первое число = ";
    cin.getline(m, 10);
    cout << "Введите второе число = ";
    cin.getline(p, 10);
    cout << "Введите знак операции + (сложение) - (вычитание) = ";
    cin >> a;
    cout << endl;
    cout << endl;
    
    if (m[0] != '-' && p[0] != '-' && a == '+')
    {
        sume = sum(m, p);
        cout << "Результат: " << sume << endl;
    }
    else if (m[0] != '-' && p[0] != '-'&& a == '-')
    {
        sume = sub(m, p);
        cout << "Результат: " << sume << endl;
    }
    else if (m[0] == '-' && p[0] == '-'&& a == '+')
    {
        for (int i = 0; i < strlen(m); i++)
            m[i] = m[i + 1];
        for (int i = 0; i < strlen(p); i++)
            p[i] = p[i + 1];
        sume = sum(m, p);
        cout << "Результат: " << '-' << sume << endl;
    }
    else if (m[0] != '-' && p[0] == '-'&& a == '+')
    {
        for (int i = 0; i < strlen(p); i++)
            p[i] = p[i + 1];
        sume = sub(m, p);
       cout << "Результат: " << sume << endl;
    }
    else if (m[0] == '-' && p[0] != '-'&& a == '+')
    {
        for (int i = 0; i < strlen(m); i++)
            m[i] = m[i + 1];
        sume = sub(p, m);
        cout << "Результат: " << sume << endl;
    }
    else if (m[0] == '-' && p[0] == '-'&& a == '-')
    {
        for (int i = 0; i < strlen(m); i++)
            m[i] = m[i + 1];
        for (int i = 0; i < strlen(p); i++)
            p[i] = p[i + 1];
        sume = sub(p, m);
        cout << "Результат: " << sume << endl;
    }
    else if (m[0] == '-' && p[0] != '-'&& a == '-')
    {
        for (int i = 0; i < strlen(m); i++)
            m[i] = m[i + 1];
        sume = sum(m, p);
        cout << "Результат: " << '-' << sume << endl;
    }
    else if(m[0] != '-' && p[0] == '-'&& a == '-')
    {
        for (int i = 0; i < strlen(p); i++)
            p[i] = p[i + 1];
        sume = sum(m, p);
        cout << "Результат: " << sume << endl;
    }
}
