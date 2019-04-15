#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char** argv)
{
    char sz[105], str[105];
    int a, b, i;
    char* res;
    while (scanf("%s %d %d", sz, &a, &b) != EOF)
    {
        memset(str, 0, sizeof(str));
        itoa(strtol(sz, &res, a), str, b);
        if (strlen(str) <= 7)
        {
            for (i = 0; i < strlen(str); i++)
            {
                if (str[i] >= 'a' && str[i] <= 'z') str[i] -= 32;
            }
            printf("%7s\n", str);
        }
        else
            printf("%7s\n", "ERROR");        
    }

    return 0;
}
