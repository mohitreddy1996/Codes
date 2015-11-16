#include <iostream>
#include <stdio.h>
using namespace std;
 
int main() {
	long int n;
	scanf("%ld",&n);
	long long int a[300002];
	for(long int i=0;i<n;i++)
	{
	    scanf("%lld",&a[i]);
	}
	long long int max=a[0]&a[1];
	for(long int i=0;i<n;i++)
	{
	    for(long int j=i+1;j<n;j++)
	    {
	        if(max<(a[i]&a[j]))
	        {
	            max=(a[i]&a[j]);
	        }
	    }
	}
	printf("%lld",max);
	return 0;
}
