#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long int n,m;
    long int a[100005];
    long int h[100005];
    long int v[100005];
    while(1)
    {
        scanf("%ld %ld",&n,&m);
        if(n==0||m==0)
            break;
        for(long int i=0;i<n;i++)
        {
            for(long int j=0;j<m;j++)
            {
                scanf("%ld",&a[j]);
            }
            h[m]=h[m+1]=0;
            for(long int j=m-1;j>=0;j--)
            {
                h[j]=max(a[j]+h[j+2],h[j+1]);
            }
            v[i]=h[0];
        }
        h[n]=h[n+1]=0;
        for(long int i=n-1;i>=0;i--)
        {
            h[i]=max(h[i+2]+v[i],h[i+1]);
        }
        printf("%ld\n",h[0]);
    }    
    
return(0);    
}
