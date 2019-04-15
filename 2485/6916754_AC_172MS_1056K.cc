#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxNum 99999

int map[501][501];
int visit[501];
int dist[501];
int N, maxlen;

void mst_prim()
{
    int i, j, mindist, flag;
    
    memset(visit, 0, sizeof(visit));
    maxlen = 0;
    visit[1] = 1;
    for (i = 2; i <= N; i++)
        dist[i] = map[1][i];

    for (i = 2; i <= N; i++)
    {
        mindist = maxNum;
        for (j = 2; j <= N; j++)
        {
            if ((dist[j] < mindist) && (!visit[j]))
            {
                mindist = dist[j];
                flag = j;
            }
        }
                
        visit[flag] = 1;
        if (maxlen < mindist) maxlen = mindist;
        for (j = 2; j <= N; j++)
        {
            if ((map[flag][j] < dist[j]) && (!visit[j]))
            {
                dist[j] = map[flag][j];
            }
        }
    }
}

int main(int argc, char** argv)
{
    int i, j, testnum;
    scanf("%d", &testnum);
    while (testnum-- > 0)
    {
        scanf("%d", &N);
        for (i = 1; i <= N; i++)
        {
            for (j = 1; j <= N; j++)
            {
                scanf("%d", &map[i][j]);
                if (0 == map[i][j]) map[i][j] = maxNum;
            }
        }

        mst_prim();  
        printf("%d\n", maxlen);
    }
        
    return 0;
}
