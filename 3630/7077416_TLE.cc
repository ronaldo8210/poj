#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(const string &a, const string &b)
{
    return (a.length() < b.length());
}

int main(int argc, char** argv)
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        int N;
        string array[10005];
        int i, j, k;
        bool bExit = false;
        
        cin >> N;
        for (i = 0; i <= N-1; i++)
        {
            cin >> array[i];
        }
        sort(array, array+N, cmp);
        for (j = 0; j <= N-2; j++)
        {
            for (k = j+1; k <= N-1; k++)
            {
                if (array[k].substr(0, array[j].length()) == array[j])
                {
                    bExit = true;
                    break;
                }
            }
            if (bExit) break;
        }

        if (bExit)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}

