#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

char X[256], Y[256];
int C[256][256];

int lcs_length()
{
    int m = 0, n = 0;
    int i = 0, j = 0;

    m = strlen(X);
    n = strlen(Y);
    for (i = 1; i <= m; i++)
        C[i][0] = 0;
    for (j = 0; j <= n; j++)
        C[0][j] = 0;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                C[i][j] = C[i - 1][j - 1] + 1;
            }
            else if (C[i - 1][j] >= C[i][j - 1])
            {
                C[i][j] = C[i - 1][j];
            }
            else
            {
                C[i][j] = C[i][j - 1];
            }
        }
    }
    return C[m][n];
}

int main (int argc, char **argv)
{
    memset(X, 0, 256);
    memset(Y, 0, 256);

    while (scanf("%s %s", &X, &Y) > 0)
    { 
        cout << lcs_length() << endl;
    }

    return 0;
}
