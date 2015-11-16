#include <stdio.h>
#include <stdlib.h>
int main(void) {
	long int a,b;
	scanf("%ld %ld",&a,&b);
	long int diff;
	diff=abs(a-b);
	int res=diff%10;
	if(res!=9)
	diff++;
	else
	diff--;
	printf("%ld\n",diff);
	return 0;
}
