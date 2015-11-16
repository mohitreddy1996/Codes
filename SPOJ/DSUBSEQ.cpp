#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
#define mod 1000000007
long long int dp[100005];
int main()
{
    
    int t;
    char ch[100005];
    cin>>t;
    int last[27];
    
    while(t--)
    {   memset(last,-1,sizeof(last[0])*27);
        scanf("%s",ch);
        long int n=strlen(ch);
        dp[0]=1;
        for(long int i=0;i<n;i++)
        {
            dp[i+1]=(dp[i]<<1);
            if(dp[i+1]>=mod)
                dp[i+1]-=mod;
            if(last[ch[i]-'A']!=-1)
            {
                dp[i+1]=dp[i+1]-dp[last[ch[i]-'A']-1];
                if(dp[i+1]<0)    
                    dp[i+1]+=mod;
            }
            
            last[ch[i]-'A']=i+1;
        }
        cout<<dp[n]<<"\n";
    }
    
return(0);    
}
