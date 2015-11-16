#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int main()
{
    char ch[5005];
    long long int dp[5005];
    while(1)
    {
        scanf("%s",ch);
        if(ch[0]=='0')
        {
            break;
        }
        
        memset(dp,0,5005);
        dp[0]=1;
        int len=strlen(ch);
        for(int i=1;i<len;i++)
        {
            if(ch[i]-'0')
            {
                dp[i]=dp[i-1];
            }
            if((10*(ch[i-1]-'0')+(ch[i]-'0'))<=26&&(10*(ch[i-1]-'0')+(ch[i]-'0'))>=10)
            {
                   dp[i]=dp[i]+dp[(i-2)>=0?i-2:0];
            }    
        }
        printf("%ld\n",dp[len-1]);
        
    }    
    
    
    
return(0);    
}
