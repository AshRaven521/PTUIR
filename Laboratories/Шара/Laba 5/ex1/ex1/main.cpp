//
//  main.cpp
//  ex1
//
//  Created by Пушнова Алиса Сергеевна on 11/2/18.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int array_size = 0;

double* generate_array(int n)
{
    double* array = new double[n]; // Создание динамического массива
    
    for (int i = 1; i <= n; i++)
    {
        if  (i <= 17)
        {
            array[i - 1] = ( 1.0 / tan(powl(i, 2)) );
        }
        else
        {
            array[i - 1] = sin(i);
        }
    }
    
    return array;
}

// функция для расчета суммы
double calculate_amount_of_array(double* array)
{
    double amount = 0;
    
    for (int i = 0; i < array_size; i++)
    {
        amount += array[i];
    }
    
    return amount;
}

// функция для d
double calculate_amount_of_squares(double* array, double m)
{
    double amount = 0;
    
    for (int i = 0; i < array_size; i++)
    {
        amount += powl((array[i] - m), 2);
    }
    
    return amount;
}

// функция для элмента массива
void write_array_to_console(double* array)
{
    cout << "Элементы массива: " << endl;
    
    for (int i = 0; i < array_size; i++)
    {
        cout << array[i] << ", ";
    }
    
    cout << endl;
}

// функция для вывода m и d
void write_m_and_D_to_console(double m, double D)
{
    cout << "Значение m = " << m << endl << "Значение D = " << D << endl << endl;
}

int get_n_from_console()
{
    cout << "Введите n = ";
    
    cin >> array_size;
    
    return array_size;
}

int main()
{
    int n = get_n_from_console();
    
    double* array = generate_array(n);
    
    double m = (1.0 / n) * calculate_amount_of_array(array);
    
    double D = (1.0 / n) * calculate_amount_of_squares(array, m);
    
    write_array_to_console(array);
    
    write_m_and_D_to_console(m, D);
    
    delete [] array; // очиска памяти
    
    return 0;
}


