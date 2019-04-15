//#include <cstdio>
#include <iostream>
using namespace std;

int dp[2005][2005];
int cost[26][2];

int Min(int a, int b, int c, int d)
{
	int r;
	r = a<b ? a : b;
	r = r<c ? r : c;
	r = r<d ? r : d;

	return r;
}

int main(int argc, char** argv)
{
	int N, M, i, j, a, d;
	char str[2005] = {0};
	char c;
	
	//scanf("%d %d", &N, &M);
	//scanf("%s", str);
	cin >> N >> M;
	cin >> str;
	for (i = 1; i <= N; i++)
	{
		//scanf("%c %d %d", &c, &a, &d);
		cin >> c >> a >> d;
		cost[c-'a'][0] = a;
		cost[c-'a'][1] = d;
	}
	/*
	for (i = 0; i <= N-1; i++)
	{
		for (j = 0; j <= N-1; j++)
			dp[i][j] = 0;
	} */

	for (j = 1; j <= M-1; j++)
	{
		for (i = j-1; i >= 0; i--)
		{
			if (str[i] == str[j])
			{
				dp[i][j] = dp[i+1][j-1];
			}
			else
			{
				dp[i][j] = Min(dp[i+1][j] + cost[str[i]-'a'][0],
							   dp[i][j-1] + cost[str[j]-'a'][0],
							   dp[i+1][j] + cost[str[i]-'a'][1],
							   dp[i][j-1] + cost[str[j]-'a'][1]);
			}
		}
	}

	//printf("%d\n", dp[0][M-1]);
	cout << dp[0][M-1] << endl;

	return 0;
}
