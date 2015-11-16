#include <stdio.h>
 
long long int gcd(long long int a,long long int b)
{
	while(b)
	b^=a^=b^=a%=b;
 
	return a;
}
 
int main()
{
	int t;
	long long int A,B;
	long long int n1,n2;
	long long int g;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld",&A,&B);
		n1=A;
		n2=B;
		if(n1==n2)
			printf("Yes\n");
		else 
			{	if(n1>n2) 	
				 g=gcd(n1,n2);
				else
				 g=gcd(n2,n1);
				A=A/g;
				B=B/g;
				if(g==1)
				{	
					if(B==1)
						printf("Yes\n");
					else	
						printf("No\n");
				}
				else
				{
					while(g!=1)
					{	if(g>B)
						 g=gcd(g,B);
						else 
						 g=gcd(B,g);
						B=B/g;	
					}
					if(B==1)
						printf("Yes\n");
					else
						printf("No\n");
				}
		
			}
	}
 
	return(0);
}
