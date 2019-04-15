#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    string key, ciphertext;
    int key_len, row;
    while ((cin >> key) && (key != "THEEND"))
    {
        char array[10][10];
        int i, j, k, p, q;
        cin >> ciphertext;
        key_len = key.length();
        row = ciphertext.length() / key_len;
        for (i = 0; i <= key_len-1; i++)
        {
            k = 0;
            for (j = 0; j <= key_len-1; j++)
            {
                if (j == i) continue;
                if (key[j] < key[i])
                {
                    k++;
                }
                else if (key[j] == key[i])
                {
                    if (j < i)
                        k++;
                }
            }
            
            q = row * k;
            for (p = 0; p <= row-1; p++)
                array[p][i] = ciphertext[q++];
        }

        for (p = 0; p <= row-1; p++)
        {
            for (q = 0; q <= key_len-1; q++)
                cout << array[p][q];
        }
        cout << endl;
    }

    return 0;
}

