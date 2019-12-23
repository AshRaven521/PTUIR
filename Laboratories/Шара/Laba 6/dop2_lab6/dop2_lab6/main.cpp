//
//  main.cpp
//  dop2_lab6
//
//  Created by Пушнова Алиса Сергеевна on 12/5/18.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

int main()
{
    int g = 0;
    char s1[200], s2[200];
    int M, N;
    int long L, temp;
    cin >> N;
    do
    {
        cin >> L >> M;
        cin.get(s1, 200);
        cin.get(s2, 200);
        
        temp = L - strlen(s1) - strlen(s2);
        if (temp < 0)
        {
            cout << 1;
            continue;
        }
        int const n = 26;
        int step = pow(n, temp);
        int mod = (step % M) * 2;
        cout << mod << endl;
        g++;
    }
    while (g < N);
}
