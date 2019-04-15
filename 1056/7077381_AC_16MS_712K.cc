#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(const string &a, const string &b)
{
    return (a.length() < b.length());
}

int main(int argc, char** argv)
{
    string str;
    int number = 0;
    while (cin >> str)
    {
        number++;
        string array[8];
        int i = 0, j, k;
        bool bExit = false;
        
        array[i++] = str;
        while (cin >> str && str != "9")
        {
            array[i++] = str;
        }
        sort(array, array+i, cmp);
        for (j = 0; j <= i-2; j++)
        {
            for (k = j+1; k <= i-1; k++)
            {
                if (array[k].substr(0, array[j].length()) == array[j])
                {
                    bExit = true;
                    break;
                }
            }
            if (bExit) break;
        }

        if (!bExit)
            cout << "Set " << number << " is immediately decodable" << endl;
        else
            cout << "Set " << number << " is not immediately decodable" << endl;
    }

    return 0;
}
