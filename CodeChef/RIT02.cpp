#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
 
 
int main()
{
    int n;
    long long int a[1003];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    int count1;
    long long int top;
    long long int sum=0;
    for(int i=0;i<n;)
    {
        count1=count(a+i,a+n,a[i]);
        top=a[i];
        
        printf("%d\n",(n-i));
        for(int j=i;j<n;j++)
        {
            a[j]=a[j]-top;
        }
        i=i+count1;
    }
        
    
return(0);    
}
