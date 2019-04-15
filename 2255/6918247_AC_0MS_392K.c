#include <stdio.h>
#include <string.h>

void build(int n, char* s1, char* s2, char* ans)
{
    if (n <= 0) return;
    int p = strchr(s2, s1[0]) - s2;
    build(p, s1+1, s2, ans);
    build(n-p-1, s1+p+1, s2+p+1, ans+p);
    ans[n-1] = s1[0];
}

int main(int argc, char** argv)
{
    char s1[27] = {0};
    char s2[27] = {0};
    int len = 0;
    while (scanf("%s %s", s1, s2) == 2)
    {
        len = strlen(s1);
        char ans[27] = {0};
        ans[len] = '\0';
        build(len, s1, s2, ans);
        printf("%s\n", ans);
    }
    
    return 0;
}
