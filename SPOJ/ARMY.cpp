#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    long int n,m;
    
     long int a[1000005],b[1000005];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%ld %ld",&n,&m);
        if(n==0&&m==0)
        {
            printf("uncertain\n");
        }
        else
        {
            if(n==0)
                printf("MechaGodzilla\n");
            else if(m==0)
                printf("Godzilla\n");
            else
            {
            long long int max1=0;
            for(long int i=0;i<n;i++)
            {
                scanf("%ld",&a[i]);
                if(a[i]>max1)
                {
                    max1=a[i];
                }
            }
            long long int max2=0;
            for(long int i=0;i<m;i++)
            {
                scanf("%ld",&b[i]);
                if(b[i]>max2)
                max2=b[i];
            }
            if(max1==max2)
            {
                if(count(a,a+n,max1)>=count(b,b+m,max2))
                {
                 printf("Godzilla\n");
                } 
                else
                {
                    printf("MechaGodzilla\n");
                }
            }
            else
            {
                if(max1>max2?1:0)
                  printf("Godzilla\n");
                else
                    printf("MechaGodzilla\n");
            }
            }
        }
        
    }
    
return(0);    
}
