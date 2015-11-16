#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
 
int main() {
	int t;
	scanf("%d",&t);
	long long int countt,counts;
	long long int n,k;
	while(t--)
	{
	    
	    cin>>n>>k;
	    
	    if(k==0)
	    {
	        countt=n;
	        counts=0;
	        printf("%lld %lld\n",counts,countt);
	    }
	    else
	    {
	        counts=n/k;
	        countt=n%k;
	        printf("%lld %lld\n",counts,countt);
	    }
	    
	}
	    
	
	return 0;
}
