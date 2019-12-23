//
//  acount_of_integrals.cpp
//  library_integral
//
//  Created by Пушнова Алиса Сергеевна on 11/11/18.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.
//

#include "acount_of_integrals.hpp"
#include <math.h>
#include <iostream>
using namespace std;

double function1(double a, double b, double n)
{
    double h = (b - a) / n;
    
    double amount = 0;
    
    
    for (int i = 0; i < n - 1; i++)
    {
        double xi = a + (i * h) + (h / 2);
        
        double function1 = sqrt(1.5 * xi + 0.6) / (1.6 + sqrt(0.8 * powl(xi, 2) + 2));
        
        amount += function1;
    }
    double integral = h * amount;
    cout << "Интеграл 1 равен = " << integral << endl;
    
    return amount;
}

double function2(double a, double b, double n)
{
    double h = (b - a) / n;
    
    double amount = 0;
    
    
    for (int i = 0; i < n - 1; i++)
    {
        double xi = a + (i * h) + (h / 2);
        
        double function2 = cos(0.6 * powl(xi, 2) + 0.4) / (1.4 + powl(sin(xi + 0.7), 2));
        
        amount += function2;
    }
    double integral = h * amount;
    cout << "Интеграл 2 равен = " << integral << endl;
    
    return amount;
}

double function3(double a, double b, double n)
{
    double h = (b - a) / n;
    
    double amount = 0;
    
    for (int i = 0; i < n - 1; i++)
    {
        double xi = a + (i * h) + (h / 2);
        
        double function3 = 1.0 / sqrt(powl(xi, 2) + 1);
        
        amount += function3;
    }
    double integral = h * amount;
    cout << "Интеграл 3 равен = " << integral << endl;
    
    return amount;
}

double function4(double a, double b, double n)
{
    double h = (b - a) / n;
    
    double amount = 0;
    
    for (int i = 0; i < n - 1; i++)
    {
        double xi = a + (i * h) + (h / 2);
        
        double function4 = cos(xi) / (xi + 1);
        
        amount += function4;
    }
    double integral = h * amount;
    cout << "Интеграл 4 равен = " << integral << endl;
    
    return amount;
}

