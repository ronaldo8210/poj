#include <iostream>
#include <cmath>
using namespace std;

int a[105][105];
int dp[105][105];

int main(int argc, char** argv)
{
    int N, i, j;
    cin >> N;
    for (i = 0; i <= N-1; i++)
        for (j = 0; j <= i; j++)
            cin >> a[i][j];    

    for (j = 0; j <= N-1; j++)
        dp[N-1][j] = a[N-1][j];

    for (i = N-2; i >= 0; i--)
        for (j = 0; j <= i; j++)
            dp[i][j] = a[i][j] + max(dp[i+1][j], dp[i+1][j+1]);

    cout << dp[0][0] << endl;
    
    return 0;
}
