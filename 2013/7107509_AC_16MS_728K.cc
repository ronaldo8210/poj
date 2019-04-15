#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    int n, index = 0;
    while ((cin >> n) && (n != 0))
    {
        string array[15];
        int i;
        for (i = 0; i <= n-1; i++)
        {
            cin >> array[i];
        }

        index++;
        cout << "SET " << index << endl;
        for (i = 0; i <= n-1; i+=2)
            cout << array[i] << endl;
        for (i = n-1-n%2; i > 0; i-=2)
            cout << array[i] << endl;
    }

    return 0;
}

