#include <iostream>
#include <cmath>
using namespace std;

char str[5005];
short int dp[5005][5005];

int main(int argc, char** argv)
{
    int N, i, j;
    
    cin >> N;
    cin >> str;
    str[N] = '\0';
    for (i = 0; i <= N-1; i++)
        dp[i][i] = 0;

    for (j = 1; j <= N-1; j++)
    {
        for (i = j-1; i >= 0; i--)
        {
            if (str[i] == str[j])
            {
                dp[i][j] = dp[i+1][j-1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[0][N-1] << endl;    

    return 0;
}
