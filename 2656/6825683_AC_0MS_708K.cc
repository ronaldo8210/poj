#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int n;
	while((cin >> n) && (n != 0)) 
    {
		int i;
		int maxday, maxvalue = -1;
		for (i = 1; i <= n; i++) 
        {
			int a, b;
			cin >> a >> b;
			if ((a + b) > maxvalue) 
            {
				maxvalue = a + b;
				maxday = i;
			}
		}
		if (maxvalue <= 8) cout << "0" << endl;
		else cout << maxday << endl;
	}
	return 0;
}