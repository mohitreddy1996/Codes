#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
 
int main() {
	
	int t,p,s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&p,&s);
		float b= (p/2-sqrt(p*p/4-6*s))/6;
	    float h= p/4-2*b;
		float v= b*b*h;
		
		printf("%0.2f\n",v);
		
	}
	
	return 0;
} 
