#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


int euler(int n)
{
    int res=n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n=n/i;
            }
            res=res-(res/i);
        }
    }
    if(n>1)
        res=res-(res/n);
    return res;
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",euler(n));

    }

    return 0;
}
