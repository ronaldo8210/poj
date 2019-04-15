#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
        int n,i;
        int a[3005];
        int flag[3005];
        while(scanf("%d",&n)!=EOF)
        {
                memset(flag,0,sizeof(flag));
                for(i=0;i<n;i++)
                        scanf("%d",&a[i]);
                for(i=0;i<n-1;i++)
                {
                        flag[abs(a[i]-a[i+1])]=1;
                }
                for(i=1;i<=n-1;i++)
                        if(flag[i]!=1)
                        {
                                printf("Not jolly\n");
                                break;
                        }
                if(i>=n)
                        printf("Jolly\n");
        }
        return 0;
}
