#include <iostream>
#include <string>
using namespace std;

bool bvowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    else return false;
}

int main(int argc, char** argv)
{
    string str;
    bool bexit;
    while ((cin >> str) && (str != "end"))
    {
        int i, n;
        n = str.length();
        bexit = false;
        for (i = 0; i <= n-1; i++)
        {
            if (bvowel(str[i]))
                break;
        }
        if (i == n)
        {
            cout << "<" << str << "> is not acceptable." << endl;
            continue;
        }

        for (i = 0; i <= n-3; i++)
        {
            if (bvowel(str[i]) && bvowel(str[i+1]) && bvowel(str[i+2]))
            {
                bexit = true;
                break;
            }
            else if ((!bvowel(str[i])) && (!bvowel(str[i+1])) && (!bvowel(str[i+2])))
            {
                bexit = true;
                break;
            }
        }
        if (bexit)
        {
            cout << "<" << str << "> is not acceptable." << endl;
            continue;
        }

        for (i = 0; i <= n-2; i++)
        {
            if (str[i] == str[i+1])
            {
                if ((str[i] == 'e') || (str[i] == 'o'))
                    continue;
                else
                {
                    bexit = true;
                    break;
                }
            }
        }
        if (bexit)
        {
            cout << "<" << str << "> is not acceptable." << endl;
            continue;
        }

        cout << "<" << str << "> is acceptable." << endl;
    }
    
    return 0;
}

