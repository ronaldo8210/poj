#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int f0, f1, f2, f3, f4, f5, A, B, C;
    while (cin >> f0 >> f1 >> f2)
    {
        C = f0;
        A = ((f2-C) - (f1-C)*2) / 2;
        B = f1 - A - C;
        f3 = 9*A + 3*B + C;
        f4 = 16*A + 4*B + C;
        f5 = 25*A + 5*B + C;
        cout << f3 << " " << f4 << " " << f5 << endl;
    }

    return 0;
}

