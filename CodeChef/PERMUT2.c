#include <stdio.h>
#include<stdlib.h>
int main(void) {
	long int n;
	long int a[1000002],b[1000002];
	while(2)
	{
	    scanf("%ld",&n);
	    
	    int flag=1;
	    if(n==0)
	    {exit(0);}
	    else
	    {
	    for(long int i=1;i<=n;i++)
	    {
	        scanf("%ld",&a[i]);
	        b[a[i]]=i;
	    }
	    for(long int i=1;i<=n;i++)
	     {
	         if(a[i]!=b[i])
	          {
	              printf("not ambiguous\n");
	              flag=0;
	              break;
	          }
	     }
	     if(flag!=0)
	     printf("ambiguous\n");
	    }
	}
	return 0;
}
