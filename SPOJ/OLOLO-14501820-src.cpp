#include <algorithm>
#include <stdio.h>
#include <map>
#include <string>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
#define mod 1000000007
int main()
{
    long int n;
    long long int x;
    long long int res;
    scanf("%ld",&n);
   
    for(long int i=0;i<n;i++) 
    {
    	scanf("%lld",&x);
        if(i==0)
        	{res=x;}
        else
        	res=res^x;
    }
    
    printf("%lld",res);
   
return(0);    
}
 