//
//  main.cpp
//  ex3
//
//  Created by Пушнова Алиса Сергеевна on 11/25/18.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.
/*
 Имеется массив строк. На том же месте, не заводя других массивов, записать слова в обратном порядке, рассматривая все строки, т.е. первое слово первой строки станет последним словом последней строки
 (если объединить строки, будет гораздо проще). Стандартных функций работы со строками не использовать.
*/

#include <iostream>
#include <stdlib.h>

#define n 4

using namespace std;

void Display(char s[n][300])
{
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (s[i][j]) {
            cout << s[i][j];
            j++;
        }
        cout << "\n";
    }
}

int Length(char s[300])
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}

int WordsLeft(char s[300])
{
    int i = 0, j = 0;
    while (s[i]) {
        if (s[i] == ' ')
            j++;
        i++;
    }
    return j;
}

void ReverseWord(char c[], int l)
{
    for (int i = 1; i < l / 2. + .5; i++) {
        char tmp = c[i];
        c[i] = c[l - i];
        c[l - i] = tmp;
    }
}

int main()
{
    char s[n][300] = { "Don't blame me, love made me crazy", "If it doesn't, you ain't doin' it right",
        "Lord, save me, my drug is my baby", "I'd be usin' for the rest of my life" };

    Display(s);
    cout << "\n";
    for (int i = 0; i < n / 2; i++) {
        int amountOfShifts = 0, j = 0;
        while (j > -1) {
            int l = Length(s[i]), l1 = Length(s[n - i - 1]);
            j = l-1;
            char s1[300];
            s1[0] = ' ';
            while (j > -1 && s[i][j] != ' ') {
                s1[l - j] = s[i][j];
                j--;
            }
            if (j < 0) {
                j = 0;
                s[i][j] = 0;
                j = -1;
            }else
                s[i][j] = 0;
            ReverseWord(s1, l - j);
            for (int k = 0; k < l - j; k++) {
                s[n - i - 1][l1 + k] = s1[k];
            }
            amountOfShifts++;
        }
        while (WordsLeft(s[n - i - 1]) >= amountOfShifts) {
            int l = Length(s[i]), l1 = Length(s[n - i - 1]);
            int j = 0;
            char s1[300];
            while (s[n - i - 1][j] != ' ') {
                s1[j] = s[n - i - 1][j];
                j++;
            }
            s1[j] = ' ';
            for (int k = j + 1; k <= l1; k++)
                s[n - i - 1][k - j - 1] = s[n - i - 1][k];
            for (int k = l; k >= 0; k--)
                s[i][k + j + 1] = s[i][k];
            for (int k = 0; k <= j; k++)
                s[i][k] = s1[k];
            s[i][l+j+1] = 0;
        }
    }
    Display(s);
    return 0;
}
