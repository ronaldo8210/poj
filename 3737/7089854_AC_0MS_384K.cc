#include <cstdio>
#include <cmath>
using namespace std;

const float Pi = 3.1415927;

int main(int argc, char** argv)
{
    float S, V, r, h, l;
    while (scanf("%f", &S) != EOF)
    {
        r = sqrt(S / (4 * Pi));
        l = S / (Pi * r) - r;
        h = sqrt(l * l - r * r);
        V = (1.0 / 3) * Pi * r * r * h;
        printf("%.2f\n%.2f\n%.2f\n", V, h, r);
    }    

    return 0;
}

