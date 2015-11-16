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
    scanf("%d",&t);
    int mark=0;
    while(t--)
    {   mark++;
        long int n;
        int m;
        
        scanf("%ld %d",&n,&m);
        long int a[m+1];
        for(int i=0;i<m;i++)
            scanf("%ld",&a[i]);
        sort(a,a+m);
        long int sum=0;
        int count=0;
        for(int i=m-1;i>=0;i--)
        {
            sum=sum+a[i];
            count++;
            if(sum>=n)
            {
                break;
            }
        }
        if(sum<n)
            printf("Scenario #%d:\nimpossible\n",mark);
        else
            printf("Scenario #%d:\n%d\n",mark,count);
    }
return(0);    
}
