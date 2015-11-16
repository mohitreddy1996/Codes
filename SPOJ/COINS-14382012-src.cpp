#include <algorithm>
#include <stdio.h>
#include <map>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
map<long long,long long> a;
long long int q=-1;
long long int dp(long long n)
{   
    if(a[n]!=0)
        return a[n];
    else
        return a[n]=max(n,(dp(n/2)+dp(n/3)+dp(n/4)));
        return a[n];   
}
int main()
{   
    long long int n;
    for(int i=0;i<=11;i++)
    {
        a[i]=i;
    }
    while(cin>>n)
    {
        
        if(n==0)
            printf("0\n");
        else
            printf("%lld\n",max(n,dp(n)));
          
    }    
    
return(0);    
}