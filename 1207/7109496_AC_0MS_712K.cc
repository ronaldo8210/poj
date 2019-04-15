#include <iostream>
using namespace std;

static int func(int n)
{
    int sum = 1;
    while (1)
    {
        if (n == 1) break;
        if (n % 2 != 0) n = 3 * n + 1;
        else n = n / 2;
        sum++;
    }

    return sum;
}

int main(int argc, char** argv)
{
    int i, j, index, t, max, ri, rj;
    while (cin >> i >> j)
    {
        if (i < j)
        {
            ri = i;
            rj = j;
        }
        else
        {
            ri = j;
            rj = i;
        }

        max = -1;
        for (index = ri; index <= rj; index++)
        {
            t = func(index);
            if (t > max) max = t;
        }
        cout << i << " " << j << " " << max << endl;
    }

    return 0;
}

