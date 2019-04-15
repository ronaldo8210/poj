#include<iostream>
#include <string.h>
 
using namespace std;
const int MAXN = 201;
 
int main()
{
    bool array[MAXN][MAXN];
    char str1[MAXN], str2[MAXN], str3[2 * MAXN];
    int i, j, n, test = 0;
    scanf("%d", &n);
    getchar();
    while(n --) {
        scanf("%s%s%s", str1 + 1, str2 + 1, str3 + 1);
        int str1_len = strlen(str1 + 1);
        int str2_len = strlen(str2 + 1);
        array[0][0] = true;
        for(i = 1; i <= str1_len; i ++) {
            if(array[i - 1][0] && str1[i] == str3[i])
            {
                array[i][0] = true;
                printf("array[%d][0]=true\n", i, 0, array[i][0]);
            }
            else
                array[i][0] = false;
        }
        for(i = 1; i <= str2_len; i ++) {
            if(array[0][i - 1] && str2[i] == str3[i])
            {
                array[0][i] = true;
                printf("array[0][%d]=true\n", 0, i, array[0][i]);
            }
            else
                array[0][i] = false;
        }
        for(i = 1; i <= str1_len; i ++) {
            for(j = 1; j <= str2_len; j ++) {
                if((array[i - 1][j] && str1[i] == str3[i + j]) ||
                        array[i][j - 1] && str2[j] == str3[i + j]) {
                    array[i][j] = true;
                    printf("array[%d][%d]=true\n", i, j, array[i][j]);
                }else {
                    array[i][j] = false;
                }
            }
        }
        if(array[str1_len][str2_len])
            printf("Data set %d: yes\n", ++ test);
        else
            printf("Data set %d: no\n",++ test);
    }
    return(0);
}