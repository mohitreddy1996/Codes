#include <iostream>
#include <stdio.h>
using namespace std;
 
int main() {
	int t;
	long int n;
	scanf("%d",&t);
	while(t--)
	{   long int count1=0,count0=0;
	    scanf("%ld",&n);
	    int temp;
	    while(n--)
	    {
	        scanf("%d",&temp);
	        if(temp==1)
	            count1++;
	        else
	            count0++;
	    }
	    if(count1%2!=0)
	    {
	        printf("%ld\n",count1);
	    }
	    else
	    {
	        printf("%ld\n",count0);
	    }
	}
	return 0;
}
