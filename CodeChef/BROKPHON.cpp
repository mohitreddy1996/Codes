#include <stdio.h>
 
int main(void) {
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
	    long int n;
	    scanf("%ld",&n);
	    long int a[n+1];
	    for(long int j=0;j<n;j++)
	    {
	        scanf("%ld",&a[j]);
	    }
	    long int count=0;
	    if(n==2)
	     {
	         if(a[0]!=a[1])
	         count=2;
	     }
	     else
	     {
	    for(long int j=1;j<n-1;j++)
	    {
	        if((a[j]!=a[j-1])||(a[j]!=a[j+1]))
	        count++;
	    }
	    if(a[0]!=a[1])
	    count++;
	    if(a[n-1]!=a[n-2])
	    count++;
	     }
	    printf("%ld\n",count);
	    
	}
	return 0;
}
