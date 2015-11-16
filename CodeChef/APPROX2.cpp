#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
 
int main() {
	int t;
	int n;
	long long int k;
	scanf("%d",&t);
	long long int a[1001];
	while(t--)
	{
	    scanf("%d %d",&n,&k);
	    for(int i=0;i<n;i++)
	    {
	        scanf("%lld",&a[i]);
	    }
	    long long int min=abs(a[1]+a[0]-k);
	    long int count=0;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=i+1;j<n;j++)
	        {
	            if(min>abs(a[i]+a[j]-k))
	            {
	                min=abs(a[i]+a[j]-k);
	                count=1;
	            }
	            else if(min==abs(a[i]+a[j]-k))
	            {
	                count++;
	            }
	        }
	    }
	    printf("%lld %ld\n",min,count);
	}
	return 0;
}
