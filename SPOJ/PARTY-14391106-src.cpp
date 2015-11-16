#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int b,c;
    
    while(1)
    {
        scanf("%d %d",&b,&c);
        int val[c+2],bud[c+2];
        if(b==0&&c==0)
            break;
        for(int i=0;i<c;i++)
        {
            scanf("%d %d",&bud[i],&val[i]);
        }
        int l[c+2][b+2];
        int min_bud;
        int max1=0;
        for(int i=0;i<=c;i++)
        {   
            
            for(int j=0;j<=b;j++)
            {   
                if(i==0||j==0)
                    l[i][j]=0;
                else
                {
                    if(j>=bud[i-1])
                    {
                        if((val[i-1]+l[i-1][j-bud[i-1]])>l[i-1][j])
                        {   
                            l[i][j]=(val[i-1]+l[i-1][j-bud[i-1]]);
                        }
                        else
                        l[i][j]=l[i-1][j];
                    }
                    else
                    {
                        l[i][j]=l[i-1][j];
                    }
                }    
             
            }
            
        }
        min_bud=l[c][b];
        int i;
        for(i=b;i>=0;i--)
        {
            if(l[c][i]<min_bud)
            {
                break;
            }
        }
        
        printf("%d %d\n",i+1,l[c][b]);
        
    }    
return(0);    
}