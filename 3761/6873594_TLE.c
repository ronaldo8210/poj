#include<stdio.h>

int main(int argc, char** argv)
{
    int T;
    scanf("%d", &T);
    while (T-- > 0)
    {
        int N, K, p, q, m, ans = 1;
        scanf("%d %d", &N, &K);
        if (K == 0) printf("1\n");
        else
        {
            p = N - K + 1;
            q = K;
            m = p - q + 1;
            for (p; p >= m; p--)
                ans = ans * p;

            ans = ans % 20100713;
            printf("%d\n", ans);
        } 
    }

    return 0;
}
