#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int N, index = 0, array[1001] = {0}, w[1001] = {0};
    int p, q, max = 0;
    
    cin >> N;
    for (index = 0; index <= N-1; index++)
    {
        cin >> array[index];
    }
    
    w[N-1] = 1;
    
    for (p = N-2; p >= 0; p--)
    {
        int value = 0;
        for (q = p+1; q <= N-1; q++)
        {
            if (array[p] < array[q])
            {
                if (w[q] > value)
                    value = w[q];
            }
        }
        w[p] = value + 1;
    }
    
    for (index = 0; index <= N-1; index++)
    {
        if (w[index] > max)
            max = w[index];
    }

    cout << max << endl;
    
    return 0;
}
