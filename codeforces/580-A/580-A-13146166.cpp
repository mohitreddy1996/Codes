#include <algorithm>
#include <stdio.h>
#include <map>
#include <math.h>
#include <stack>
#include <string.h>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;
#define mod 1000000007
#define MAX 10001
#define inf 1e9
#define inf 1000000000

int main()
{
   long long int a[100004];
   int n;
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }
   long long int prev=0;
   int temp=0;
   int max1=0;
   for(int i=0;i<n;i++)
   {
       if(a[i]>=prev)
       {
           prev=a[i];
           temp++;
       }
       else
       {
           max1=max(max1,temp);
           prev=a[i];
           temp=1;
       }
   }
   cout<<max(max1,temp);

return 0;
}