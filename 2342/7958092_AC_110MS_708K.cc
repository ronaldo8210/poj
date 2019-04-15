#include <cstdio>
using namespace std;

#define Max(a, b) (a)>(b) ? (a) : (b)

int dp[6005][2];
int parent[6005];
int visited[6005];
int N;

void dfs(int node)
{
	int i;
	visited[node] = 1;
	for (i = 1; i <= N; i++)
	{
		if (!visited[i] && parent[i] == node)
		{
			dfs(i);
			dp[node][0] += Max(dp[i][0], dp[i][1]);
			dp[node][1] += dp[i][0];
		}
	}
}

int main(int argc, char** argv)
{
	int i, root, l, k, beg;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &dp[i][1]);
	}
	
	root = 0;
	beg = 1;
	while (scanf("%d %d", &l, &k) && l != 0 && k != 0)
	{
		parent[l] = k;
		if (root == l || beg)
			root = k;
	}

	dfs(root);
	printf("%d\n", Max(dp[root][0], dp[root][1]));
	
	return 0;
}
