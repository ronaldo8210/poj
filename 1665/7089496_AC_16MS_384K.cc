#include <cstdio>
using namespace std;

const float Pi = 3.1415927;

int main(int argc, char** argv)
{
    float diameter, time, distance, MPH;
    int revolutions, n = 0;
    
    while (scanf("%f %d %f", &diameter, &revolutions, &time) && (revolutions != 0))
    {
        n++;
        distance = (diameter * revolutions * Pi) / (12 * 5280);
        MPH = (distance * 3600) / time;
        printf("Trip #%d: %.2f %.2f\n", n, distance, MPH); 
    }

    return 0;
}


