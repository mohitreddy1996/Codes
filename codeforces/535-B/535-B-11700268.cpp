#include <algorithm>
#include <stdio.h>
#include <map>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long int n;
    long long len=0;
    long long ans=0;
    scanf("%lld",&n);
    while(n)
    {
        if(n%10 == 7)
            ans+=(1<<len);
        len++;
        n=n/10;
    }
    for(int i=0;i<len;i++)
    {
        ans+=(1<<i);
    }
    cout<<ans;

return(0);    
}