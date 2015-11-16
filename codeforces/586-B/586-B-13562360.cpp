#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int a[2][51],b[51];
    scanf("%d",&n);
    for(int i=0;i<2;i++)
    {
        for(int j=1;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    for(int j=0;j<n;j++)
    {
        scanf("%d",&b[j]);
    }
    int dp[52];
    int sum[2][52];
    sum[0][0]=0;
    sum[1][0]=b[0];
    for(int j=1;j<n;j++)
    {
        sum[0][j]=sum[0][j-1]+a[0][j];
        sum[1][j]=sum[1][j-1]+a[1][j];
    }

    dp[0]=sum[1][n-1];
    for(int j=1;j<n;j++)
    {
        dp[j]=sum[0][j]+sum[1][n-1]-sum[1][j]+b[j];
    }

    sort(dp,dp+n);
    //cout<<endl;
    cout<<dp[0]+dp[1];
}