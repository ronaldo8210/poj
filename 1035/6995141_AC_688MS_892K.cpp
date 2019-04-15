#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

map<string, int> directory;
set<string> rep;

class newstring
{
public:
    string str;
    newstring(string s) {str = s;}
    bool operator < (const newstring& b) const
    {
        return (directory[str] < directory[b.str]);
    }
    friend ostream& operator << (ostream& os, newstring b)
    {
        os << b.str;
        return os;
    }
};
vector<newstring> rep2;

int main(int argc, char** argv)
{
    string word, str, opstr;
    int offset = 0;
    
    while ((cin >> word) && (word != "#"))
    {        
        offset++;
        directory.insert(make_pair(word, offset));     
    }

    while ((cin >> word) && (word != "#"))
    {        
        int i, j, len;
        rep.clear();
        rep2.clear();

        if (directory.find(word) != directory.end())
        {
            cout << word << " is correct" << endl;
            continue;
        }

        cout << word << ": ";
        len = word.length();
        for (i = 0; i <= len-1; i++)
        {
            str = word;
            str.replace(i, 1, "");
            if (directory.find(str) != directory.end()) rep.insert(str);
        }

        for (i = 0; i <= len-1; i++)
        {
            for (j = 97; j <= 97+25; j++)
            {
                str = word;
                opstr = (char)j;
                str.replace(i, 1, opstr);
                if (directory.find(str) != directory.end()) rep.insert(str);
            }
        }

        for (i = 0; i <= len; i++)
        {
            for (j = 97; j <= 97+25; j++)
            {
                str = word.substr(0, i) + (char)j + word.substr(i);
                if (directory.find(str) != directory.end()) rep.insert(str);
            }
        }

        set<string>::iterator iter = rep.begin();
        while (iter != rep.end())
            rep2.push_back(newstring(*iter++));
        sort(rep2.begin(), rep2.end());
        vector<newstring>::iterator iter2 = rep2.begin();
        while (iter2 != rep2.end())
            cout << *iter2++ << " ";
        cout << endl;
    }   
    
    return 0;
}
