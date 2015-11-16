#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int dp[20005][500];
 
 
int main()
{
    
    int len;
    char ch[20005];
    scanf("%s",ch);
    len=strlen(ch);
 
    int q;
    int l,m;
    scanf("%d",&q);
    while(q--)
    {   
        
        
        scanf("%d %d",&m,&l);
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<m;j++)
            {   
                dp[i][j]=0;
            }
        }
        for(int i=0;i<len;i++)
        {
            dp[i][(ch[i]-'0')%m]=1;
        }
        for(int i=1;i<len;i++)
        {
            for(int j=0;j<m;j++)
            {   
                 dp[i][((j*10)+(ch[i]-'0'))%m]+=dp[i-1][j];
            }
        }
        long int count1=0;
        for(int i=0;i<len;i++)
        {
            count1+=dp[i][l];
        }
        printf("%ld\n",count1);
        
    }
    
    
return(0);    
}
