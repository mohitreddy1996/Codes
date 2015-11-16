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
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long int n;
        scanf("%ld",&n);
        long int a[n+1];
        for(long int i=0;i<n;i++)
            scanf("%ld",&a[i]);
        long int max1=0;
        long int top;
        long int count=0;
        for(long int i=0;i<n;i++)
        {
            if(i==0)
                {
                    top=a[i];count++;
                }    
            else
            {
                top=gcd(top,a[i]),count++;
            }   
            if(top==1)
                max1=max(max1,count);
        }
        if(max1==0)
            printf("-1\n");
        else
            printf("%ld\n",max1);
    }
 
return(0);    
}
