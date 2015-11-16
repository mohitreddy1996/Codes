#include <algorithm>
#include <stdio.h>
#include <limits.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {
        long long int initw,finw;
        long long int n;
        scanf("%lld %lld",&initw,&finw);
        scanf("%lld",&n);
        long long int val[n+2],wt[n+2];
        for(int i=0;i<n;i++)
        {
            scanf("%lld %lld",&val[i],&wt[i]);
        }
        long long int diff=finw-initw;
        long long int L[10050];
        if(diff)
        {
            L[0]=0;
        for(long long int i=1;i<=diff;i++)
        {   L[i]=LLONG_MAX;
            for(long long int j=0;j<n;j++)
            {
                if(i>=wt[j])
                {
                    if(L[i-wt[j]]!=LLONG_MAX)
                        L[i]=min(L[i],L[i-wt[j]]+val[j]);
                    
                }
            }
        }
        
        
    		 if(L[diff]!=LLONG_MAX)
    		 {
            printf("The minimum amount of money in the piggy-bank is %lld.\n",L[diff]);
        	}
        	else
        	{
            printf("This is impossible.\n");
        	}
        }
        else
        {
            printf("This is impossible.\n");
        }
    }
    
return(0);    
}
