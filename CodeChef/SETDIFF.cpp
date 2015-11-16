#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
long long int mod_fun(int base,long int exponent,long long int mod)
{
 	long long int res=1;
	//base=base%mod;
	while(exponent>0)
	{
	 if(exponent%2==1)
		res=((res%mod)*(base%mod))%mod;
	exponent=exponent>>1;
	base=((base%mod)*(base%mod))%mod;
	}
	return res;
 
		
}
 
int main()
{
	int t;
	scanf("%d",&t);
	long long int a[100007];
	long int n;
	long long int sum=0;
	long long int mod=1000000007;
	while(t--)
	{
		sum=0;
		scanf("%ld",&n);
		
		
		for(long int i=0;i<n;i++)
		{	
			scanf("%lld",&a[i]);
		}
		std::sort(a,a+n);
		for(long int i=0;i<n;i++)
		{
			sum=sum+((((mod_fun(2,i,mod))%mod-(mod_fun(2,n-i-1,mod))%mod+mod)%mod)*a[i]%mod)%mod;
			sum=sum%mod;
		}
		printf("%lld\n",sum);
	}
 
return(0);
}
