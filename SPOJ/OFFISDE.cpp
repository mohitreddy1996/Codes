#include <algorithm>
#include <stdio.h>
#include <map>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
   int n,m;
   while(1)
   {
       scanf("%d %d",&n,&m);
       if(n+m==0)
            break;
        long int a[n+1],b[m+1];
        for(int i=0;i<n;i++)
            scanf("%ld",&a[i]);
        for(int j=0;j<m;j++)
            scanf("%ld",&b[j]);
        sort(a,a+n);
        sort(b,b+m);
        if(a[0]>=b[1])
            printf("N\n");
        else
            printf("Y\n");
   }
return(0);    
}
