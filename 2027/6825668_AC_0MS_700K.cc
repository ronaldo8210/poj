#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int n = 0, x = 0, y = 0;
    cin >> n;
    while (n--)
    {
        cin >> x >> y;
        if (x >= y)
            cout << "MMM BRAINS" << endl;
        else 
            cout << "NO BRAINS" << endl;
    }

    return 0;
}
