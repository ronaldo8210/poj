#include <iostream>
using namespace std;

int pa[30001];
int num[30001];

void make_set(int n)
{
    for (int i = 0; i < n; i++)
    {
        pa[i] = i;
        num[i] = 1;
    }    
}

int find_set(int x)
{
    if (x != pa[x])
        pa[x] = find_set(pa[x]);
    return pa[x];
}

void link_set(int x, int y)
{
    if (x == y) return;
    
    if (num[x] <= num[y])
    {
        pa[x] = y;
        num[y] += num[x];
    }
    else
    {        
        pa[y] = x;
        num[x] += num[y];
    }
}

void union_set(int x, int y)
{
    link_set(find_set(x), find_set(y));
}

int main(int argc, char** argv)
{
    int n, m;
    while ((cin >> n) && (cin >> m) && (n != 0))
    {
        int groupindex, memberindex, membercount, firstmember, followmember;
        
        make_set(n);
        for (groupindex = 0; groupindex < m; groupindex++)
        {
            cin >> membercount >> firstmember;
            for (memberindex = 1; memberindex < membercount; memberindex++)
            {
                cin >> followmember;
                union_set(firstmember, followmember);
            }
        }
        
        cout << num[find_set(0)] << endl;
    }

    return 0;
}
