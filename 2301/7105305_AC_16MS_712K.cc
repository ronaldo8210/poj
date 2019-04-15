#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int n;
    cin >> n;
    while (n--)
    {
        int s, d, a, b;
        cin >> s >> d;
        if ((s+d)%2 == 1 || (s < d))
            cout << "impossible" << endl;
        else
            cout << (s+d)/2 << " " << (s-d)/2 << endl;
    }
    
    return 0;
}

