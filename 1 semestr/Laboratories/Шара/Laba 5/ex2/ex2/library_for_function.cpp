//
//  library_for_function.cpp
//  ex2
//
//  Created by Пушнова Алиса Сергеевна on 11/7/18.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.
//

#include <math.h>
#include "library_for_function.hpp"

int amount_of_elements_array(double array[], int one_element, int N)
{
    if (N == one_element)
    {
        if (sin(array[N] / 2) < 0)
            return 1;
        return 0;
    }
    else return amount_of_elements_array(array, one_element, (N + one_element) / 2) +
        amount_of_elements_array(array, (N + one_element) / 2 + 1, N);
}
