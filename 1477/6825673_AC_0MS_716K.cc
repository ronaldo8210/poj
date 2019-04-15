#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int n, case_id = 0;
    while ((cin >> n) && (n != 0))
    {
        case_id++;
        int stacks[51] = {0};
        int i, aver, sum = 0, minimum_moved_number = 0;
        for (i = 0; i < n; i++)
        {
            cin >> stacks[i];
            sum += stacks[i];
        }
        
        aver = sum / n;
        
        for (i = 0; i < n; i++)
        {
            if (stacks[i] > aver)
                minimum_moved_number += (stacks[i] - aver);
        }

        cout << "Set #" << case_id << endl;
        cout << "The minimum number of moves is " << minimum_moved_number << "." << endl << endl;
    }

    return 0;
}
