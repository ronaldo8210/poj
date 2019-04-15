#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int firstnum, testid = 0;
    while ((cin >> firstnum) && (firstnum != -1))
    {
        int inputnum, totalnum = 1, index, array[10000] = {0};
        int p, q, max = 0;
        testid++;
        array[0] = firstnum;
        while ((cin >> inputnum) && (inputnum != -1))
        {
            array[totalnum++] = inputnum;
        }

        int intercept[10000] = {0};
        intercept[totalnum-1] = 1;
        for (p = totalnum-2; p >= 0; p--)
        {
            int value = 0;
            for (q = p+1; q <= totalnum-1; q++)
            {
                if (array[p] > array[q])
                {
                    if (intercept[q] > value)
                        value = intercept[q];
                }
            }
            intercept[p] = value + 1;
        }
    
        for (index = 0; index <= totalnum-1; index++)
        {
            if (max < intercept[index])
                max = intercept[index];
        }

        cout << "Test #" << testid << ":" << endl;
        cout << "  maximum possible interceptions: " << max << endl << endl;
    }
    
    return 0;
}
