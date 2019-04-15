#include <iostream>
//#include <cmath>
using namespace std;

const int INF = 1e9;

int main(int argc, char** argv)
{
    int N, index, array[105] = {0};
    int dp[105][105];
    int i, j, k, minNum;
    
    cin >> N;
    for (index = 0; index <= N-1; index++)
    {
        cin >> array[index];
    }
    
    for (i = 0; i <= N-1; i++)
        dp[i][i] = 0;

    for (j = 2; j <= N-1; j++)
    {
        for (i = j-2; i >= 0; i--)
        {
            dp[i][j] = INF;
            for (k = i+1; k <= j-1; k++)
            {
                //minNum = array[i]*array[j]*array[k] + min(dp[i][k], dp[k][j]);
                minNum = array[i]*array[j]*array[k] + dp[i][k] + dp[k][j];
                if (dp[i][j] > minNum)
                    dp[i][j] = minNum;
            }
        }
    }
    
    cout << dp[0][N-1] << endl;    
    
    return 0;
}
