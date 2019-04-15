#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int length_road, M;
    while ((cin >> length_road) && (cin >> M) && (length_road != 0) && (M != 0))
    {
        int start, end, left = length_road + 1;
        while (M > 0)
        {
            M--;
            cin >> start >> end;
            left -= (end - start + 1);
        }
        cout << left << endl;
    }

    return 0;
}
