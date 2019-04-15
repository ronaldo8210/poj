#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
    int T;
    cin >> T;
    while (T-- > 0)
    {
        int N, K, a, b, p = 1, q = 1, ans;
        cin >> N >> K;
        if (K == 0) cout << 1 << endl;
        else
        {
            a = (N-K)+1;
            b = (N-2*K)+1;
            if (a == 0)
            {
                p = 1;
            }
            else 
            {
                while (a >= 1)
                {
                    p = p*a;
                    a--;
                }                    
            }
            
            if (b == 0)
            {
                q = 1;
            }
            else 
            {
                while (b >= 1)
                {
                    q = q*b;
                    b--;
                }                   
            }
            
            ans = p / q;
            ans = ans % 20100713;
            cout << ans << endl;
        } 
    }

    return 0;
}
