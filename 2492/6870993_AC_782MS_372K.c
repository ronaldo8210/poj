#include <stdio.h>

int pa[2001];
int rank[2001];
int opposite[2001];

void make_set(int n)
{
    int i;
    for (i = 0; i <= n; i++)
    {
        pa[i] = i;
        rank[i] = 0;
        opposite[i] = -1;
    }
}

int find_set(int x)
{
    if (x != pa[x])
    {
        pa[x] = find_set(pa[x]);
    }
    return pa[x];
}

void union_set(int x, int y)
{
    int a, b;
    
    a = find_set(x);
    b = find_set(y);
    if (a == b) return;

    if (rank[a] > rank[b])
    {
        pa[b] = a;
    }
    else
    {
        pa[a] = b;
        if (rank[a] == rank[b])
            rank[b]++;
    }
}

int main(int argc, char** argv)
{
    int n, caseid = 0;
    scanf("%d", &n);
    while (n-- > 0)
    {
        int numbugs, numinteractions, j, x, y, z;
        int bfind = 0;
        
        caseid++;
        scanf("%d %d", &numbugs, &numinteractions);
        make_set(numbugs);
        for (j = 0; j < numinteractions; j++)
        {
            scanf("%d %d", &x, &y);
            if (bfind) continue;
            if (find_set(x) == find_set(y))
            {
                bfind = 1;
                continue;
            }

            if (opposite[x] == -1)
            {
                opposite[x] = y;
            }
            else
            {
                z = opposite[x];
                union_set(y, z);
            }

            if (opposite[y] == -1)
            {
                opposite[y] = x;
            }
            else
            {
                z = opposite[y];
                union_set(x, z);
            }
        }

        printf("Scenario #%d:\n", caseid);
        if (bfind)
        {
            printf("Suspicious bugs found!\n\n");                
        }
        else
        {
            printf("No suspicious bugs found!\n\n");
        }
    }    

    return 0;
}
