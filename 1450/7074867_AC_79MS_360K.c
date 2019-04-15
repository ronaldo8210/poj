#include <stdio.h>

int main(int argc, char** argv)
{
    int testcases;
    int m, n, i, number = 0;
    scanf("%d", &testcases);
    while (testcases--)
    {
        number++;
        scanf("%d %d", &m, &n);
        i = m*n;
        printf("Scenario #%d:\n", number);
        if (!(i%2))
            printf("%d.00\n\n", i);
        else
            printf("%d.41\n\n", i);
    }
    
    return 0; 
}
