#include <cstdio>
using namespace std;

int main(int argc, char** argv)
{
	int N, M, i, j;
	int w[3500] = {0};
	int d[3500] = {0};
	int dp[13000] = {0};
	
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++)
	{
		scanf("%d %d", &w[i], &d[i]);
	}

	for (i = 1; i <= N; i++)
	{
		for (j = M; j >= w[i]; j--)
		{
			if (dp[j] < dp[j-w[i]] + d[i])
				dp[j] = dp[j-w[i]] + d[i];
		}
	}

	printf("%d\n", dp[M]);

	return 0;
}
