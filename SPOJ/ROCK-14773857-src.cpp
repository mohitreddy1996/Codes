#include <algorithm>
#include <stdio.h>
#include <utility>
#include <map>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
char ch[205];
int dp1[205][205];
int siz[205];
int dp(int i,int j)
{
    if(i>j)
    {
        return 0;
    }
    if(i==j)
    {
        return ch[i]-'0';
    }
    if(dp1[i][j]!=-1)
    {
        return dp1[i][j];
    }
    if(siz[j+1]-siz[i] >(j-i+1)/2)
    {
        return dp1[i][j]=max(dp1[i][j],(j-i+1));
    }
    else
    {
        for(int k=i;k<j;k++)
        {
            int cal=dp(i,k)+dp(k+1,j);
        //cout<<i<<" "<<k<<" "<<j<<" cal: "<<cal<<" \n";
            dp1[i][j]=max(cal,dp1[i][j]);
        }
        return dp1[i][j];
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",ch);
        siz[0]=0;
        for(int i=0;i<n;i++)
        {
            siz[i+1]=siz[i]+(ch[i]-'0');
        }
        memset(dp1,-1,sizeof(dp1));
        printf("%d\n",dp(0,n-1));
    }


return(0);
}
