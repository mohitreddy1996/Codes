#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    
    int t;
    int h,w;
    int dp[102][102];
    int a[102][102];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&h,&w);
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(int j=0;j<w;j++)
        {
            dp[0][j]=a[0][j];
        }
        for(int i=1;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(j==0)
                    dp[i][j]=a[i][j]+max(dp[i-1][j+1],dp[i-1][j]);
                else if(j==w-1)
                    dp[i][j]=a[i][j]+max(dp[i-1][j-1],dp[i-1][j]);
                else
                    dp[i][j]=a[i][j]+max(max(dp[i-1][j-1],dp[i-1][j+1]),dp[i-1][j]);
            }
        }
        int max1=dp[h-1][0];
        for(int i=0;i<w;i++)
        {
            max1=max(max1,dp[h-1][i]);
        }
        printf("%d\n",max1);
    }
    
return(0);    
}
