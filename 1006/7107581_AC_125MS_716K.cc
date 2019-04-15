#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int p, e, i, d, a, index = 0;
    while (1)
    {
        cin >> p >> e >> i >> d;
        if (p == -1 && e == -1 && i == -1 && d == -1) break;
        a = (5544*p + 14421*e + 1288*i - d + 21252) % 21252;
        if (!a) a = 21252;
        index++;
        cout << "Case " << index << ": the next triple peak occurs in " << a << " days." << endl;
    }

    return 0;
}

