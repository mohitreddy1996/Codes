#include <stdio.h>
#include <math.h>
int isprime(long int n)
{  int flag=0;
    for(long int i=2;i<=sqrt(n);i=i+1)
    {
        if(n%i==0)
        {flag=1;
        return(0);
        }
    }
    if(!flag)
    {return(1);}
    return(0);
}
int ispalindrome(long int n)
{ long int temp=n;
 
long int rev=0;
 
    
    while(temp)
    {
        rev=rev*10+temp%10;
        temp=temp/10;
    }
    if(rev==n)
    return(1);
    else
    return(0);
}
int main(void) {
	long int n;
	scanf("%ld",&n);
	for(long int i=n;;i=i+1)
	{  int check=ispalindrome(i)&&isprime(i);
	  if(check)
	  {printf("%ld\n",i);
	  return(0);
	  }  
	}   
	return 0;
}
