#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
    int T;
    cin >> T;
    while (T-- > 0)
    {
        int N, K, p, q, m, ans = 1;
        cin >> N >> K;
        if (K == 0) cout << 1 << endl;
        else
        {
            p = N - K + 1;
            q = K;
            m = p - q + 1;
            while (p >= m)
            {
                ans = ans * p;
                p--;
            }

            ans = ans % 20100713;
            cout << ans << endl;
        } 
    }

    return 0;
}
