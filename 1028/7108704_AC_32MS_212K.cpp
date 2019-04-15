#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(int argc, char** argv)
{
    string command, cur_url, new_url;
    stack<string> for_stack;
    stack<string> back_stack;
    cur_url = "http://www.acm.org/";
    while (cin >> command)
    {
        if (command == "QUIT") break;
        else if (command == "BACK")
        {
            if (back_stack.empty())
                cout << "Ignored" << endl;
            else 
            {
                for_stack.push(cur_url);
                cur_url = back_stack.top();
                back_stack.pop();
                cout << cur_url << endl;
            }
        }
        else if (command == "FORWARD")
        {
            if (for_stack.empty())
                cout << "Ignored" << endl;
            else
            {
                back_stack.push(cur_url);
                cur_url = for_stack.top();
                for_stack.pop();
                cout << cur_url << endl;
            }
        }
        else if (command == "VISIT")
        {
            cin >> new_url;
            back_stack.push(cur_url);
            cur_url = new_url;
            while (!for_stack.empty())
            {
                for_stack.pop();
            }
            cout << cur_url << endl;
        }        
    }

    return 0;
}

