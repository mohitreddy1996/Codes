#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    
    
    
    while(t--)
    {
        int a[2005];
        int m=0;
        int temp=1;
        int i=0;
        while(temp)
        {
            scanf("%d",&temp);
            if(temp!=0)
            a[i++]=temp;
        }
        
        while(1)
        {   
            int b[2005];
            scanf("%d",&temp);
            if(temp==0)
                break;
            b[0]=temp;
            temp=1;
            int j=1;
            while(temp)
            {
                scanf("%d",&temp);
                if(temp!=0)
                b[j++]=temp;
            }
            
            
            int L[i+2][j+2];
            
            for(int q=0;q<=i;q++)
            {
                for(int w=0;w<=j;w++)
                {
                    if(q==0||w==0)  
                    {
                       L[q][w]=0;  
                    }
                    else if(a[q-1]==b[w-1])
                    {
                        L[q][w]=1+L[q-1][w-1];  
                    }
                    else
                    {
                        L[q][w]=max(L[q-1][w],L[q][w-1]);
                    }
                }
            }
            m=max(L[i][j],m);
            
        }
        printf("%d\n",m);
    }
    
return(0);    
}
