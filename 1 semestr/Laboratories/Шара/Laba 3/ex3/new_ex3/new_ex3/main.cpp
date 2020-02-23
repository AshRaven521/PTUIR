#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main ()
{
    cout << "Подсчет значения функции:" << "\n";
    int  A = 0, M = 20;
    double y, x = 0.0, B = M_PI / 2.0, H = (B - A) / M;
    cout << "x" << "\t\t\t" << "y" << "\n";
    
    for (double i = 0; x < B && x >= A; i++) // исправила, что x < B, а было X <= B
    {
        x = A + i * H;
        y = sin(x) - cos(x);
        cout << floor(x * 100) / 100 << "\t\t" << floor(y * 100) / 100 << "\n";
    }
    return 0;
}
