//
//  main.cpp
//  dop_1
//
//  Created by Пушнова Алиса Сергеевна on 10/20/18.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.
//  Даны две действительные квадратные матрицы порядка n. Получить новую матрицу умножением элементов каждой строки первой матрицы на наибольшее из значений элементов соответствующей строки второй матрицы.

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int N;
    cout << "Первая матрица:" << endl;
    cout << "Введите N=";
    cin >> N;
    
    cout << "Введите элементы матрицы:" << endl;
    double **mass = new double*[N];
    for (int i = 0; i < N; i++)
    {
        mass[i] = new double[N];
    }
    
    // ввод 1 матрицы
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> mass[i][j];
        }
    }
    
    cout << "Введите элементы второй матрицы:" << endl;
    double **matr = new double*[N];
    for (int a = 0; a < N; a++)
    {
        matr[a] = new double[N];
    }
    
    // ввод 2 матрицы
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> matr[i][j];
        }
    }
    
    // нахождение наибольшего элемента строки 2 матрицы
    double temp = matr[0][0], max;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (matr[i][j] >= temp)
            {
                max = matr[i][j];
            }
            temp = matr[i][j];
        }
        
        for (int j = 0; j < N; j++)
        {
            mass[i][j] *= max;
        }
    }
    
    // вывод матрицы
    cout << "Результат матрицы:" << "\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
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
    
    // удаление
    for (int a = 0; a < N; a++)
    {
        delete[] matr[a];
    }
    delete[] matr;
    
    return 0;
}
