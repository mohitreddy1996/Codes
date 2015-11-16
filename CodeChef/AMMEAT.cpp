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
        int n;
        long long m;
        scanf("%d %lld",&n,&m);
        long long int a[n+1];
        long long int sum=0;
        for(int i=0;i<n;i++)
            {
                scanf("%lld",&a[i]);
                sum+=a[i];
            }
            if(sum<m)
                printf("-1\n");
            else
            {   sum=0;
                sort(a,a+n);
                for(int i=n-1;i>=0;i--)
                {
                    sum=sum+a[i];
                    if(sum>=m)
                        {
                            
                            printf("%d\n",(n-i));
                            break;
                        }
                }
            }    
        
    }    
    
return(0);    
}
