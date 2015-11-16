#include <algorithm>
#include <stdio.h>
#include <map>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    float dp[400];
    dp[0]=0.0;
    for(int i=1;i<400;i++)
    {
        dp[i]=dp[i-1]+(1.0/(i+1));
    }
    
    float n;
    while(1)
    {
        scanf("%f",&n);
        if(n == 0.00)
        {
            break;
        }
        else
        {
            int m;
            for(int i=1;i<=400;i++)
                {
                    if(dp[i]>=n)
                        {m=i;break;}
                }
                printf("%d card(s)\n",m);
        }
        
    }

return(0);    
}