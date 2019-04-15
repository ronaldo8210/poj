#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(int argc, char** argv)
{
    string l1, l2;
    int n;
    scanf("%d\n", &n);
    //cin.sync();
    //getchar();
    while (n--)
    {
        getline(cin, l1);
        getline(cin, l2);
        string temp, p1, p2;
        int pos1, pos2, pos3, pos4, pos5;
        pos1 = l1.find('<');
        pos2 = l1.find('>');
        p1 = l1.substr(pos1+1, pos2-pos1-1);
        pos3 = l1.rfind('<');
        pos4 = l1.rfind('>');
        p2 = l1.substr(pos3+1, pos4-pos3-1);
        temp = l1;
        l1.erase(pos1, 1);
        pos5 = l1.find('>');
        l1.erase(pos5, 1);
        pos5 = l1.find('<');
        l1.erase(pos5, 1);
        pos5 = l1.find('>');
        l1.erase(pos5, 1);
        
        temp.replace(pos1, pos2-pos1+1, p2);
        pos3 = temp.find('<');
        pos4 = temp.find('>');
        temp.replace(pos3, pos4-pos3+1, p1);
        pos3 = l2.find("...");
        p1 = l2.substr(0, pos3);
        temp.replace(0, pos1, p1);

        cout << l1 << endl;
        cout << temp << endl;
    }

    return 0;
}

