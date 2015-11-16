#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int s,n;
    scanf("%d %d",&s,&n);
    int wt[n+2],val[n+2];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&wt[i],&val[i]);
    }
    long int L[n+2][s+2];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            if(i==0||j==0)
                L[i][j]=0;
            else if(wt[i-1]<=j)
            {
                L[i][j]=max(L[i-1][j],val[i-1]+L[i-1][j-wt[i-1]]);
            }
            else
                L[i][j]=L[i-1][j];
        }
    }
    printf("%ld",L[n][s]);
return(0);    
}