#include <iostream>
using namespace std;

int dp[105][105];
int a[105][105];
const int minNum = -999999999;

int main(int argc, char** argv)
{
    int F, V, i, j, k, maxValue, ans;
    cin >> F >> V;
    for (i = 0; i <= F-1; i++)
        for (j = 0; j <= V-1; j++)
            cin >> a[i][j]; 

    for (i = 0; i <= F-2; i++)
        for (j = 0; j <= V-1; j++)
            dp[i][j] = minNum;

    for (j = 0; j <= V-1; j++)
        dp[F-1][j] = a[F-1][j]; 

    for (i = F-2; i >= 0; i--)
    {
        for (j = i; j<= V-1; j++)
        {
            maxValue = minNum;
            for (k = j+1; k <= V-1; k++)
            {
                if (dp[i+1][k] > maxValue) maxValue = dp[i+1][k];
            }
            dp[i][j] = a[i][j] + maxValue;
        }
    }

    ans = minNum;
    for (j = 0; j <= V-1; j++)
    {
        if (dp[0][j] > ans) ans = dp[0][j];
    }   

    cout << ans << endl;
    
    return 0;
}
