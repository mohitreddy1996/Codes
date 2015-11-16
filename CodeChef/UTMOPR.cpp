#include <algorithm>
#include <stdio.h>
#include <map>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t;
    long int k;
    int n;
    long long int a[1002];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %ld",&n,&k);
        long long int sum=0;
        for(int i=0;i<n;i++)
        {    scanf("%ld",&a[i]);
            sum=sum+a[i];
        }
        if(sum%2==0)
        {
            if(k==1)
                printf("odd\n");
            else
                printf("even\n");
        }
        else
        {
            printf("even\n");
        }
    }
 
return(0);    
}
