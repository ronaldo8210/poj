#include <cstdio>
#include <queue>
using namespace std;

#define msize  205
#define Min(a, b) (a)<(b) ? (a) : (b)

int map[msize][msize];
int pre[msize];
bool visited[msize];
int n, m;

bool bfs(int s, int t)
{
	queue<int> Q;
	int u, v;

	memset(pre, -1, sizeof(pre));
	memset(visited, false, sizeof(visited));

	pre[s] = s;
	Q.push(s);
	while (!Q.empty())
	{
		u = Q.front();
		Q.pop();
		for (v = 1; v <= m; v++)
		{
			if (map[u][v] > 0 && !visited[v])
			{
				pre[v] = u;
				visited[v] = true;
				if (v == t) return true;
				Q.push(v);
			}
		}
	}

	return false;
}

int maxFlow(int s, int t)
{
	int flow = 0, d;
	
	while (bfs(s, t))
	{
		d = INT_MAX;
		for (int u = t; u != s; u = pre[u])
		{
			d = Min(d, map[pre[u]][u]);
		}
		for (int u = t; u != s; u = pre[u])
		{
			map[pre[u]][u] -= d;
			map[u][pre[u]] += d;
		}

		flow += d;
	}
	
	return flow;
}

int main(int argc, char** argv)
{
	int s, e, c;
	
	while (scanf("%d %d", &n, &m) == 2)
	{
		memset(map, 0, sizeof(map));
		for (int i = 1; i <= n; i++)
		{
			scanf("%d %d %d", &s, &e, &c);
			map[s][e] += c;
		}

		printf("%d\n", maxFlow(1, m));
	}

	return 0;
}
