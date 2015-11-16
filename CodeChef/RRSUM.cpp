#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    long long int n,m;
    scanf("%lld %lld",&n,&m);
    long long int temp;
    while(m--)
    {
        scanf("%lld",&temp);
        if(temp>(3*n)|| temp<=n)
        {
            printf("0\n");
            
        }
        else
        {
            printf("%lld\n",(n-abs((2*n)+1-temp)));
        }    
    }
    
    
return(0);    
}
