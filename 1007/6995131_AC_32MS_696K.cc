#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef struct node {
    string strDNA;
    int key;
    int pos;
} node;

bool cmp(const node &a, const node &b)
{
    if (a.key == b.key)
        return (a.pos < b.pos);
    else
        return (a.key < b.key);
}

int main(int argc, char** argv)
{
    int n, m, count, i, j, k;
    string str;
    node DNAs[105];
    
    cin >> n >> m;
    for (i = 0; i <= m-1; i++)
    {
        cin >> str;
        count = 0;
        for (j = 0; j <= n-1; j++)
        {
            for (k = j+1; k <= n-1; k++)
            {
                if (str[j] > str[k]) count++;
            }
        }

        DNAs[i].strDNA = str;
        DNAs[i].key = count;
        DNAs[i].pos = i;
    }

    sort(DNAs, DNAs+m, cmp);
    for (i = 0; i <= m-1; i++)
    {
        cout << DNAs[i].strDNA << endl;
    }

    return 0;
}
