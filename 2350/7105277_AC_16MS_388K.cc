#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
    int C;
    scanf("%d", &C);
    while (C--)
    {
        int N, i;
        float array[1005], sum = 0.0, avg, count = 0.0;
        scanf("%d", &N);
        for (i = 0; i <= N-1; i++)
        {
            scanf("%f", &array[i]);
            sum += array[i];
        }
        avg = sum / N;
        sort(array, array+N);
        for (i = N-1; i >= 0; i--)
        {
            if (array[i] <= avg) break;
            count++;
        }
        printf("%.3f%c\n", (count/N)*100, '%');
    }
    
    return 0;
}

