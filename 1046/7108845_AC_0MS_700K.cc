#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char** argv)
{
    struct RGB {
        int R, G, B;
    };

    RGB array[16];
    int i;
    for (i = 0; i <= 15; i++)
        cin >> array[i].R >> array[i].G >> array[i].B;
    RGB color;
    while (1)
    {
        int j, D = 9999999, t;
        cin >> color.R >> color.G >> color.B;
        if (color.R == -1 && color.G == -1 && color.B == -1) break;
        for (i = 0; i <= 15; i++)
        {
            t = (color.R-array[i].R)*(color.R-array[i].R) +
                (color.G-array[i].G)*(color.G-array[i].G) +
                (color.B-array[i].B)*(color.B-array[i].B);
            if (t < D)
            {
                D = t;
                j = i;
            }
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n", color.R, color.G, color.B, array[j].R, array[j].G, array[j].B);
    }

    return 0;
}

