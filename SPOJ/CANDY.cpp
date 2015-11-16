#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

int main()
{   int n;
    long int a[10003];
    while(1)
    {   long long int sum=0;
        long count1=0;
        scanf("%d",&n);
        if(n!=-1)
        {
            for(int i=0;i<n;i++)
            {
                scanf("%ld",&a[i]);
                sum=sum+a[i];
            }
            sort(a,a+n);
            if(sum%n==0)
            {   sum=sum/n;
                for(int i=0;i<n;i++)
                {
                    if(a[i]<sum)
                    {
                        count1=count1+(sum-a[i]);
                    }
                    else
                    {
                        break;
                    }
                }
                printf("%ld\n",count1);
            }
            else
            {
                printf("-1\n");
            }
        }
        else
        {
            break;
        }
    }
return(0);    
}
