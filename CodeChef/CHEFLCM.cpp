#include <stdio.h>
#include <math.h>
long int isprime(long long int n)
{  
    if(n==2)
    return 1;
    if(n==3)
    return 1;
    for(long int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        return 0;
    }
    return 1;
}
 
 
int main(void) {
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
	    long long int n,sum;
	    scanf("%lld",&n);
	    if(n==1)
	    sum=1;
        else if(isprime(n))
        sum=n+1;
        else
        {   sum=0;
            
            for(long int j=1;j<=sqrt(n);j++)
            {
                if(n%j==0)
                {
                    sum=sum+j+(n/j);
                    
                    
                }
            }
            long int temp=sqrt(n);
            if(temp*temp==n)
            sum=sum-sqrt(n);
        }
	    printf("%lld\n",sum);
	    
	}
	return 0;
}
