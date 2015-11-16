#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    char ch[5003];
    scanf("%s",ch);
    char temp[5003];
    for(int i=0;i<n;i++)
    {
        temp[n-1-i]=ch[i];
    }
    
    int dp[2][5003]; 
    for(int i=n; i>=0; i--)
    {
       int ii = i&1;
        for(int j=n; j>=0; j--)
        {
            if(i==n || j==n) { dp[ii][j]=0; continue; }
            if(ch[i]==temp[j])
                dp[ii][j] = 1+dp[1-ii][j+1];
            else
                dp[ii][j] = max(dp[ii][j+1], dp[1-ii][j]);
        }
    }   
    cout<<n-dp[0][0];
    
    
    
return(0);    
}