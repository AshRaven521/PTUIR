//
//  main.cpp
//  dop3
//
//  Created by Пушнова Алиса Сергеевна on 12/13/18.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.
//

#include<iostream>
using namespace std;

int main()
{
    int n, answer[100], help = 0;
    cout << "Введите натуральное число n, 1 ≤ n ≤ 2*10^9 = ";
    cin >> n;
    
    while (n > 0)
        if (n % 3 == 0)
        {
            answer[help] = 3;
            n = int (n / 3) - 1;
            help++;
        }
        else
        {
            answer[help] = n % 3;
            help++;
            n = int(n / 3);
        }
    
    for (int i = help - 1; i >= 0; i--)
        cout << answer[i];
    
    cout << endl;

    return 0;
}
