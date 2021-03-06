#include <iostream>
#include <cstring>
using namespace std;

const int N = 400005;
char T[N];
int next[N], ans[N], len;

void get_next()
{
	int j = 0, k = -1;
	next[0] = -1;
	while (j < len)
	{
		if (k == -1 || T[j] == T[k])
		{
			j++; k++;
			next[j] = k;
		}
		else
		{	
			k = next[k];
		}
	}
}

void solve()
{
/*	int index = 0, j = len-1, t = j;
	j = next[j];
	while (j != -1)
	{
		if (T[len-1] = T[j])
		{
			ans[index++] = t+1;
		}
		t = j;
		j = next[j];
	}
	if (T[0] == T[len-1])
	{
		ans[index++] = 1;
	}
	for (--index; index >= 1; index--)
	{
		cout << ans[index] << " ";
	}
	cout << ans[index] << endl; */

	int count = 0, j = len;
	while (j != 0)
	{
		ans[++count] = j;
		j = next[j];
	}
	while (count > 1)
	{
		cout << ans[count] << " ";
		count--;
	}
	cout << ans[count] << endl;
}

int main(int argc, char** argv)
{
	while (cin >> T)
	{
		memset(next, 0, N);
		memset(ans, 0, N);
		len = strlen(T);
		// if (T[0] == 0) break;
		get_next();
		solve();		
		memset(T, 0, N);
	}

	return 0;
}

