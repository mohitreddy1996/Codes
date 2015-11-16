#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
long long int fact(int n)
{
	if(n==0)
		return 1;
	else
		{
			return n*fact(n-1);
		}
}
int main() {
	int t;
scanf("%d",&t);
int a[12];
int n;
long long int tot;
int count1;
 
while(t--)
{
	for(int i=0;i<11;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&n);
	int k=n;
	std::sort(a,a+11);
	for(int i=10;i>=11-n;)
	{   
		count1=count(a,a+11,a[i]);
		
		if(k==count1)
		{
		    printf("1\n");
		    break;
		}
		else if(k<count1)
		{   //printf("%d %d\n",k,count1);
		    tot=fact(count1)/((fact(k)*(fact(count1-k))));
			printf("%lld\n",tot);
			break;
		}
		else
		{
		    k=k-count1;
		    i=i-count1;
		}
		
	}    
}
	return 0;
}
