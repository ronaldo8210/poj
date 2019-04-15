#include <iostream>
using namespace std;

#define maxnum 1<<30

int map[101][101] = {0};
int visit[101] = {0};
int dist[101] = {0};
int N, Q, ans;

void mst_prim()
{
    int i, j, length = 0, mindist, flag;
    
    visit[1] = 1;
    for (i = 2; i <= N; i++)
        dist[i] = map[1][i];

    for (i = 2; i <= N; i++)
    {
        mindist = maxnum;
        for (j = 2; j <= N; j++)
        {
            if ((dist[j] < mindist) && (!visit[j]))
            {
                mindist = dist[j];
                flag = j;
            }
        }
                
        visit[flag] = 1;
        length += dist[flag];
        for (j = 2; j <= N; j++)
        {
            if ((map[flag][j] < dist[j]) && (!visit[j]))
            {
                dist[j] = map[flag][j];
            }
        }
    }

    ans = length;
}

int main(int argc, char** argv)
{
    int i, j, a, b;
    cin >> N;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            cin >> map[i][j];
            if (0 == map[i][j]) map[i][j] = maxnum;
        }
    }
    
    cin >> Q;
    for (i = 1; i <= Q; i++)
    {
        cin >> a >> b;
        map[a][b] = 0;
        map[b][a] = 0;
    }

    mst_prim();  
    cout << ans << endl;
    
    return 0;
}
