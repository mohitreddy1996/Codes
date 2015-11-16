#include <stdio.h>
 
int main(void) {
	long int t;
	long int x,n,y,k;
	scanf("%ld",&t);
	long int p,c;
	for(int i=0;i<t;i++)
	{
	    scanf("%ld %ld %ld %ld",&x,&y,&k,&n);
	    long int pages=x-y;
	    //long int a[n];
	    int flag=0;
	    for(long int i=0;i<n;i++)
	    {
	        scanf("%ld %ld",&p,&c);
	        if(c<=k&&p>=pages)
	          flag=1;
	    }
	    if(flag==1)
	    printf("LuckyChef\n");
	    else
	    printf("UnluckyChef\n");
	}
	return 0;
}
