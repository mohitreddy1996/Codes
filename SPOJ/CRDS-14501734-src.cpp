#include <algorithm>
#include <stdio.h>
#include <map>
#include <string>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
#define mod 1000007
int main()
{
    long long int dp[1000002];
    dp[0]=0;
    for(long int i=1;i<=1000000;i++)
    {
        dp[i]=dp[i-1]+ i-1 + 2*(i);
        if(dp[i]>=mod)
            dp[i]%=mod;
    }
    
   int t;
   
   cin>>t;
   long int n;
   while(t--)
   {
       scanf("%ld",&n);
       printf("%lld\n",dp[n]);
       
   }
   
return(0);    
}
 