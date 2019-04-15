#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    string str;
    while (1)
    {
        int i, len;
        getline(cin, str);
        if (str == "#") break;
        len = str.length();
        for (i = 0; i <= len-1; i++)
        {
            if (str[i] == ' ')
                cout << "%20";
            else if (str[i] == '!')
                cout << "%21";
            else if (str[i] == '$')
                cout << "%24";
            else if (str[i] == '%')
                cout << "%25";
            else if (str[i] == '(')
                cout << "%28";
            else if (str[i] == ')')
                cout << "%29";
            else if (str[i] == '*')
                cout << "%2a";
            else 
                cout << str[i];
        }
        cout << endl;
    }

    return 0;
}

