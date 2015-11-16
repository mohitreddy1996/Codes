#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int ans;
    int count1=0;
    if(n%2==1)
    {
        
        ans=(n*n)/2;
        ans=ans+1;
    }
    else
    {
        ans=(n*n)/2;
    }
    int flag=1;
    if(ans>=k)
    {printf("YES\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            
            
            if(k>0&&(i+j)%2==0)
                {
                    k--;
                    printf("L");
                
                }
            else
            {
                printf("S");
            }
        }
        printf("\n");
        
    }
    }
    else
    {
        printf("NO\n");
    }
return(0);    
}