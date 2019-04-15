#include <iostream>
using namespace std;

#define INF 99999

struct edge {
    int u;
    int v;
    int w;
};
edge edges[5501];
int dist[501];
int F, N, M, W;

int bellman_ford()
{
    int i, j;
    dist[1] = 0;
    for (i = 2; i <= N; i++)
        dist[i] = INF;

    for (i = 1; i <= N-1; i++)
    {
        for (j = 1; j <= 2*M+W; j++)
        {
            if (dist[edges[j].v] > dist[edges[j].u] + edges[j].w)
                dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
        }
    }

    for (j = 1; j <= 2*M+W; j++)
    {
        if (dist[edges[j].v] > dist[edges[j].u] + edges[j].w)
            return -1;
    }
    return 1;
}

int main(int argc, char** argv)
{
    int i, j, index, ret;
    cin >> F;
    for (i = 1; i <= F; i++)
    {
        cin >> N >> M >> W;
        index = 0;
        for (j = 1; j <= M; j++)
        {
            index++;
            cin >> edges[index].u >> edges[index].v >> edges[index].w;
            index++;
            edges[index].u = edges[index-1].v;
            edges[index].v = edges[index-1].u;
            edges[index].w = edges[index-1].w;
        }

        for (j = 1; j <= W; j++)
        {
            index++;
            cin >> edges[index].u >> edges[index].v >> edges[index].w;
            edges[index].w = -edges[index].w;
        }

        ret = bellman_ford();
        if (ret < 0) 
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}
