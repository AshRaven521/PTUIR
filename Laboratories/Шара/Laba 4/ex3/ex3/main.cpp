//
//  main.cpp
//  ex3
//
//  Created by Пушнова Алиса Сергеевна on 20.10.2018.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.

// Дана вещественная матрица размером NxM. Упорядочить ее строки по возрастанию наибольших элементов в строках матрицы.

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int N, M, rez;
    cout << "Введите N=";
    cin >> N;
    cout << "Введите M=";
    cin >> M;
    cout << "Введите элементы матрицы:" << endl;
    
    int **mass = new int*[N];
    for (int i = 0; i < N; i++)
    {
        mass[i] = new int[M];
    }
    
    // ввод матрицы
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> mass[i][j];
        }
    }
    
    // решение
    for (int i = 0; i < N; i++)
    {
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = 0; j < M - 1; j++)
            {
                if (mass[i][j] > mass[i][j + 1])
                {
                    rez = mass[i][j];
                    mass[i][j] = mass[i][j + 1];
                    mass[i][j + 1] = rez;
                }
            }
        }
    }
    
    // вывод матрицы
    cout << "Исходная матрица:" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << mass[i][j] << "\t";
        }
        cout << endl;
    }
    
    // удаление
    for (int i = 0; i < N; i++)
    {
        delete[] mass[i];
    }
    delete[] mass;
    return 0;
}
