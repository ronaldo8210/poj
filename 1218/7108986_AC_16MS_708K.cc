#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    struct cell {
        int num;
        int locked;
    };
     
    int a;
    cin >> a;
    while (a--)
    {
        int n, i, j, total = 0;
        cin >> n;
        cell array[105];
        for (i = 1; i <= n; i++)
        {
            array[i].num = i;
            array[i].locked = 0;
        }

        for (i = 2; i <= n; i += 2)
        {
            array[i].locked = 1;
        }

        for (j = 3; j <= n; j++)
        {
            for (i = j; i <= n; i += j)
            {
                if (array[i].locked == 1)
                    array[i].locked = 0;
                else
                    array[i].locked = 1;
            }
        }

        for (i = 1; i <= n; i++)
        {
            if (array[i].locked == 0)
                total++;
        }
        cout << total << endl;
    }

    return 0;
}

