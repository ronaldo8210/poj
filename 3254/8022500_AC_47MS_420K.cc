#include <cstdio>
#include <cmath>
using namespace std;

#define Max(a, b) (a)>(b) ? (a) : (b)
#define mod 100000000

int M, N;
int map[12][12];
int dp[15][(1<<12)-1];

int valid(int a, int b)
{
	//if (b & (~a)) return 0;
	//else return 1;
	int i, max = (int)(log(b) / log(2));
	if (~(a | (~b))) return 0;
	else
	{
		for (i = 0; i < max; i++)
			if ((b & 1<<i) && (b & 1<<(i+1))) return 0;
		return 1;
	}
}

int dfs(int row, int bitway)
{
	int j, ans = 0, tar = 0;

	if (dp[row][bitway] >= 0) return dp[row][bitway]; //??

	for (j = 0; j <= N-1; j++)
		tar += map[row][j] * (1<<j);
	tar &= (~bitway);
	
	if (row == M-1)
	{
		for (j = 0; j <= (1<<N)-1; j++)
		{
			if (valid(tar, j)) ans += 1;
		}

		return dp[row][bitway] = ans;
	}
	else 
	{
		for (j = 0; j <= (1<<N)-1; j++)
		{
			if (valid(tar, j)) ans += dfs(row+1, j);
		}

		return dp[row][bitway] = ans;
	}
}

int main(int argc, char** argv)
{
	int i, j, ans;
	scanf("%d %d", &M, &N);
	for (i = 0; i <= M-1; i++)
	{
		for (j = 0; j <= N-1; j++)
			scanf("%d", &map[i][j]);
	}
	for (i = 0; i <= M-1; i++)
	{
		for (j = 0; j <= (1<<N)-1; j++)
			dp[i][j] = -1;
	}
	ans = dfs(0, 0) % mod;
	printf("%d\n", ans);

	return 0;
}