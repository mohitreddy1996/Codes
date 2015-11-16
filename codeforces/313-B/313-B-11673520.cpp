#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;
char ch[100005];
int check(int i,int j)
{
    char top;
    for(int k=i;k<j;k++)
    {
        if(k==i)
            top=ch[k];
        if(top!=ch[k])
           return 0;
            
    }
    return 1;
}

int main()
{
    
    long int m;
    scanf("%s",ch);
    long int dp[100005];
    long int len=strlen(ch);
    for(int i=1;i<len;i++)
    {
        if(i==1)    dp[i]=(ch[i]==ch[i-1]?1:0);
        else    dp[i]=dp[i-1]+(ch[i]==ch[i-1]?1:0);
        
       
    }
    
    cin>>m;
    long int x,y;
    while(m--)
    {
        cin>>x>>y;
        x--;
        y--;
        cout<<dp[y]-dp[x]<<"\n";
    }
    
return(0);    
}