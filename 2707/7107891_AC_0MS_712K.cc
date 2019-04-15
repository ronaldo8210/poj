#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int A, B, C, D, min1, min2;
    while (1)
    {
        cin >> A >> B >> C >> D;
        if (A == 0 && B == 0 && C == 0 && D == 0)
            break;

        min1 = (C < D ? C : D)*100 / (A < B ? A : B);
        min2 = (C > D ? C : D)*100 / (A > B ? A : B);
        if (min1 > min2)
            min1 = min2;
        if (min1 <= 0)
            min1 = 1;
        else if (min1 > 100)
            min1 = 100;
        cout << min1 << "%" << endl;
    }

    return 0;
}

