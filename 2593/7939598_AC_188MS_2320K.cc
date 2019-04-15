#include <cstdio>
using namespace std;

#define Max(x, y) (x)>(y) ? (x) : (y)

int a[100005];
int b1[100005];
int b2[100005];
int dp1[100005];
int dp2[100005];
int ans;

int main(int argc, char** argv)
{
	int N;
	while ((scanf("%d", &N)) && (N != 0))
	{
		int i, j, max;
		ans = -9999999;
		
		for (i = 0; i <= N-1; i++)
		{
			scanf("%d", &a[i]);
		}

		b1[0] = a[0];
		dp1[0] = b1[0];
		max = dp1[0];
		for (j = 1; j <= N-1; j++)
		{
			b1[j] = Max(b1[j-1]+a[j], a[j]);
			dp1[j] = Max(max, b1[j]);
			if (dp1[j] > max) max = dp1[j];
		}
		
		b2[N-1] = a[N-1];
		dp2[N-1] = b2[N-1];
		max = dp2[N-1];
		ans = dp2[N-1] + dp1[N-2];
		for (j = N-2; j >= 1; j--)
		{
			b2[j] = Max(b2[j+1]+a[j], a[j]);
			dp2[j] = Max(max, b2[j]);
			if (dp2[j] > max) max = dp2[j];
			if (dp2[j]+dp1[j-1] > ans) ans = dp2[j] + dp1[j-1];
		}
		
		printf("%d\n", ans);
	}

	return 0;
}
