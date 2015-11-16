#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
 
int main() {
	long int n;
	long long int d;
	long long int a[100003];
	scanf("%ld %lld",&n,&d);
	for(long int i=0;i<n;i++)
	{
	    scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	long int count=0;
	for(long int i=0;i<n;i++)
	{
	    if(a[i]!=0)
	    {
	        long long int temp=(upper_bound(a,a+n,a[i]+d)-&a[0]);
	        for(long int j=i+1;j<temp;j++)
	        {
	            if(a[j]!=0)
	            {
	                count++;
	                a[i]=0;
	                a[j]=0;
	                
	                break;
	            }
	        }
	        
	    }
	}
	printf("%ld",count);
	return 0;
}
