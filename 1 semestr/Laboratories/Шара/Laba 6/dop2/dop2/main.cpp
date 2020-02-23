//
//  main.cpp
//  dop2
//
//  Created by Пушнова Алиса Сергеевна on 12/4/18.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int countVars(string, string, int L, int m);
bool ends(string, string);

int main()
{   int T;
    cout << "Enter T: ";
    cin >> T;
    int m, L;
    string s1, s2;
    for (int i = 0; i < T; i++) {
        cout << "\nEnter L: ";
        cin >> L;
        cout << "Enter m: ";
        cin >> m;
        cout << "\nEnter S1: ";
        cin >> s1;
        cout << "Enter S2: ";
        cin >> s2;
        cout << "Amount of variants: " << (countVars(s1, s2, L, m) + countVars(s2, s1, L, m)) % m;
    }
    return 0;
}

int countVars(string prefix, string suffix, int L, int m)
{
    int i = 1, min = (prefix.length() < suffix.length()) ? prefix.length() : suffix.length();
    
    while (i < min + 1 && !ends(prefix, suffix.substr(0, i)))
        i++;
    
    if (!ends(prefix, suffix.substr(0, i))) i = 0;
    
    int power = L - prefix.length() - suffix.length() + i;
    
    if (power < 0)
        return 0;
    
    return (int)(powl(26, power)) % m;
}

bool ends(string value, string ending)
{
    if (ending.size() > value.size()) return false;
    return equal(ending.rbegin(), ending.rend(), value.rbegin());
}
