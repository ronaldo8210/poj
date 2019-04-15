#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char** argv)
{
    int N, D, i, j, k, find;
    int array[505][105];
    while ((cin >> N) && (cin >> D))
    {
        if ((N == 0) && (D == 0)) break;
        memset(array, 0, sizeof(array));
        for (i = 0; i <= D-1; i++)
            for (j = 0; j <= N-1; j++)
                cin >> array[i][j];

        find = 0;
        for (j = 0; j <= N-1; j++)
        {
            k = 1;
            for (i = 0; i <= D-1; i++)
            {
                k &= array[i][j];
                if (k == 0)
                {
                    break;
                }
            }
            if (k == 1)
            {
                find = 1;
                break;
            }
        }
        
        if (find) cout << "yes" << endl;
        else cout << "no" << endl;
    }    

    return 0;
}

