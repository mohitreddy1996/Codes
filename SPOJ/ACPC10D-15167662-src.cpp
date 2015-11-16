#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int k=1;
    while(1)
    {


    int n;
    scanf("%d",&n);
    if(n==0)
        break;
    int a[n+1][3];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
    }
    long long int dp[n+1][3];
    dp[0][0]=1e8;
    dp[0][1]=a[0][1];
    dp[0][2]=a[0][1]+a[0][2];
    for(int i=1;i<n;i++)
    {
        dp[i][0]=min(a[i][0]+dp[i-1][0],a[i][0]+dp[i-1][1]);
        dp[i][1]=min(a[i][1]+dp[i-1][0],min(a[i][1]+dp[i-1][1],a[i][1]+dp[i-1][2]));
        dp[i][1]=min(dp[i][1],dp[i][0]+a[i][1]);
        dp[i][2]=min(a[i][2]+dp[i-1][1],a[i][2]+dp[i-1][2]);
        dp[i][2]=min(dp[i][2],min(dp[i][0]+a[i][1]+a[i][2],dp[i][1]+a[i][2]));
        //cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<"\n";

    }
    long long ans=dp[n-1][1];
    printf("%d. %lld\n",k,ans);
    k++;
    }
return 0;
}
