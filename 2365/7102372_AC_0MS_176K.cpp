#include <cstdio>
#include <cmath>
using namespace std;

const int size = 101;
struct point {
    double x, y;
} p[size];

int main(int argc, char** argv)
{
    int i, top, n, s[size];
    double r, len = 0;
    scanf("%d%lf", &n, &r);

    for (i = 0; i < n; i++)
        scanf("%lf%lf", &p[i].x, &p[i].y);

    for (i = 0; i < n; i++)
        len += sqrt((p[i%n].x - p[(i+1)%n].x) * (p[i%n].x - p[(i+1)%n].x) + (p[i%n].y - p[(i+1)%n].y) * (p[i%n].y - p[(i+1)%n].y));

    printf("%.2lf\n", len + 2*acos(double(-1))*r);

    return 0;
}

