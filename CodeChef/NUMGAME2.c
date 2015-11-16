#include <stdio.h>
 
int main(void) {
	long int t;
scanf("%ld",&t);
while(t--)
{
	long long int n;
	scanf("%lld",&n);
	int max=n%4;
	if(max==1)
		printf("ALICE\n");
	else
		printf("BOB\n");
}
 
return(0);
	return 0;
}
