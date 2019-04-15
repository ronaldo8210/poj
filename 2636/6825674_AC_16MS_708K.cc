#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int t, a, sum, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        sum = 1 - n;
        for(int i = 0; i < n; i++)
        {
            cin >> a;
            sum += a;
        }
        cout << sum << endl;
    }
}
