#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct directory
{
    char e[15];
    char f[15];
};

int qcmp(const void* a, const void* b)
{
    return strcmp((*(struct directory *)a).f, (*(struct directory *)b).f);
}

int bcmp(const void* a, const void* b)
{
    return strcmp((char *)a, (*(struct directory *)b).f);
}

struct directory dict[100005];

int main(int argc, char** argv)
{
    int flag = 0;
    char line[64];
    int i = 0;
    while (gets(line))
    {
        if (line[0] == '\0')
        {
            flag = 1;
            qsort(dict, i, sizeof(struct directory), qcmp);
            continue;
        }

        if (flag == 0)
        {
            sscanf(line, "%s %s", dict[i].e, dict[i].f);
            i++;
        }
        else 
        {
            struct directory* p = bsearch(line, dict, i, sizeof(struct directory), bcmp);
            if (NULL == p) printf("eh\n");
            else printf("%s\n", p->e);
        }
    }

    return 0;
}

