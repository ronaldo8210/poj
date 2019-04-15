#include <stdio.h>

int main(int argc, char** argv)
{
    int T;
    scanf("%d", &T);
    while (T-- > 0)
    {
        int N, K, a, b, p = 1, q = 1, ans;
        scanf("%d %d", &N, &K);
        if (K == 0) printf("1\n");
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
            printf("%d\n", ans);
        } 
    }

    return 0;
}
