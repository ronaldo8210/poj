#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 20010;
int w[maxn], wa[maxn], wb[maxn], wv[maxn], a[maxn], x[maxn];
int sa[maxn], rank[maxn], height[maxn], n;

int cmp(int *r, int a, int b,int l)
{
	return (r[a] == r[b] && r[a+l] == r[b+l]);
}

void da(int *r, int *sa, int n, int m)
{
	int i, j, p, *x = wa, *y = wb, *t;
	for (i = 0; i < m; i++) w[i] = 0;
	for (i = 0; i < n; i++) w[x[i]=r[i]]++;
	for (i = 1; i < m; i++) w[i] += w[i-1];
	for (i = n-1; i >= 0; i--) sa[--w[x[i]]] = i;
	for (p = 1, j = 1; p < n; j *= 2, m = p)
	{
		for (p = 0, i = n-j; i < n; i++) y[p++] = i;
		for (i = 0; i < n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
		for (i = 0; i < m; i++) w[i] = 0;
		for (i = 0; i < n; i++) w[wv[i]=x[y[i]]]++;
		for (i = 1; i < m; i++) w[i] += w[i-1];
		for (i = n-1; i >= 0; i--) sa[--w[wv[i]]] = y[i];
		for (t = x, x = y, y = t, p = 1, i = 1, x[sa[0]] = 0; i < n; i++)
			x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p-1 : p++;
	}

	return;
}

void cal_height(int *r, int *sa, int n)
{
	int i, j, k = 0;
	for (i = 1; i <= n; i++) rank[sa[i]] = i;
	for (i = 0; i < n; height[rank[i++]] = k)
		for (k ? k-- : 0, j = sa[rank[i] - 1]; r[i+k] == r[j+k]; k++);

	return;
}

int r[maxn];
int main(int argc, char** argv)
{
	/* test code
	int n, i;
	char* str = "aabaaaab";
	int len = strlen(str);
	
	memset(sa, 0, sizeof(sa));
	memset(height, 0, sizeof(height));

	for (i = 0; i <= len-1; i++) a[i] = static_cast<int>(str[i]);

	da(a, sa, len, 100);
	cal_height(a, sa, len-1);

	for (i = 0; i <= len-1; i++) printf("%d ", sa[i]);
	printf("\n");
	for (i = 1; i <= len-1; i++) printf("%d ", height[i]);
	printf("\n");
	*/
	
	int i, j, p, q, mid, mi, ma, ans, s, e;
	int flag;
	
	while (scanf("%d", &n) && n != 0)
	{
		scanf("%d", &s);
		for (i = 0; i < n-1; i++)
		{
			scanf("%d", &e);
			r[i] = e-s+100;
			s = e;
		}
		r[n-1] = 0;
		da(r, sa, n, 189);
		cal_height(r, sa, n-1);

		ans = 0; p = 0; q = n-1;
		while (p <= q)
		{
			mid = (p+q) >> 1;
			flag = 0;
			mi = ma = sa[1];
			for (i = 2; i <= n; i++)
			{
				if (height[i] >= mid && i != n)
				{
					if (sa[i] > ma) ma = sa[i];
					if (sa[i] < mi) mi = sa[i];
					continue;
				}
				else
				{
					if (ma-mi >= mid) 
					{
						flag = 1;
						break;
					}
					mi = ma = sa[i];
				}
			}

			if (flag) 
			{
				ans = mid;
				p = mid + 1;
			}
			else
				q = mid - 1;
		}
		
		if (ans < 4) printf("0\n");
		else printf("%d\n", ans+1);
	}
	
	return 0;
}
