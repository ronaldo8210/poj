#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int k;
    while ((cin >> k) && (k != -1))
    {
        int i;
        int flag[5000000] = {0};
        int a[500001] = {0};
        a[0] = 0;
        for (i = 1; i <= 500000; i++ )
        {
            int t = a[i-1] - i;
            if ((t > 0) && (flag[t] == 0))
            {
                a[i] = t;
                flag[a[i]] = 1;
            }
            else 
            {
                a[i] = a[i-1] + i;
                flag[a[i]] = 1;
            }
        }
        cout << a[k] << endl;
    }

    return 0;
}
