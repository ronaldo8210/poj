#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 210
using namespace std;

char a[MAX], b[MAX], c[2*MAX];

int dp[MAX][MAX];

int main()
{
    int i, j, t, cas;
    scanf("%d", &cas);
    for(t = 1; t <= cas; t++){
        scanf("%s%s%s", a, b, c);
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        int la, lb;
        la = strlen(a);
        lb = strlen(b);
        for(i = 0; i <= la; i++){
            for(j = 0; j <= lb; j++){
                if(i > 0 && a[i-1] == c[i+j-1] && dp[i-1][j])
                    dp[i][j] = 1;
                if(j > 0 && b[j-1] == c[i+j-1] && dp[i][j-1])
                    dp[i][j] = 1;    
            }
        }
        printf("Data set %d: ", t);
        if(dp[la][lb])
            printf("yes\n");
        else
            printf("no\n");
    }
return 0;
}