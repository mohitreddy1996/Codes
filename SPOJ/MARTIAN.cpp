#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

int n,m;
int dp[502][502];
int sum[2][502][502];

int solve()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int temp1=sum[0][i][j];
            int temp2=sum[1][i][j];
            if(j>0)
                temp1+=dp[i][j-1];
            if(i>0)
                temp2=temp2+dp[i-1][j];
            dp[i][j]=max(temp1,temp2);    
        }
    }
    return dp[n-1][m-1];
}
int main()
{
    int temp;
    while(1)
    {
    
    scanf("%d %d",&n,&m);
    if(n==0&&m==0)
        break;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&temp);
            sum[1][i][j]=temp;
            if(j>0)
                sum[1][i][j]+=sum[1][i][j-1];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&temp);
            sum[0][i][j]=temp;
            if(i>0)
                sum[0][i][j]+=sum[0][i-1][j];
        }
    }
    printf("%d\n",solve());
    }
    
return(0);    
}
