#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int a[10001] = {0}, i, t;
    for (i = 1; i <= 10000; i++)
    {
        if (i < 10)
            t = i + i;
        else if (i >= 10 && i < 99)
            t = i + i/10 + i%10;
        else if (i >= 100 && i < 999)
            t = i + i/100 + (i%100)/10 + (i%100)%10;
        else if (i >= 1000 && i <= 9999)
            t = i+ i/1000 + (i%1000)/100 + ((i%1000)%100)/10 + ((i%1000)%100)%10;
        
        if (t <= 10000)
            a[t] = 1;    
    }

    for (i = 1; i <= 10000; i++)
    {
        if (a[i] == 0)
            cout << i << endl;
    }

    return 0;
}

