#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 1000000
 
char substr[MAXN + 2];
int sublen;
int next[MAXN + 1];
 
void getNext() {
    next[1] = 0;
    int i, j = 0;
    for (i = 2; i <= sublen; ++i) {
        while (j > 0 && substr[j + 1] != substr[i])
            j = next[j];
        if (substr[j + 1] == substr[i])
            ++j;
        next[i] = j;
    }
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    while (gets(substr + 1)) {
        if (substr[1] == '.')
            break;
        sublen = strlen(substr + 1);
        getNext();
        if (sublen % (sublen - next[sublen]) == 0)
            printf("%d\n", sublen / (sublen - next[sublen]));
        else
            puts("1");
    }
    return 0;
}