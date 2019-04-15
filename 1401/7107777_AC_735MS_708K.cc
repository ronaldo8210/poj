#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int N;
    cin >> N;
    while (N--)
    {
        int a, sum = 0;
        cin >> a;
        while (a > 0)
        {
            sum += a / 5;
            a = a / 5;
        }
        cout << sum << endl;
    }

    return 0;
}

