#include <iostream>
#include <cstring>
using namespace std;

const int N = 1000005;
int next[N];
char S[N], T[N];
int slen, tlen;
int cnt;

/*
void get_nextval()
{
	int j = 0, k = -1;
	next[0] = -1;
	while (j <= tlen-1)
	{
		if (k == -1 || T[j] == T[k])
		{
			j++; k++;
			if (T[j] != T[k]) next[j] = k;
			else next[j] = next[k];
		}
		else
		{
			k = next[k];
		}
	}
}
*/

void get_next()
{
	int j = 0, k = -1;
	next[0] = -1;
	while (j < tlen)
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

void kmp_count()
{
	int i = 0, j = 0;
	cnt = 0;
/*	while (i < slen)
	{		
		if (j == -1 || S[i] == T[j]) 
		{
			i++; j++;
		}
		else 
		{
			j = next[j];
		}
		if (j == tlen)
		{
			cnt++; 
			j = next[j-1];
		}
	} */
	for (i = 0; i < slen; i++)
	{
		while (j > 0 && S[i] != T[j])
			j = next[j];
		if (S[i] == T[j])
			j++;
		if (j == tlen)
		{
			cnt++;
			j = next[j];
		}
	}
}

int main(int argc, char** argv)
{
	int M;
	cin >> M;
	while (M--)
	{
		cin >> T >> S;
		slen = strlen(S);
		tlen = strlen(T);
		get_next();
		kmp_count();
		cout << cnt << endl;
	}

	return 0;
}

