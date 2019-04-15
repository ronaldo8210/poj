#include <iostream>
#include <cstring>
using namespace std;

#define INF 0x7fffffff

int N;
int map[2001][2001];
int dist[2001];
int visit[2001];

int dijkstra()
{
    int i, j, distmin, mark;
    memset(visit, 0, sizeof(visit));
    dist[N] = 0;
    map[N][N] = 0;
    for (i = 1; i <= N-1; i++)
    {
        dist[i] = map[N][i];
    }
    visit[N] = 1;
    
    for (i = 1; i <= N-1; i++)
    {
        distmin = INF;
        for (j = 1; j <= N-1; j++)
        {
            if ((dist[j] < distmin) && (!visit[j]))
            {
                distmin = dist[j];
                mark = j;
            }
        }

        visit[mark] = 1;
        for (j = 1; j <= N-1; j++)
        {
            if ((dist[j] > dist[mark] + map[mark][j]) && (!visit[j]))
                dist[j] = dist[mark] + map[mark][j];
        }
    }

    return dist[1];
}

int main(int argc, char** argv)
{
    int T, i, j, a, b, len, ret;
    while (cin >> T >> N)
    {
        for (i = 1; i <= N; i++)
            for (j = 1; j <= N; j++)
                map[i][j] = INF;
    
        for (i = 1; i <= T; i++)
        {
            cin >> a >> b >> len;
            map[a][b] = len;
            map[b][a] = len;
        }

        ret = dijkstra();
        cout << ret << endl;
    }
     
    return 0;
}
