#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char** argv)
{
    char szLine[128] = {0};
    char szOCity[32] = {0};
    char szDCity[32] = {0};
    int miles;
    char code;
    int sum = 0;
    
    while (1)
    {
        fgets(szLine, sizeof(szLine), stdin);
        if (0 == strcmp(szLine, "#\n")) break;
        else if (0 == strcmp(szLine, "0\n"))
        {
            printf("%d\n", sum);
            sum = 0;
        }
        else
        {
            sscanf(szLine, "%s %s %d %c", &szOCity, &szDCity, &miles, &code);
            switch (code)
            {
                case 'F':
                    sum += miles * 2;
                    break;
                case 'B':
                    sum += (int)(miles * 1.5 + 0.5);
                    break;
                case 'Y':
                    if (miles <= 500) sum += 500;
                    else sum += miles;
                    break;
                default:
                    break;
            }
            memset(szLine, 0, sizeof(szLine));
            memset(szOCity, 0, sizeof(szOCity));
            memset(szDCity, 0, sizeof(szDCity));
        }
    }

    return 0;
}

