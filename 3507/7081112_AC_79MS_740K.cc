#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
    int a[6], sum;
    float avg;
    while (1)
    {
        int i;
        for (i = 0; i <= 5; i++)
            cin >> a[i];
        if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0 && a[5] == 0)
            break;
        sort(a, a+6);
        sum = 0;
        for (i = 1; i <= 4; i++)
            sum += a[i];
        avg = (float)sum / 4;
        cout << avg << endl;
    }

    return 0;
}

