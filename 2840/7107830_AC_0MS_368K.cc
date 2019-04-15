#include <cstdio>
using namespace std;

int main(int argc, char** argv)
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int H, M;
        scanf("%d:%d", &H, &M);
        if (M != 0)
            printf("0\n");
        else if (H >= 0 && H <= 12)
            printf("%d\n", H + 12);
        else
            printf("%d\n", H - 12);
    }

    return 0;
}

