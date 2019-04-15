#include <cstdio>
using namespace std;

int m[5][5] = {{5, -1, -2, -1, -3},
			   {-1, 5, -3, -2, -4},
			   {-2, -3, 5, -2, -2},
			   {-1, -2, -2, 5, -1},
			   {-3, -4, -2, -1, 0}};

int v(char c)
{
	int idx;
	switch (c)
	{
		case 'A':
			idx = 0;
			break;
		case 'C':
			idx = 1;
			break;
		case 'G':
			idx = 2;
			break;
		case 'T':
			idx = 3;
			break;
		case '-':
			idx = 4;
			break;
	}

	return idx;
}

int Max(int a, int b, int c)
{
	int ret;
	ret = a>b ? a : b;
	ret = ret>c ? ret : c;
	return ret;
}

int main(int argc, char** argv)
{
	int T, alen, blen, i, j;
	char c;
	char a[105], b[105];
	int dp[105][105];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d ", &alen);
		for (i = 1; i <= alen; i++)
		{
			scanf("%c", &c);
			a[i] = c;
		}
		scanf("%d ", &blen);
		for (i = 1; i <= blen; i++)
		{
			scanf("%c", &c);
			b[i] = c;
		}

		dp[0][0] = 0;
		for (j = 1; j <= blen; j++) dp[0][j] = dp[0][j-1] + m[v('-')][v(b[j])];
		for (i = 1; i <= alen; i++) dp[i][0] = dp[i-1][0] + m[v(a[i])][v('-')];

		for (i = 1; i <= alen; i++)
		{
			for (j = 1; j <= blen; j++)
			{
				dp[i][j] = Max(dp[i-1][j-1] + m[v(a[i])][v(b[j])],
							   dp[i][j-1] + m[v('-')][v(b[j])],
							   dp[i-1][j] + m[v(a[i])][v('-')]);
			}
		}

		printf("%d\n", dp[alen][blen]);
	}

	return 0;
}
