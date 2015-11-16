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
    int t;
    scanf("%d",&t);
    int k=1;
    while(t--)
    {

        int n;
        scanf("%d",&n);
        long long int temp;
        long long int a[10006];
        long long int dp[10006];
        for(int i=3;i<n+3;i++)
        {
            scanf("%lld",&temp);
            a[i]=temp;
        }
        for(int i=0;i<=10005;i++)
        {
            dp[i]=0;
        }
        for(int i=3;i<n+3;i++)
        {
            dp[i]=max(dp[i-1],max(dp[i-2]+a[i],dp[i-3]+a[i]));
        }
        printf("Case %d: %lld\n",k,dp[n+2]);
        k++;

    }


return(0);
}
