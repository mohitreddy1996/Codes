#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main()
{
 long int n;
 long int t;
 scanf("\n%ld",&t);
 if(t>=0&&t<=100000)
 for(long int i=0;i<t;i++)
  { scanf("\n%ld",&n);
    if(n>=0&&n<=pow(10,9))
    {long int count=0;
    count=((n/5)+(n/25)+(n/125)+(n/625)+(n/3125)+(n/15625)+(n/78125)+(n/390625)+(n/1953125)+(n/9765625)+(n/48828125)+(n/244140625)+(n/1220703125));
    printf("\n%ld",count);
    }
  }
  
  return(0);
  
  }  
