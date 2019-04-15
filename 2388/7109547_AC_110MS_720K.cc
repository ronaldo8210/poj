#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
    int array[10005], N, i;
    cin >> N;
    for (i = 0; i <= N-1; i++)
    {
        cin >> array[i];
    }
    sort(array, array+N);
    cout << array[N/2] << endl;

    return 0;
}

