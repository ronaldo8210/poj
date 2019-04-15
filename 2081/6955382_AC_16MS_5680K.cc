#include <iostream>
using namespace std;

int flag[35000000] = {0};
int a[500001];

void calc()
{
    int i, t;        
    a[0] = 0;
    for (i = 1; i <= 500000; i++ )
    {
        t = a[i-1] - i;
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
}

int main(int argc, char** argv)
{
    int k;
    calc();
    while ((cin >> k) && (k != -1))
    {      
        cout << a[k] << endl;
    }

    return 0;
}
