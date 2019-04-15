#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int n = 0;
    int p, q, r;
    int a, b, c;
    int i, j;
    int A[101] = {0};
    int B[101] = {0};
    int C[101] = {0};
    int w[101][101][101];

    cin >> p >> q >> r;
    while ((p != -1) || (q != -1) || (r != -1))
    {
        n++;
        A[n] = p;
        B[n] = q;
        C[n] = r;
        cin >> p >> q >> r;
    }
    
    w[0][0][0] = 1; 
    w[0][0][1] = 1;
    w[0][1][0] = 1;
    w[0][1][1] = 1;
    w[1][0][0] = 1;
    w[1][0][1] = 1;
    w[1][1][0] = 1;
    for (i = 0; i <= 20; i++)
        for (j = 0; j <= 20; j++)
            w[0][i][j] = 1;
    for (i = 0; i <= 20; i++)
        for (j = 0; j <= 20; j++)
            w[i][0][j] = 1;
    for (i = 0; i <= 20; i++)
        for (j = 0; j <= 20; j++)
            w[i][j][0] = 1;
    
    for (a = 1; a <= 20; a++ )
    {
        for (b = 1; b <= 20; b++)
        {
            for (c = 1; c <= 20; c++)
            {
                if (a < b && b < c)
                    w[a][b][c] = w[a][b][c-1] + w[a][b-1][c-1] - w[a][b-1][c];
                else
                    w[a][b][c] = w[a-1][b][c] + w[a-1][b-1][c] + w[a-1][b][c-1] - w[a-1][b-1][c-1];
            }
        }
    }
    
    for (i = 1; i <= n; i++)
    {
        if (A[i] <= 0 || B[i] <= 0 || C[i] <= 0)
            cout << "w(" << A[i] << ", " << B[i] << ", " << C[i] << ") = " << 1 << endl;
        else if (A[i] > 20 || B[i] > 20 || C[i] > 20)
            cout << "w(" << A[i] << ", " << B[i] << ", " << C[i] << ") = " << w[20][20][20] << endl;
        else
            cout << "w(" << A[i] << ", " << B[i] << ", " << C[i] << ") = " << w[A[i]][B[i]][C[i]] << endl;
    }

    return 0;
}
