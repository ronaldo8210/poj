#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    float c;
    while ((cin >> c) && (c != 0.00))
    {
        int n = 1;
        float sum = 0.5;
        while (sum < c)
        {
            n++;
            sum += (float)1 / ((n+1)*1.0);
        }
        cout << n << " card(s)" << endl;
    }
    
    return 0;
}

