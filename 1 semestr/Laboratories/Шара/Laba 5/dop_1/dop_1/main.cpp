//
//  main.cpp
//  dop_1
//
//  Created by Пушнова Алиса Сергеевна on 11/13/18.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

void mass(int** array, int n, int k)
{
    int i, j;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < k; j++)
        {
            array[i][j] = rand() % 10 + 1;
        }
    }
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
}

void mainpart(int** arr, int* ar, int  n, int k)
{
    int i, j, l;
    int result = 1;
    for (i = 0, l = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            if (i == j)
            {
                if (arr[i][j] % 2 == 0)
                {
                    ar[l++] = arr[i][j];
                }
            }
        }
        
    }
    
    cout << "Подходящие элементы: ";
    for (i = 0; i < l; i++)
    {
         cout << ar[i] << "\t";
    }
    for (int i = 0; i < l; i++)
    {
        result = result * ar[i];
    }
    cout << "\nРезультат произведения = " << result << endl;
}

int main()
{
    int n, k, i;
    cout << "Введите n=";
    cin >> n;
    cout << "Введите k=";
    cin >> k;
    
    int** arr = new int*[n];
    for ( i = 0; i < n; i++)
    {
        arr[i] = new int[k];
    }
    
    int* ar = new int;
    mass(arr, n, k);
    mainpart(arr, ar, n, k);
    for (i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    delete ar;
}





