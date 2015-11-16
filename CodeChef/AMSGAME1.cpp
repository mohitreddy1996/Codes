#include <iostream>
#include <stdio.h>
using namespace std;
 
long long int gcd(long long int a,long long int b)
{
    while(b)
        b ^= a ^= b ^= a %= b;
    return a;
}
 
 
int main() {
    int t;
scanf("%d",&t);
long long int a[1001];
int n;
while(t--)
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	long long int top=a[0];
	for(int i=1;i<n;i++)
	{
		top=gcd(top,a[i]);
	}
	printf("%lld\n",top);
}
	return 0;
}
