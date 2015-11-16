#include <algorithm>
#include <stdio.h>
#include <map>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,m;
    int x,y;
    scanf("%d %d",&n,&m);
    scanf("%d %d",&x,&y);
    int a[n+2][m+2];
    int dp[n+2][m+2]={0};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int energy=a[x][y];
    if(x==n&&y==m)
        printf("Y %d",a[x][y]);
    else
    {
        for(int i=x;i<=n;i++)
        {
            if(i==x)
                dp[i][y]=0;
            else
                dp[i][y]=dp[i-1][y]+a[i][y];
        }
        for(int i=y;i<=m;i++)
        {
            if(i==y)
                dp[x][i]=0;
            else
                dp[x][i]=dp[x][i-1]+a[x][i];
        }
        if(x+1<=n && y+1<=m)
        {
        for(int i=x+1;i<=n;i++)
        {
            for(int j=y+1;j<=m;j++)
            {
                dp[i][j]=a[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        }
        if(dp[n][m]<=energy)
        {
            printf("Y %d",energy-dp[n][m]);
        }
        else
        {
            printf("N");
        }
    }

return(0);    
}
