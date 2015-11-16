#include <algorithm>
#include <stdio.h>
#include <utility>
#include <map>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
int color[102];
int a[102];
int dp1[102][102];
int dp(int i,int j)
{
    if(i>=j)
        return 0;
    if(dp1[i][j]!=-1)
    {
        return dp1[i][j];
    }
    for(int k=i;k<j;k++)
    {
        int cal=((color[j+1]-color[k+1])%100)*((color[k+1]-color[i])%100)+dp(i,k)+dp(k+1,j);
        if(dp1[i][j]==-1)
        {
            dp1[i][j]=cal;
        }
        else
        {
            dp1[i][j]=min(cal,dp1[i][j]);
        }
    }
    return dp1[i][j];
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(dp1,-1,sizeof(dp1));
        
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        color[0]=0;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                color[i+1]=a[i];
            }
            else
            {
                color[i+1]=color[i]+a[i];
            }
        }
        cout<<dp(0,n-1)<<"\n";
        
    }


return(0);
}
