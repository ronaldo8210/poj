#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main(int argc, char** argv)
{
    int N, i, array[1001];
    while ((cin >> N) && (N != 0))
    {        
        while (1)
        {
            stack<int> s;
            memset(array, 0, sizeof(array));
            cin >> array[1];
            if (array[1] == 0) break;
            for (i = 2; i <= N; i++)
            {
                cin >> array[i];
            }
            
            int A = 1, B = 1, ok = 1;
            while (B <= N)
            {
                if (A == array[B]) {A++; B++;}
                else if (!s.empty() && s.top() == array[B]) {s.pop(); B++;}
                else if (A <= N) {s.push(A++);}
                else {ok = 0; break;}
            }
            if (ok) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        cout << endl;
    }

    return 0;
}
