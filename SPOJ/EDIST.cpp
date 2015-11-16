#include <algorithm>
#include <stdio.h>
#include <map>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    char a[2002],b[2002];
    static int dp[2002][2002];
    cin>>t;
    while(t--)
    {
        scanf("%s",a);
        scanf("%s",b);
        int len1=strlen(a);
        int len2=strlen(b);
        for(int i=0;i<=len1;i++)
        dp[i][0]=i;
        for(int i=0;i<=len2;i++)
        dp[0][i]=i;
        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                dp[i][j]=min(dp[i-1][j]+1,min(dp[i][j-1]+1, a[i-1]==b[j-1]?dp[i-1][j-1]:dp[i-1][j-1]+1 ));
            }
        }
        cout<<dp[len1][len2]<<"\n";
        
    }
    
    
return(0);    
}
