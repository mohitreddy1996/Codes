#include <algorithm>
#include <stdio.h>
#include <map>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

long int solve(long int n,long int count)
{
    if(n==1)
        return (count+1);
    else
    {
        
        
        {
            if(n%2)
                return solve(3*n + 1,count+1);
            else
                return solve(n/2,count+1);
        }
    }
}


int main()
{
    long int i,j;
    
   
    while(scanf("%ld %ld",&i,&j)!=EOF)
    {    long int max1=0;
    long int q=j,w=i;
        if(i>j)
            {
                q=i;
                w=j;
            }
        for(long int k=w;k<=q;k++)
        {    
            max1=max(max1,solve(k,0));
    }
        printf("%ld %ld %ld\n",i,j,max1);   
    }
    
    
return(0);    
}