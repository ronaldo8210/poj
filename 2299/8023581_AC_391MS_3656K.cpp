#include <iostream>
using namespace std;

const int N=500000;
__int64 cnt;

int a[N],b[N];

void Merge(int begin,int mid,int end)
{
 int i,j,k=0;
 for(i=begin,j=mid+1;i<=mid && j<=end;k++)
 {
  if(a[i]<=a[j])
   b[k]=a[i++];
  else
  {
   b[k]=a[j++];
   cnt+=mid-i+1;
  }
 }
 for(;i<=mid;i++)
  b[k++]=a[i];
 for(;j<=end;j++)
  b[k++]=a[j];
 for(i=0;i<k;i++)
  a[begin+i]=b[i];
}

void MSort(int b,int e)
{
 if(b>=e)
  return ;
 int m=(b+e)>>1;
 MSort(b,m);
 MSort(m+1,e);
 Merge(b,m,e);
}

int main()
{
 int n;
 while(scanf("%d",&n),n)
 {
  int i;
  for(i=0;i<n;i++)
   scanf("%d",a+i);
  cnt=0;
  MSort(0,n-1);
  printf("%I64d\n",cnt);
 }
 return 0;
}