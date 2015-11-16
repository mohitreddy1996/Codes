#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    long int t;
    long long int n;
    scanf("%ld",&t);
    while(t--)
    {
        long long int ans;
        ans=0;
        scanf("%lld",&n);
        ans=ans+(n*(n+1))/2;
        ans=ans+n;
        printf("%lld\n",ans);
    }
    return 0;
} 
