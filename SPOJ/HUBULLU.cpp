#include <algorithm>
#include <stdio.h>
#include <map>
#include <math.h>
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
        int mark;
        scanf("%lld %d",&n,&mark);
        if(mark==0)
            printf("Airborne wins.\n");
        else
            printf("Pagfloyd wins.\n");
    }

return(0);    
}
