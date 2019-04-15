#include <iostream>
#include <string>
using namespace std;

string strLine;

void convert(string& strLine)
{
    int i;
    int n = strLine.length();
    for (i = 0; i <= n-1; i++)
    {
        switch (strLine[i])
        {
            case 'A':
                strLine[i] = 'V';
                break;
            case 'B':
                strLine[i] = 'W';
                break;
            case 'C':
                strLine[i] = 'X';
                break;
            case 'D':
                strLine[i] = 'Y';
                break;
            case 'E':
                strLine[i] = 'Z';
                break;
            case 'F':
                strLine[i] = 'A';
                break;
            case 'G':
                strLine[i] = 'B';
                break;
            case 'H':
                strLine[i] = 'C';
                break;
            case 'I':
                strLine[i] = 'D';
                break;
            case 'J':
                strLine[i] = 'E';
                break;
            case 'K':
                strLine[i] = 'F';
                break;
            case 'L':
                strLine[i] = 'G';
                break;
            case 'M':
                strLine[i] = 'H';
                break;
            case 'N':
                strLine[i] = 'I';
                break;
            case 'O':
                strLine[i] = 'J';
                break;
            case 'P':
                strLine[i] = 'K';
                break;
            case 'Q':
                strLine[i] = 'L';
                break; 
            case 'R':
                strLine[i] = 'M';
                break;
            case 'S':
                strLine[i] = 'N';
                break;
            case 'T':
                strLine[i] = 'O';
                break;
            case 'U':
                strLine[i] = 'P';
                break;
            case 'V':
                strLine[i] = 'Q';
                break;
            case 'W':
                strLine[i] = 'R';
                break;
            case 'X':
                strLine[i] = 'S';
                break;
            case 'Y':
                strLine[i] = 'T';
                break;
            case 'Z':
                strLine[i] = 'U';
                break;
            default:
                break;
        }
    }
}

int main(int argc, char** argv)
{
    while (getline(cin, strLine))
    {
        if (strLine == "ENDOFINPUT") break;
        else if ((strLine == "START") || (strLine == "END")) continue;
        else
        {
            convert(strLine);
            cout << strLine << endl;
        }
    }

    return 0;
}
