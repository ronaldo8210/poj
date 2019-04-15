#include <cstdio>
#include <cstring>
//#include <iostream>
using namespace std;

#define Min(a, b) (a)<(b) ? (a), (b)

const int MAX = 1005;
int array[MAX], b[MAX];
//__int64 ans;
int ans;

void merge(int l, int m, int r)
{
	int i, j, k = 0;
	for (i = l, j = m+1; i <= m && j <= r; k++)
	{
		if (array[i] <= array[j])
		{
			b[k] = array[i++];
		}
		else 
		{
			b[k] = array[j++];
			ans += m-i+1;
		}
	}

	for (; i <= m;)
		b[k++] = array[i++];
	for (; j <= r;)
		b[k++] = array[j++];
		
	for (i = 0; i <= k-1; i++)
	{
		array[l+i] = b[i];
	}

	return;
}

void mergesort(int beg, int end)
{
	if (end <= beg) return;

	int mid = (beg + end) / 2;
	mergesort(beg, mid);
	mergesort(mid+1, end);
	
	merge(beg, mid, end);

	return;
}

int main(int argc, char** argv)
{
	int M, caseid = 1;
	scanf("%d", &M);

	while (M--)
	{
		int N, i;
		scanf("%d", &N);
		
		memset(array, 0, sizeof(array));
		memset(b, 0, sizeof(b));
		for (i = 0; i <= N-1; i++)
		{
			scanf("%d", &array[i]);
		}

		ans = 0;
		mergesort(0, N-1);
		printf("Scenario #%d:\n%d\n\n", caseid++, ans);
	}

	return 0;
}