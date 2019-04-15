#include <cstdio>
using namespace std;

#define max(x, y) (x)>(y) ? (x) : (y)

int a[100005];
int b[100005];
int ans;

int main(int argc, char** argv)
{
	int N;
	while ((scanf("%d", &N)) && (N != 0))
	{
		int i, j, k;
		ans = -9999999;
		
		for (i = 0; i <= N-1; i++)
		{
			scanf("%d", &a[i]);
		}

		for (k = 0; k <= N-2; k++)
		{
			int X, Y;

			b[0] = a[0];
			b[k+1] = a[k+1];
			X = b[0];
			Y = b[k+1];
			for (j = 1; j <= k; j++)
			{
				b[j] = max(b[j-1]+a[j], a[j]);
				if (b[j] > X) X = b[j];
			}
			for (j = k+2; j <= N-1; j++)
			{
				b[j] = max(b[j-1]+a[j], a[j]);
				if (b[j] > Y) Y = b[j];
			}
			
			if (X+Y > ans) ans = X+Y;
		}

		printf("%d\n", ans);
	}

	return 0;
}
