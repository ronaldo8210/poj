#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int n;
    while ((cin >> n) && (n != -1))
    {
        int s, t, total = 0, t_pre = 0;
        while (n--)
        {
            cin >> s >> t;
            total += s * (t - t_pre);
            t_pre = t;
        }
        cout << total << " miles" << endl;
    }

    return 0;
}

