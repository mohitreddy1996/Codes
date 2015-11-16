#include <algorithm>
#include <stdio.h>
#include <map>
#include <math.h>
#include <stack>
#include <string.h>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;
#define mod 1000000007
#define MAX 10001
#define inf 1e9
#define inf 1000000000
struct comp
{
    bool operator() (pair<int,int> const &a,pair<int,int> const &b )
    {
        return a.second>b.second;
    }
};

int solve(int a,int b,int c)
{
    int A=a;
    int B=0;
    int moves=1;
    while(A!=c || B!=c)
    {
        int temp=min(A,b-B);
        A-=temp;
        B+=temp;
        moves++;
        if(A==c || B==c)
        {
            break;
        }
        if(A==0)
        {
            A=a;
            moves++;
        }
        if(B==b)
        {
            B=0;
            moves++;
        }
    }
    return moves;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        //cout<<__gcd(4,24)<<" "<<__gcd(24,4)<<"\n";
        if(c>a && c>b)
        {
            printf("-1\n");
        }
        else if(c%__gcd(a,b)!=0)
        {
            printf("-1\n");
        }
        else if(c==a || c==b)
        {
            printf("1\n");
        }
        else
        {
            printf("%d\n",min(solve(a,b,c),solve(b,a,c)));
        }

    }
return(0);
}
