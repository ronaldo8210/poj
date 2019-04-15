#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    string str;
    while (1)
    {
        int i, len, t;
        double sum = 0;
        cin >> str;
        if (str == "0") break;
        len = str.length();
        t = len;
        for (i = 0; i <= len-1; i++)
        {
            sum += (str[i] - '0') * (pow((double)2, (double)t) - 1);
            t--;
        }
        //cout << sum << endl;
        printf("%.0lf\n", sum);
    }

    return 0;
}

