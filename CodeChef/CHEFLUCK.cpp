#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int t;
    long long int n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        long int j=n/7;
        int mark=1;
        for(j;j>=0;j--)
        {
            if(((n-(7*j))%4)==0)
            {
                printf("%ld\n",7*j);
                mark=0;
                break;
            }
        }
        if(mark)
        {
            printf("-1\n");
        }
    }
return(0);    
}
