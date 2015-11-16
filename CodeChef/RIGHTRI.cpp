#include <iostream>
#include <stdio.h>
using namespace std;
 
int main() {
    long int n;
scanf("%ld",&n);
int x1,x2,x3,y1,y2,y3;
long int count=0;
while(n--)
{
	scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
	int a=(y2-y1)*(y2-y1)+(x2-x1)*(x2-x1);
	int b=(y3-y2)*(y3-y2)+(x3-x2)*(x3-x2);
	int c=(y1-y3)*(y1-y3)+(x1-x3)*(x1-x3);
	if(a==(b+c)||(b==(a+c))||(c==(a+b)))
	    count++;
}
printf("%ld",count);
	return 0;
}
