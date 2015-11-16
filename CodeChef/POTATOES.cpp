#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int isprime(int n)
{
    if(n==2)
    {
        return 1;
    }
    else if(n==3)
    {
        return 1;
    }
    else
    {
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                return 0;
            }
        }
    }
    return 1;
}
 
int main() {
    int t;
    scanf("%d",&t);
    int x,y;
    while(t--)
    {
        scanf("%d %d",&x,&y);
        int n=x+y+1;
        while(isprime(n)!=1)
        {
            n++;
        }
        printf("%d\n",n-(x+y));
    }
	
	return 0;
}
