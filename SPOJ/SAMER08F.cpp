#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	
	while(1)
	{	int n;
		long long int sum=0;
		scanf("%d",&n);
		if(n!=0)
		{
		while(n)
		{
			sum=sum+(n*n);
			n--;
		}
		printf("%lld\n",sum);
	    }
	    else
	    {
	    	break;
	    }
	}    

	return 0;
}
