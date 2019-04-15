#include <cstdio>
using namespace std;

#define Min(a, b) (a)<(b) ? (a), (b)

const int MAX = 500005;
int array[MAX], b[MAX];
int ans;

void merge(int l, int m, int r)
{
	int i, j, k = 0;
	for (i = l, j = m+1; i <= m, j <= r; k++)
	{
		if (array[i] < array[j])
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
	int N, i;

	while (scanf("%d", &N) && N != 0)
	{
		for (i = 0; i <= N-1; i++)
		{
			scanf("%d", &array[i]);
		}

		ans = 0;
		mergesort(0, N-1);
		printf("%d\n", ans);
	}

	return 0;
}