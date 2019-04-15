#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(int argc, char** argv)
{
    double n, p, k;
    while (cin >> n >> p)
    {
        k = pow(p, 1.0/n);
        printf("%.0lf\n", k);
    }

    return 0;
}

