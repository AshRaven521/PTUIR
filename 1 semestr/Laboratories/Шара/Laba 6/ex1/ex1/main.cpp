//
//  main.cpp
//  ex1
//
//  Created by Пушнова Алиса Сергеевна on 11/22/18.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    char str[81] = "0100000111111110000111111000001111110001011111111\0";
    cout << "Введенная строка: " << str << endl << endl;
    
    cout << "Группы с четным количеством символов: ";
    for (int i = 0; str[i] != '\0'; i++)
    {
        int first_element = i;
        
        while (str[i] == str[i + 1])
            i++;
        
            if ( (i - first_element) % 2 )
            {
                for (int last_element = first_element; last_element <= i; last_element ++)
                {
                    cout << str[last_element];
                }
                cout << ", " << "\t";
            }
    }
    return 0;
}






























