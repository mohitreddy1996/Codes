#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int t;
    long int n;
    long int temp;
    long int a[100002];
    long int mini,maxd;
    scanf("%d",&t);
    while(t--)
    {
        mini=1000001;maxd=0;
        scanf("%ld",&n);
        for(long int i=0;i<n;i++)
        {
            scanf("%ld",&a[i]);
            mini=min(mini,a[i]);
            maxd=max(maxd,a[i]-mini);
            
        }
        if(maxd!=0)
        {
            printf("%ld\n",maxd);
        }
        else
        {
            printf("UNFIT\n");
        }
            
    }
return(0);    
}
