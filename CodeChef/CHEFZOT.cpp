#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    long int n;
    int temp;
    scanf("%ld",&n);
    long int m=n;
    long int sub=0,sup=0;
    long int max1=0;
    long int count=0;
    while(n--)
    {
        scanf("%d",&temp);
        if(temp!=0)
        {sup++;
        }
        else
        {
            if(max1<(sup-sub))
            {
                max1=sup-sub;
            }
            count++;
            sup=0;
            sub=0;
        }
        
        
        
    }
    if(count==0)
    printf("%ld",m);
    else
    {
        printf("%ld",max1);
    }
    
return(0);    
}
