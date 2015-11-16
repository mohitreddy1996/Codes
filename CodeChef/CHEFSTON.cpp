#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
 
int main() {
	int t;
	long int n;
	long long int k,a[100003],b[100003];
	scanf("%d",&t);
	long long int max,temp;
	while(t--)
	{
	    scanf("%ld %lld",&n,&k);
	    for(long int i=0;i<n;i++)
	    {
	        scanf("%lld",&temp);
	        a[i]=k/temp;
	    }
	    for(long int i=0;i<n;i++)
	    {
	        scanf("%lld",&temp);
	        b[i]=temp*a[i];
	    }
	    sort(b,b+n);
	    printf("%lld\n",b[n-1]);
	}
	return 0;
}
