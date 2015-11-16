#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
 
int main() {
	int t;
	long int n;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%ld",&n);
	    long int min;
	    long int temp=sqrt(n);
	    while(temp>0)
	    {
	        if(n%temp==0)
	        {
	            min=abs(temp-n/temp);
	            break;
	        }
	        temp--;
	    }
	    printf("%ld\n",min);
	}
	return 0;
}
