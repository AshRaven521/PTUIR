//
//  main.cpp
//  ex2
//
//  Created by Пушнова Алиса Сергеевна on 11/6/18.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "library_for_function.hpp"

using namespace std;

int main()
{
    srand (time(NULL));
    
    int N = 8;
    //cin >> N;
    
    double array[N];
    
    cout << "Элементы массива: ";
    
    for (int i = 0; i < N; i++)
    {
        array[i] = rand() % 10 + 1;
        cout  << array[i] << " ";
    }
    
    cout << "\nКоличество элементов массива, для которых выполняется условие: " << amount_of_elements_array(array, 0, N-1) << "\n";
    
    return 0;
}
