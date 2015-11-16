#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
 
int main() {
	int t;
	scanf("%d",&t);
	long int n;
	long long int a[100003];
	while(t--)
	{
	    scanf("%ld",&n);
	
	for(long int i=0;i<n;i++)
	{
	    scanf("%lld",&a[i]);
	    
	}
	sort(a,a+n);
	long long int count=0;
	for(long int i=n-1;i>=0;i=i-2)
	{
	    count=count+a[i];
	}
	
	printf("%lld\n",count);
	}
	return 0;
}
