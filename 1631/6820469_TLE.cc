#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int testnum;
    cin >> testnum;
    while (testnum--)
    {
        int N;
        int index = 0, array[40001] = {0}, a[40001] = {0};
        int total = 0, l, r, mid;
        
        cin >> N;
        for (index = 0; index <= N-1; index++)
        {
            cin >> array[index];
        }
        
        a[0] = array[0];
        total = 1;
        for (index = 1; index <= N-1; index++)
        {
            l = 0;
            r = total - 1;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (a[mid] <= array[index])
                    l = mid + 1;
                else 
                    r = mid - 1;
            }
            if (l >= total) total++;
            a[l] = array[index];
        }
        
        cout << total << endl;
    }

    return 0;
}
