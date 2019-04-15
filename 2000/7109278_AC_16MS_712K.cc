#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int n;
    while ((cin >> n) && (n != 0))
    {
        int ans = 0, i, j = 0;
        for (i = 1; j <= n; i++)
        {
            ans += i * i;
            j += i;
        }
        if (j != n)
            ans += (n-j) * (i-1);
        cout << n << " " << ans << endl;
    }
    
    return 0;
}

