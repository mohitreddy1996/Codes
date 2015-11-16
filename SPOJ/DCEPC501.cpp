#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    long long int n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        long long a[n+7];
        long long dp[n+7];
        for(long long i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        a[n]=a[n+1]=a[n+2]=a[n+3]=a[n+4]=a[n+5]=a[n+6]=0;
        dp[n]=dp[n+1]=dp[n+2]=dp[n+3]=dp[n+4]=dp[n+5]=dp[n+6]=0;
        
        for(int i=n-1;i>=0;i--)
        {
            dp[i]=a[i]+dp[i+2];
            if(i+1<n)
                dp[i]=max(dp[i],a[i]+a[i+1]+dp[i+4]);
            if(i+2<n)  
                dp[i]=max(dp[i],a[i]+a[i+1]+a[i+2]+dp[i+6]);
        }
        cout<<dp[0]<<"\n";
    }
    
    
return(0);    
}
