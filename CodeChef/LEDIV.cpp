#include <algorithm>
#include <stdio.h>
#include <map>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
#define mod 1000000007
/*
int solve()
{
      ....
      Base Cases
      ....
      if ( DP[i][j] is calculated) // Already calculated so just reuse
               return DP[i][j];
      else // Calculate DP[i][j] and return it
           put recurrence algo
           DP[i][j] = ans of recurrence algo 
           return DP[i][j]
}
 
unsigned nChoosek( unsigned n, unsigned k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;
 
    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}
 
*/
long int gcd(long int a,long int b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}
 
 
int main()
{
   long int t;
    scanf("%ld",&t);
    while(t--)
    {
        long int n;
        scanf("%ld",&n);
        long int a[n+1];
        int flag=1;
        for(long int i=0;i<n;i++)
            {
                scanf("%ld",&a[i]);
                
            }       
            
       
        sort(a,a+n);
        long top=a[0];
        for(long int i=0;i<n;i++)
        {
            top=gcd(top,a[i]);
        }
        int i;
        int m=-1;
         for(i=2;i<=floor(sqrt(top));i++)
		{
			if(top%i==0)
			{
				m=i;
				break;
			}
		}
 
       if((i==floor(sqrt(top))+1)&&top>1)
			printf("%d\n",top);
		else
			printf("%d\n",m);
       
    }
 
return(0);    
}
