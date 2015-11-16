#include <stdio.h>
#include <string.h>
int main(void) {
	long int t;
	int n,x;
	scanf("%ld",&t);
	char str[101];
	for(long int i=0;i<t;i++)
	{
	    scanf("%s",str);
	    //int len=strlen(str);
	    x=0;
	    int count=0;
	    scanf("%d",&n);
	   while(x<=12*n)
	   {
	    for(int j=0;str[j]!='\0';j++)
	    {
	        if(str[j]=='T')
	        x=x+2;
	        else
	        x=x+1;
	    }
	    if(x<=12*n)
	    count=count+(12*n-x);
	   } 
	    printf("%d\n",count);
	}
	return 0;
}
