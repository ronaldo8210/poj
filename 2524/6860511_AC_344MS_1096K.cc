#include <iostream>
#include <stdio.h>
using namespace std;

int pa[50001];
int num[50001];
int maxnum;

void make_set(int n)
{
    for (int i = 0; i <= n; i++)
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
    maxnum--;
}

void union_set(int x, int y)
{
    link_set(find_set(x), find_set(y));
}

int main(int argc, char** argv)
{
    int n, m, caseid = 0;
    while ((scanf("%d %d", &n, &m) != EOF) && (n != 0) && (m != 0))
    {
        int pair_index, student_i, student_j;
        
        caseid++;
        make_set(n);
        maxnum = n;
        for (pair_index = 0; pair_index < m; pair_index++)
        {
            scanf("%d %d", &student_i, &student_j);
            union_set(student_i, student_j);
        }
        
        cout << "Case " << caseid << ": " << maxnum << endl;
    }

    return 0;
}
