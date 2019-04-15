#include <cstdio>
#include <cstring>
using namespace std;

#define maxn  1000010

char str[maxn];
int len;
int next[maxn];
int n, cnt;

void get_next()
{
	int i = 0, j = -1;
	
	next[0] = -1;
	while (i <= len-1)
	{
		if (j == -1 || str[i] == str[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}

int main(int argc, char** argv)
{
	cnt = 1;
	while (scanf("%d", &n) && n != 0)
	{
		int i, j;
		scanf("%s", str);		
		//strcpy(str, "aabaabaabaab");
		
		len = strlen(str);
		get_next();

		//for (int i = 0; i < len; i++) printf("%d\n", next[i]);
		printf("Test case #%d\n", cnt++);
		for (i = 2; i <= len; i++)
		{
			if (i % (j = i - next[i]) == 0)
			{
				if (i/j > 1)
					printf("%d %d\n", i, i/j);
			}
		}
		printf("\n");
	}

	return 0;
}
