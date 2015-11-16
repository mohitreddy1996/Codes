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
    long long int k;
    long long int temp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%ld %lld",&n,&k);
        long long int count1=0;
        for(long int i=0;i<n;i++)
        {
            scanf("%lld",&temp);
            
            if((temp%k)!=0)
            {
                if(temp/k==0)
                {
                    count1=count1+(k-temp);
                }
                else if((temp%k)>(k/2))
                {
                    count1=count1+(k-(temp%k));
                }
                else
                {
                    count1=count1+(temp%k);
                }
            }
            
        }
        printf("%lld\n",count1);
        
    }
return(0);    
} 
