#include <iostream>
#include <cstring>
using namespace std;

int nodenum;

struct node {
	bool isExist;
	node* branch[10];
} Node[100000];

class Trie
{
private:
	node root;
public:
	Trie() {root = Node[0];}
	bool insert(char num[])
	{
		node *location = &root;
		int i = 0;
		int len = strlen(num);
		while (num[i])
		{
			if (i == len-1 && location->branch[num[i]-'0'] != NULL)	
			{	
				return false;
			}
			if (location->branch[num[i]-'0'] == NULL)
			{
				location->branch[num[i]-'0'] = &Node[nodenum];
				Node[nodenum].isExist = false;
				memset(Node[nodenum].branch, NULL, sizeof(Node[nodenum].branch));
				nodenum++;
			}
			if (location->branch[num[i]-'0']->isExist == true)
			{
				return false;
			}
			location = location->branch[num[i]-'0'];
			i++;
		}
		location->isExist = true;
		return true;
	}
};

int main(int argc, char** argv)
{
    int testcases, count;
    cin >> testcases;
	while (testcases--)
	{
		nodenum = 1;
		bool flag = true;
		cin >> count;
		char tel[11];
		Trie t;
		while (count--)
		{
			cin >> tel;
			if (!t.insert(tel)) flag = false;
		}
		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

    return 0;
}

