#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, char** argv)
{
    int N;
    cin >> N;
    while (N--)
    {
        string str, array[4];
        double a[4] = {0}, m, i;
        int j;
        cin >> str;
        array[0] = str.substr(0, 8);
        array[1] = str.substr(8, 8);
        array[2] = str.substr(16, 8);
        array[3] = str.substr(24, 8);
        for (i = 7, j = 0; i >= 0; i--, j++)
        {
            m = (array[0][j]-'0')*pow((double)2, i);
            a[0] += m;
            m = (array[1][j]-'0')*pow((double)2, i);
            a[1] += m;
            m = (array[2][j]-'0')*pow((double)2, i);
            a[2] += m;
            m = (array[3][j]-'0')*pow((double)2, i);
            a[3] += m;
        }

        cout << a[0] << "." << a[1] << "." << a[2] << "." << a[3] << endl;
    }

    return 0;
}

