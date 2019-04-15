#include <iostream>
#include <cmath>
using namespace std;

#define pi 3.1415926

int main(int argc, char** argv)
{
    int N, testid = 0;
    cin >> N;
    while (N-- > 0)
    {
        testid++;
        float x = 0.0, y = 0.0, area = 0.0, radius = 0.0;
        int year;
        
        cin >> x >> y;
        radius = sqrt(x*x + y*y);
        area = pi * radius * radius / 2;
        year = (int)(area/50) + 1;
        cout << "Property " << testid << ": This property will begin eroding in year " << year << "." << endl;
    }
    cout << "END OF OUTPUT." << endl;

    return 0;
}
