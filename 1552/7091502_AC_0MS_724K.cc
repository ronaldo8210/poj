#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(int argc, char** argv)
{
    int array[15] = {0};
    int a, n, ans, i, j;
    while ((cin >> a) && (a != -1))
    {
        n = 0;
        array[n++] = a;
        while ((cin >> a) && (a != 0))
        {
            array[n++] = a;
        }

        sort(array, array+n);
        ans = 0;
        for (i = 0; i <= n-2; i++)
        {
            for (j = i+1; j <= n-1; j++)
            {
                if (array[j] == 2 * array[i])
                {
                    ans++;
                    break;
                }
            }
        }

        cout << ans << endl;
        memset(array, 0, sizeof(array));
    }    

    return 0;
}

