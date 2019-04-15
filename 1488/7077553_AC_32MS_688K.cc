#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    string str;
    bool bLeft = true;
    while (getline(cin, str))
    {
        int i, len = str.length();
        for (i = 0; i <= len-1; i++)
        {
            if (str[i] == '"')
            {
                if (bLeft)
                {
                    str.replace(i, 1, "``");
                    len++;
                    bLeft = !bLeft;
                }
                else
                {
                    str.replace(i, 1, "''");
                    len++;
                    bLeft = !bLeft;
                }
            }
        }

        cout << str << endl;
    }

    return 0;
}

