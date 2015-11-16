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
        long int n;
        scanf("%ld",&n);
        long int w[n+1];
        for(long int i=0;i<n;i++)
            scanf("%ld",&w[i]);
        long int max1;    
        for(long int i=n-1;i>=0;i--)
        {
            if(i==n-1)
                max1=w[i];
            else
                max1=max(w[i],max1+1);
        }
        printf("%ld\n",max1);
        
    }    
    
return(0);    
