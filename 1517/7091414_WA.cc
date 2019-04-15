#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char** argv)
{
    int i, j, m;
    double sum = 2.5;
    cout << "n e" << endl;
    cout << "- -----------" << endl;
    cout << "0 1" << endl;
    cout << "1 2" << endl;
    cout << "2 2.5" << endl;
    
    for (i = 3; i <= 9; i++)
    {
        m = 1;
        for (j = 2; j <= i; j++)
        {
            m *= j; 
        }
        sum += 1 / (double)m;
        printf("%d %.9lf\n", i, sum);
    }
    
    return 0;
}

