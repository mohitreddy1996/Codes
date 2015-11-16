#include <iostream>
#include <stdio.h>
using namespace std;
 
int main() {
	int t;
	long int n;
	int temp;
	
	scanf("%d",&t);
	while(t--)
	{   int count=0;
	long long int sum=0;
	    scanf("%ld",&n);
	    while(n--)
	    {
	        scanf("%d",&temp);
	        if(temp!=0)
	            count++;
	       sum=sum+temp;
	    }
	    if(sum>=100&&sum<100+count)
	    {
	        printf("YES\n");
	    }
	    else
	    {
	        printf("NO\n");
	    }
	}
	return 0;
}
