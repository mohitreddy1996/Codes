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
    while(n--)
    {
        int k,m;
        scanf("%d %d",&k,&m);
        int wt[m+2],val[m+2];
        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&wt[i],&val[i]);
        }
        int L[m+2][k+2];
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=k;j++)
            {
                if(i==0||j==0)
                {
                   L[i][j]=0;
                }
                 else if(j>=wt[i-1])
                {
                 L[i][j]=max(L[i-1][j],val[i-1]+L[i-1][j-wt[i-1]]);
                }
                else
                  L[i][j]=L[i-1][j];
                
                
            }
            
        }
        
        printf("Hey stupid robber, you can get %d.\n",L[m][k]);
    }
    
return(0);    
}
