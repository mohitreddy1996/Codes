#include <iostream>
#include <stdio.h>
using namespace std;
 
int main() {
	long long int n,temp;
	scanf("%lld",&n);
	long long int sum=0;
	long long int s=(n*(n+1)/2);
	for(long int i=0;i<n;i++)
	{
	    scanf("%lld",&temp);
	    sum=sum+temp;
	}
	if(s==sum)
	printf("YES");
	else
	printf("NO");
	return 0;
}
