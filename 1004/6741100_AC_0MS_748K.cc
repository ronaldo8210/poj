#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    float money[12] = { 0.0f };
    float sum = 0.0f;

    for (int i = 0; i < 12; i++)
    {
        cin >> money[i];
        sum += money[i];
    }
    printf("$%.02f\n", sum / 12);

    return 0;
}
