#include <stdio.h>

int pa[100001];
int rank[100001];
int opposite[100001];

void make_set(int n)
{
    int i;
    for (i = 1; i <= n; i++)
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
    int T;
    scanf("%d", &T);
    while (T-- > 0)
    {
        int N, M, j, x, y;
        char ch[3] = {0};
        scanf("%d %d", &N, &M);
        make_set(N);
        for (j = 0; j < M; j++)
        {
            scanf("%s", ch);
            if (ch[0] == 'A')
            {
                scanf("%d %d", &x, &y);
                if ((opposite[x] == -1) || (opposite[y] == -1))
                    printf("Not sure yet.\n");
                else if (find_set(x) == find_set(y))
                    printf("In the same gang.\n");
                else
                    printf("In different gangs.\n");
            }
            else if (ch[0] == 'D')
            {
                scanf("%d %d", &x, &y);
                if (opposite[x] == -1)
                    opposite[x] = y;
                else
                    union_set(opposite[x], y);

                if (opposite[y] == -1)
                    opposite[y] = x;
                else
                    union_set(opposite[y], x);
            }
        }
    }    

    return 0;
}
