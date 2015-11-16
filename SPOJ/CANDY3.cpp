#include <algorithm>
#include <stdio.h>
#include <map>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
   long long int t,n;
    cin>>t;
    while(t--)
    {   long long int sum=0;
        cin>>n;long long int a[n+1];
        for(long long int i=0;i<n;i++)
        {
            cin>>a[i];sum+=a[i];sum%=n;
        }
        if(sum%n==0)
            cout<<"YES\n";
        else 
            cout<<"NO\n";
    }

return(0);    
}
