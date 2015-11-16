#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

int main()
{   
    int n;
    int a[1003],b[1003];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        sort(a,a+n);
        sort(b,b+n);
        long long int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+a[i]*b[i];
        }
        printf("%lld\n",sum);
    }    
return(0);    
}