#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long int n,m,a;
    long long int res=1;
    cin>>n>>m>>a;
    if(n%a==0)
        res=res*(n/a);
    else
        res=res*((n/a)+1);
    
    if(m%a==0)
        res=res*(m/a);
    else
        res=res*((m/a)+1);
        
    cout<<res;
return(0);    
}