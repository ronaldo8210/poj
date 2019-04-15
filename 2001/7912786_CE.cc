#include <iostream>
#include <string.h>
using namespace std;

#define MAX 26

typedef struct TrieNode {
	int nCount;
	int bWord;
	struct TrieNode* next[MAX];
} TrieNode;

TrieNode Pool[1000000];
int alloc = 0;

char array[1005][25] = {0};
char pre[25] = {0};

TrieNode* CreateNode()
{
	int i;
	TrieNode* p = &Pool[alloc++];
	p->nCount = 0;
	p->bWord = 0;
	for (i = 0; i < MAX; i++)
		p->next[i] = NULL;
	
	return p;
}

void insert(TrieNode** root, char* str)
{
	int location, i;
	TrieNode* p = *root;
	for (i = 0; str[i] != '\0'; i++)
	{
		location = str[i] - 'a';
		if (NULL == p->next[location])
		{
			p->next[location] = CreateNode();
			p = p->next[location];
		}
		else
		{
			p = p->next[location];
		}
		p->nCount++;
	}

	p->bWord = 1;
}

void search(TrieNode** root, char* str)
{
	int location, i;
	TrieNode* p = *root;
	for (i = 0; str[i] != '\0'; i++)
	{
		location = str[i] - 'a';
		pre[i] = str[i];
		p = p->next[location];
		if (p->nCount == 1) return;
	}

	return;
}

int main(int argc, char** argv)
{
	int i, n = 0;

	TrieNode* root = CreateNode();
	
	while (scanf("%s", array[n]) != EOF)
	{
		insert(&root, array[n]);
		n++;
	}

	for (i = 0; i < n; i++)
	{
		search(&root, array[i]);
		printf("%s %s\n", array[i], pre);
		memset(pre, 0, 25);
	}

	return 0;
}

