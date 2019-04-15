#include <cstdio>
#include <cstring>
using namespace std;

#define maxn  1000005

char str[maxn];
int len;
int next[maxn];

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
	while (scanf("%s", str))
	{
		if (0 == strcmp(str, ".")) break;

		len = strlen(str);
		get_next();

		if (0 == next[len-1])
			printf("1\n");
		else 
			printf("%d\n", len / ((len-1) - next[len-1]));

		memset(str, 0, sizeof(str));
		memset(next, -1, sizeof(next));
	}

	return 0;
}
