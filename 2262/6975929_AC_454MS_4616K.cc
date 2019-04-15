#include <iostream>
using namespace std;

const int maxNum = 1000001;
int IsOddPrime[maxNum] = {0};

int main(int argc, char** argv)
{
    int n, a, b;
    IsOddPrime[2] = 1;
    
    for (a = 3; a < maxNum; a += 2)
        IsOddPrime[a] = 1;
    for (a = 2; a <= maxNum/2; ++a)
    {
        if (IsOddPrime[a])
        {
            for (b = 3; b < maxNum/a; b += 2)
                IsOddPrime[a*b] = 0;
        }
    }
    
    while ((cin >> n) && (n != 0))
    {
        for (a = 3; a <= n/2; a++)
        {
            b = n-a;
            if (IsOddPrime[a] && IsOddPrime[b])
            {
                cout << n << " = " << a << " + " << b << endl;
                break;
            }
        }
    }

    return 0;
}
