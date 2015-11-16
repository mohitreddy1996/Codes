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
 
 
long int gcd(long int a,long int b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}
*/
 
int main()
{
    int t;
    int n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int x,l,f;
        long int tottime=0;
        int count=0;
        while(n--)
        {   count++;
            scanf("%d %d %d",&x,&l,&f);
            if(count==1)
                tottime=x+l;
            else
            {
            if(tottime<=x)
            {
                tottime=x;
                tottime+=l;
            }
            else
            {
               int rem=(tottime-x)%f;
               if(rem==0)
                rem=f;
               tottime+=(f+l-rem); 
            }
            }
          
        }
        printf("%ld\n",tottime);
    }    
    
return(0);    
}
